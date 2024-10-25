Setting up custom metrics in Kubernetes involves using the Prometheus Adapter to collect and expose custom metrics from your applications. Here's a step-by-step guide:

## Step 1: Deploy Prometheus and Grafana (if not already done)

Ensure you have Prometheus and Grafana set up in your cluster. If not, you can follow the steps provided earlier to deploy them.

## Step 2: Deploy Prometheus Adapter

1. Create a file named `prometheus-adapter-values.yaml` with the following content:

```yaml
prometheus:
  url: http://prometheus-server
  port: 80

rules:
  default: false
  custom:
  - seriesQuery: 'my_custom_metric{job="my-job"}'
    resources:
      overrides:
        namespace: {resource: "namespace"}
    name:
      as: "my_custom_metric_per_namespace"
    metricsQuery: 'avg_over_time(my_custom_metric{job="my-job"}[1h])'
```

This configuration file specifies how to collect custom metrics (`my_custom_metric`) from a specific job (`my-job`).

2. Install the Prometheus Adapter using Helm:

```bash
helm repo add bitnami https://charts.bitnami.com/bitnami
helm install prometheus-adapter bitnami/prometheus-adapter -f prometheus-adapter-values.yaml
```

## Step 3: Verify the Prometheus Adapter Deployment

Ensure that the Prometheus Adapter is deployed and running:

```bash
kubectl get deployments -n default
```

## Step 4: Configure HPA with Custom Metrics

Assuming you have an application with an HPA configuration, update the HPA definition to use your custom metric. For example, create a file named `hpa.yaml` with:

```yaml
apiVersion: autoscaling/v2beta2
kind: HorizontalPodAutoscaler
metadata:
  name: my-hpa
spec:
  scaleTargetRef:
    apiVersion: apps/v1
    kind: Deployment
    name: my-deployment
  minReplicas: 1
  maxReplicas: 10
  metrics:
  - type: Pods
    pods:
      metric:
        name: my_custom_metric_per_namespace
      target:
        type: AverageValue
        averageValue: 50
```

This HPA configuration is set to scale based on your custom metric (`my_custom_metric_per_namespace`) with a target average value of 50.

Apply the HPA:

```bash
kubectl apply -f hpa.yaml
```

## Step 5: Verify HPA and Scaling

Check if the HPA and deployment are working correctly:

```bash
kubectl get hpa
kubectl get deployments
kubectl get pods
```

The HPA should now use your custom metric for scaling decisions.

## Tips:

- Ensure your application is exporting the custom metric in a format Prometheus can scrape.

- Adjust the queries and configurations in the `prometheus-adapter-values.yaml` file to match your specific metric requirements.

- Use Grafana to visualize your custom metrics alongside built-in metrics.

Always refer to the official documentation for Prometheus Adapter and HPA for best practices and advanced configurations.
