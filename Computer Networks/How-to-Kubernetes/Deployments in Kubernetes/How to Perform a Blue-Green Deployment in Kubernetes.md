Performing a Blue-Green Deployment in Kubernetes involves creating two identical sets of pods (blue and green), then switching traffic from the blue set to the green set. Here's a step-by-step guide:

## Step 1: Set Up Kubernetes Deployment

Create a Deployment YAML file (e.g., `my-app-deployment.yaml`) for your application:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: my-app
spec:
  replicas: 3
  selector:
    matchLabels:
      app: my-app
  template:
    metadata:
      labels:
        app: my-app
    spec:
      containers:
      - name: my-app-container
        image: my-image:tag
        ports:
        - containerPort: 80
```

Apply the Deployment:

```bash
kubectl apply -f my-app-deployment.yaml
```

This creates a Deployment named `my-app` with three replicas.

## Step 2: Expose Service

Expose the Deployment as a Service:

```bash
kubectl expose deployment my-app --type=ClusterIP --name=my-app-service
```

## Step 3: Create a Blue Ingress Resource

Create an Ingress YAML file (e.g., `my-app-blue-ingress.yaml`) for the blue version of your application:

```yaml
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: my-app-ingress
spec:
  rules:
  - host: my-app.example.com   # Replace with your domain
    http:
      paths:
      - pathType: Prefix
        path: /
        backend:
          service:
            name: my-app-service
            port:
              number: 80
```

Apply the Ingress resource:

```bash
kubectl apply -f my-app-blue-ingress.yaml
```

## Step 4: Verify Blue Deployment

Verify that the blue version of your application is accessible at `my-app.example.com`.

## Step 5: Create a Green Deployment

Create a new Deployment YAML file (e.g., `my-app-green-deployment.yaml`) for the green version of your application:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: my-app-green
spec:
  replicas: 3
  selector:
    matchLabels:
      app: my-app-green
  template:
    metadata:
      labels:
        app: my-app-green
    spec:
      containers:
      - name: my-app-container
        image: my-new-image:tag   # Use the new image or version
        ports:
        - containerPort: 80
```

Apply the green Deployment:

```bash
kubectl apply -f my-app-green-deployment.yaml
```

## Step 6: Create a Green Ingress Resource

Create an Ingress YAML file (e.g., `my-app-green-ingress.yaml`) for the green version of your application:

```yaml
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: my-app-ingress
spec:
  rules:
  - host: my-app.example.com   # Replace with your domain
    http:
      paths:
      - pathType: Prefix
        path: /
        backend:
          service:
            name: my-app-service
            port:
              number: 80
---
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: my-app-green-ingress
spec:
  rules:
  - host: my-app.example.com   # Replace with your domain
    http:
      paths:
      - pathType: Prefix
        path: /
        backend:
          service:
            name: my-app-green-service
            port:
              number: 80
```

Apply the Ingress resource:

```bash
kubectl apply -f my-app-green-ingress.yaml
```

## Step 7: Verify Green Deployment

Verify that the green version of your application is accessible at `my-app.example.com`.

## Step 8: Switch Traffic

Update the Ingress resource to route traffic to the green version:

```bash
kubectl apply -f my-app-green-ingress.yaml
```

Now, all incoming traffic will be directed to the green version of your application.

## Step 9: Clean Up (Optional)

You can remove the blue Deployment and associated resources once you're confident in the green version:

```bash
kubectl delete deployment my-app
kubectl delete ingress my-app-ingress
```

Remember to replace `my-app` with your actual resource names.

That's it! You've performed a Blue-Green Deployment in Kubernetes. Always refer to the official Kubernetes documentation for best practices and advanced configurations.
