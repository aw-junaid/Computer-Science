Using State Metrics in Kubernetes involves monitoring the state of various resources. One popular tool for this is Prometheus, which uses the kube-state-metrics service to gather information about your cluster. Here's a step-by-step guide:

## Step 1: Deploy kube-state-metrics

1. Create a file named `kube-state-metrics.yaml` with the following content:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: kube-state-metrics
spec:
  selector:
    matchLabels:
      app: kube-state-metrics
  template:
    metadata:
      labels:
        app: kube-state-metrics
    spec:
      containers:
      - name: kube-state-metrics
        image: quay.io/coreos/kube-state-metrics:v2.2.0
        ports:
        - containerPort: 8080
```

Apply the deployment:

```bash
kubectl apply -f kube-state-metrics.yaml
```

2. Expose the kube-state-metrics service:

```bash
kubectl expose deployment kube-state-metrics --port=8080
```

## Step 2: Deploy Prometheus

You can set up Prometheus to scrape metrics from kube-state-metrics.

1. Create a file named `prometheus.yaml` with the following content:

```yaml
apiVersion: v1
kind: Service
metadata:
  name: prometheus
spec:
  selector:
    app: prometheus
  ports:
    - protocol: TCP
      port: 9090
      targetPort: 9090
---
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
            name: prometheus-config
        - name: prometheus-storage
          emptyDir: {}
```

2. Create a file named `prometheus-config.yaml` with the following content:

```yaml
apiVersion: v1
kind: ConfigMap
metadata:
  name: prometheus-config
data:
  prometheus.yml: |
    global:
      scrape_interval: 15s

    scrape_configs:
      - job_name: 'prometheus'
        static_configs:
          - targets: ['localhost:9090']

      - job_name: 'kube-state-metrics'
        static_configs:
          - targets: ['kube-state-metrics:8080']
```

Apply both the `prometheus.yaml` and `prometheus-config.yaml` files:

```bash
kubectl apply -f prometheus.yaml
kubectl apply -f prometheus-config.yaml
```

## Step 3: Access Prometheus UI

You can access the Prometheus UI by port-forwarding:

```bash
kubectl port-forward svc/prometheus 9090:9090
```

Then open http://localhost:9090 in your browser.

## Step 4: Explore Metrics

In the Prometheus UI, you can explore and query metrics gathered from kube-state-metrics.

## Tips:

- Consider securing your Prometheus deployment, especially if it's exposed to the public internet.
- Customize the `prometheus-config.yaml` file to include additional scraping targets or adjust scraping intervals.

That's it! You've set up kube-state-metrics and Prometheus to monitor your Kubernetes cluster. Remember to consult the official documentation for best practices and advanced configurations.
