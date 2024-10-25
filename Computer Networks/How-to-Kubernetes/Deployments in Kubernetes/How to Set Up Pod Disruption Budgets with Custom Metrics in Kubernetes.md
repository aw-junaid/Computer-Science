Setting up Pod Disruption Budgets (PDBs) with custom metrics in Kubernetes involves several steps, including setting up custom metrics APIs and HorizontalPodAutoscalers. Here's a step-by-step guide:

## Step 1: Set Up Custom Metrics API

1. **Deploy Custom Metrics API**:

   First, you need to deploy the Custom Metrics API in your cluster. You can use the [Metrics Server](https://github.com/kubernetes-sigs/metrics-server) or a more advanced solution like [Prometheus Adapter](https://github.com/kubernetes-sigs/prometheus-adapter) for custom metrics.

   Follow the respective documentation to install and configure the Custom Metrics API.

## Step 2: Create a HorizontalPodAutoscaler

1. **Define the HPA**:

   Create a HorizontalPodAutoscaler (HPA) definition file, for example, `hpa.yaml`, with the following content:

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
         metricName: custom-metric
         targetAverageValue: 50
   ```

   In this example, we're configuring the HPA to use a custom metric named `custom-metric` with a target average value of `50`.

2. **Apply the HPA**:

   Apply the HPA definition:

   ```bash
   kubectl apply -f hpa.yaml
   ```

## Step 3: Create a Pod Disruption Budget (PDB)

1. **Define the PDB**:

   Create a Pod Disruption Budget (PDB) definition file, for example, `pdb.yaml`, with the following content:

   ```yaml
   apiVersion: policy/v1beta1
   kind: PodDisruptionBudget
   metadata:
     name: my-pdb
   spec:
     selector:
       matchLabels:
         app: my-app
     maxUnavailable: 1
   ```

   In this example, we're allowing a maximum of 1 unavailable pod at a time.

2. **Apply the PDB**:

   Apply the PDB definition:

   ```bash
   kubectl apply -f pdb.yaml
   ```

## Step 4: Create Custom Metrics

1. **Generate Custom Metrics**:

   Generate custom metrics in your application or system that the HPA will use for scaling. The specifics of this step depend on your application and the metrics you want to use.

2. **Ensure Custom Metrics are Available**:

   Verify that the custom metrics are available in your Custom Metrics API. You can use tools like `kubectl get --raw /apis/custom.metrics.k8s.io/v1beta1` to check for the availability of custom metrics.

## Step 5: Monitor Scaling

Observe how your HorizontalPodAutoscaler responds to the custom metric changes and adjusts the number of replicas in your deployment accordingly.

## Notes:

- Ensure that the labels specified in the HPA and PDB definitions match the labels on your pods.

- Always refer to the official Kubernetes documentation for best practices and advanced configurations when working with HPAs and PDBs.

Remember that this is a simplified guide, and actual configurations may vary based on your specific environment and requirements. Always refer to the official documentation for Kubernetes and related tools for best practices and advanced configurations.
