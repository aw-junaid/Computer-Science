Setting up Prometheus monitoring for Kubernetes involves several steps, including deploying Prometheus, configuring service discovery, and creating alerting rules. Here's a step-by-step guide:

## Step 1: Deploy Prometheus

1. Create a file named `prometheus-config.yaml` with the following content:

```yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: prometheus-server-conf
data:
  prometheus.yml: |
    global:
      scrape_interval: 15s

    scrape_configs:
      - job_name: 'kubernetes-apiservers'
        kubernetes_sd_configs:
        - role: endpoints
        scheme: https
        tls_config:
          ca_file: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        bearer_token_file: /var/run/secrets/kubernetes.io/serviceaccount/token

        relabel_configs:
        - source_labels: [__meta_kubernetes_namespace, __meta_kubernetes_service_name, __meta_kubernetes_endpoint_port_name]
          action: keep
          regex: default;kubernetes;https

      - job_name: 'kubernetes-nodes'
        scheme: https
        tls_config:
          ca_file: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        bearer_token_file: /var/run/secrets/kubernetes.io/serviceaccount/token
        kubernetes_sd_configs:
        - role: node

        relabel_configs:
        - action: labelmap
          regex: __meta_kubernetes_node_label_(.+)

        - target_label: __address__
          replacement: kubernetes.default.svc:443
          action: replace

        - source_labels: [__meta_kubernetes_node_name]
          target_label: __metrics_path__
          regex: (.+)
          replacement: /api/v1/nodes/${1}/proxy/metrics

      - job_name: 'kubernetes-pods'
        kubernetes_sd_configs:
        - role: pod

        relabel_configs:
        - source_labels: [__meta_kubernetes_pod_annotation_prometheus_io_scrape]
          action: keep
          regex: true

        - source_labels: [__meta_kubernetes_pod_container_port_name]
          action: replace
          target_label: __metrics_path__
          regex: (.+)
          replacement: /metrics
      - job_name: 'kubernetes-cadvisor'
        scheme: https
        tls_config:
          ca_file: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        bearer_token_file: /var/run/secrets/kubernetes.io/serviceaccount/token
        kubernetes_sd_configs:
        - role: node

        relabel_configs:
        - action: labelmap
          regex: __meta_kubernetes_node_label_(.+)

        - target_label: __address__
          replacement: kubernetes.default.svc:443
          action: replace

        - source_labels: [__meta_kubernetes_node_name]
          target_label: __metrics_path__
          regex: (.+)
          replacement: /api/v1/nodes/${1}/proxy/metrics/cadvisor
```

2. Create a file named `prometheus-deployment.yaml` with the following content:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: prometheus
spec:
  replicas: 1
  selector:
    matchLabels:
      app: prometheus
  template:
    metadata:
      labels:
        app: prometheus
    spec:
      containers:
        - name: prometheus
          image: prom/prometheus:v2.30.0
          args:
            - "--config.file=/etc/prometheus/prometheus.yml"
            - "--storage.tsdb.path=/prometheus"
            - "--web.console.libraries=/etc/prometheus/console_libraries"
            - "--web.console.templates=/etc/prometheus/consoles"
          ports:
            - containerPort: 9090
          volumeMounts:
            - name: config-volume
              mountPath: /etc/prometheus
            - name: prometheus-storage
              mountPath: /prometheus
      volumes:
        - name: config-volume
          configMap:
            name: prometheus-server-conf
        - name: prometheus-storage
          emptyDir: {}
```

3. Create a file named `prometheus-service.yaml` with the following content:

```yaml
apiVersion: v1
kind: Service
metadata:
  name: prometheus
spec:
  selector:
    app: prometheus
  ports:
    - port: 9090
      targetPort: 9090
  type: NodePort
```

4. Apply the configurations:

```bash
kubectl apply -f prometheus-config.yaml
kubectl apply -f prometheus-deployment.yaml
kubectl apply -f prometheus-service.yaml
```

## Step 2: Access Prometheus

You can access Prometheus by using the NodePort specified in the `prometheus-service.yaml` file. Find the NodePort:

```bash
kubectl get svc prometheus
```

Access Prometheus in your web browser using `<Node-IP>:<NodePort>`.

## Step 3: Set Up Alerting Rules (Optional)

Create a file named `prometheus-rules.yaml` with the following content:

```yaml
apiVersion: monitoring.coreos.com/v1
kind: PrometheusRule
metadata:
  labels:
    prometheus: prometheus
  name: alert-rules
spec:
  groups:
  - name: example
    rules:
    - alert: HighErrorRate
      expr: job:request_error_rate:ratio_rate{job="my-app"} > 0.5
      for: 5m
      labels:
        severity: page
      annotations:
        summary: High request error rate
```

Apply the alerting rules:

```bash
kubectl apply -f prometheus-rules.yaml
```

## Step 4: Verify and Monitor

Verify that Prometheus is up and running by visiting `<Node-IP>:<NodePort>`. You can create and view alerting rules in the Prometheus UI.

That's it! You've successfully set up Prometheus monitoring for Kubernetes. Always refer to the official Prometheus documentation for best practices and advanced configurations.
