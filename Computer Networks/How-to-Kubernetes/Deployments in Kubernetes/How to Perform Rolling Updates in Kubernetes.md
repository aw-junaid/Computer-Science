Performing rolling updates in Kubernetes allows you to update your application without causing downtime. Here's how you can do it:

## Step 1: Create or Apply a Deployment

First, you need to have a Deployment in place. If you don't already have one, create or apply a deployment YAML file. For example:

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: my-deployment
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
      - name: my-container
        image: my-image:tag
        ports:
        - containerPort: 80
```

Apply the deployment using:

```bash
kubectl apply -f my-deployment.yaml
```

## Step 2: Update the Image Version

Update the image version in your deployment file or use the `set image` command:

```bash
kubectl set image deployment/my-deployment my-container=my-new-image:tag
```

## Step 3: Monitor the Update Progress

Monitor the update progress using:

```bash
kubectl get pods -l app=my-app
```

You'll see a mix of old and new pods while the update is in progress.

## Step 4: Check the Deployment Status

Once the update is complete, you'll see that all pods are running the new version:

```bash
kubectl get pods -l app=my-app
```

## Optional: Rollback

If something goes wrong during the update, you can perform a rollback to the previous version:

```bash
kubectl rollout undo deployment/my-deployment
```

This will revert the deployment to the previous version.

## Optional: Pause and Resume

You can also pause and resume a deployment if you want to halt the update process temporarily:

```bash
kubectl rollout pause deployment/my-deployment
kubectl rollout resume deployment/my-deployment
```

Keep in mind that this is a basic example. Depending on your specific requirements, you may need to handle more complex scenarios, such as database migrations or application-specific procedures during updates. Always refer to the official Kubernetes documentation for best practices and advanced configurations.
