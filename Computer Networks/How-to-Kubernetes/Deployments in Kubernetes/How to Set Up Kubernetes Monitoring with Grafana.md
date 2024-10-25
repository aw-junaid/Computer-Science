Setting up Kubernetes monitoring with Grafana involves deploying Prometheus for data collection and Grafana for visualization. Here's a step-by-step guide:

## Step 1: Deploy Prometheus

1. Create a file named `prometheus.yaml` with the following content:

```yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: prometheus
---
apiVersion: v1
kind: ConfigMap
metadata:
  name: prometheus-server-conf
  labels:
    prometheus: k8s
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
        relabeling_configs:
        - source_labels: [__meta_kubernetes_namespace, __meta_kubernetes_service_name, __meta_kubernetes_endpoint_port_name]
          separator: ;
          regex: (.+);https;https
          replacement: $1
          target_label: __address__
        - action: labelmap
          regex: __meta_kubernetes_service_label_(.+)
        - source_labels: [__meta_kubernetes_namespace]
          separator: ;
          regex: (.*)
          target_label: kubernetes_namespace
        - source_labels: [__meta_kubernetes_service_name]
          separator: ;
          regex: (.*)
          target_label: kubernetes_name
      - job_name: 'kubernetes-nodes'
        scheme: https
        tls_config:
          ca_file: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        bearer_token_file: /var/run/secrets/kubernetes.io/serviceaccount/token
        kubernetes_sd_configs:
        - role: node
        relabeling_configs:
        - action: labelmap
          regex: __meta_kubernetes_node_label_(.+)
        - target_label: __address__
          replacement: kubernetes.default.svc:443
        - source_labels: [__address__]
          regex: (.*)
          target_label: __param_target
        - target_label: __param_target
          replacement: /metrics
        - action: labelmap
          regex: __param_target
        - source_labels: [__address__]
          regex: (.*)
          target_label: instance
        - action: labelmap
          regex: __address__(.+)__meta_kubernetes_node_label_(.+)__
        - source_labels: [__meta_kubernetes_node_name]
          regex: (.+)
          target_label: node
      - job_name: 'kubernetes-cadvisor'
        scheme: https
        tls_config:
          ca_file: /var/run/secrets/kubernetes.io/serviceaccount/ca.crt
        bearer_token_file: /var/run/secrets/kubernetes.io/serviceaccount/token
        kubernetes_sd_configs:
        - role: node
        relabeling_configs:
        - action: labelmap
          regex: __meta_kubernetes_node_label_(.+)
        - target_label: __address__
          replacement: kubernetes.default.svc:443
        - source_labels: [__address__]
          regex: (.*)
          target_label: __param_target
        - target_label: __param_target
          replacement: /metrics/cadvisor
        - action: labelmap
          regex: __param_target
        - source_labels: [__address__]
          regex: (.*)
          target_label: instance
        - action: labelmap
          regex: __address__(.+)__meta_kubernetes_node_label_(.+)__
        - source_labels: [__meta_kubernetes_node_name]
          regex: (.+)
          target_label: node
---
apiVersion: apps/v1
kind: Deployment
metadata:
  name: prometheus-deployment
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
      serviceAccountName: prometheus
      containers:
        - name: prometheus
          image: prom/prometheus:v2.30.3
          args:
            - "--config.file=/etc/prometheus/prometheus.yml"
            - "--storage.tsdb.path=/prometheus"
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
---
apiVersion: v1
kind: Service
metadata:
  name: prometheus-service
spec:
  selector:
    app: prometheus
  ports:
    - protocol: TCP
      port: 80
      targetPort: 9090
```

2. Apply the Prometheus deployment:

```bash
kubectl apply -f prometheus.yaml
```

## Step 2: Deploy Grafana

1. Create a file named `grafana.yaml` with the following content:

```yaml
apiVersion: v1
kind: Service
metadata:
  name: grafana
spec:
  selector:
    app: grafana
  ports:
    - protocol: TCP
      port: 3000
      targetPort: 3000
---
apiVersion: apps/v1
kind: Deployment
metadata:
  name: grafana
spec:
  replicas: 1
  selector:
    matchLabels:
      app: grafana
  template:
    metadata:
      labels:
        app: grafana
    spec:
      containers:
        - name: grafana
          image: grafana/grafana:latest
          ports:
            - containerPort: 3000
```

2. Apply the Grafana deployment:

```bash
kubectl apply -f grafana.yaml
```

## Step 3: Access Grafana

1. Port-forward the Grafana service:

```bash
kubectl port-forward svc/grafana 3000:3000
```

2. Open your browser and go to [http://localhost:3000](http://localhost:3000). Log in with the default credentials (admin/admin).

3. Configure a data source:
   - Click on the gear icon on the left sidebar to open the configuration menu.
   - Select "Data Sources" and click on "Add your first data source."
   - Choose "Prometheus" from the list and configure the HTTP settings (use `http://prometheus-service:80` as the URL).

4. Create dashboards and panels to visualize your Kubernetes metrics.

## Step 4: Set Up Prometheus as a Data Source (Optional)

If you

 want to use Prometheus as a data source for Grafana, follow these steps:

1. In the Grafana dashboard, go to the gear icon, select "Data Sources," and click "Add your first data source."

2. Choose "Prometheus" from the list.

3. In the HTTP section, set the URL to your Prometheus service (e.g., `http://prometheus-service:80`).

4. Click "Save & Test" to verify the connection.

## Tips:

- Ensure you have the necessary permissions to create deployments, services, and config maps in your cluster.

- Customize the configurations (e.g., scrape intervals) in the `prometheus.yaml` file to fit your specific needs.

- Secure your Grafana instance by changing the default credentials and consider enabling HTTPS.

- Explore available dashboards and panels in Grafana's dashboard library for Kubernetes.

Always refer to the official documentation for Grafana and Prometheus for best practices and advanced configurations.
