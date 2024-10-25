# Deploying a Stateless Application on Kubernetes

In this guide, we'll walk through the steps to deploy a simple stateless application on Kubernetes. We'll use a basic Nginx web server as an example.

## Step 1: Create a Deployment YAML File

Create a file named `nginx-deployment.yaml` with the following content:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: nginx-deployment
spec:
  replicas: 3
  selector:
    matchLabels:
      app: nginx
  template:
    metadata:
      labels:
        app: nginx
    spec:
      containers:
      - name: nginx
        image: nginx:latest
        ports:
        - containerPort: 80
```

This YAML file defines a Kubernetes Deployment that manages three replicas of an Nginx container.

## Step 2: Apply the Deployment

Apply the deployment to your Kubernetes cluster:

```bash
kubectl apply -f nginx-deployment.yaml
```

## Step 3: Check Deployment Status

Check the status of your deployment:

```bash
kubectl get deployments
kubectl get pods
```

You should see three pods running.

## Step 4: Expose the Deployment

To make the Nginx service accessible from outside the cluster, you'll need to expose it:

```bash
kubectl expose deployment nginx-deployment --type=LoadBalancer --port=80
```

## Step 5: Verify Service Status

Check the status of your service:

```bash
kubectl get services
```

Once the external IP is assigned, you can access your Nginx service using a web browser.

## Step 6: Scale the Deployment (Optional)

You can scale your deployment up or down easily:

```bash
kubectl scale deployment nginx-deployment --replicas=5
```

## Step 7: Clean Up (Optional)

If you want to delete the deployment and associated resources:

```bash
kubectl delete deployment nginx-deployment
kubectl delete service nginx-deployment
```

Congratulations! You've successfully deployed a stateless application (Nginx) on Kubernetes.

Keep in mind that this is a basic example. Real-world applications may require additional configuration, such as persistent storage, environment variables, and more. Always refer to the official Kubernetes documentation for in-depth guidance and best practices.
