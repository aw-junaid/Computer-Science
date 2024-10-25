Using Kubernetes Secrets with Helm allows you to manage sensitive information like passwords, API keys, and other confidential data in your Kubernetes deployments. Here's a step-by-step guide:

## Step 1: Create a Kubernetes Secret

Create a Kubernetes Secret using the following command:

```bash
kubectl create secret generic my-secret --from-literal=username=admin --from-literal=password=secretpassword
```

In this example, we're creating a secret named `my-secret` with two key-value pairs: `username=admin` and `password=secretpassword`.

## Step 2: Create a Values File for Helm

Create a `values.yaml` file in your Helm chart directory (or use an existing one). Add a section for the secret:

```yaml
secrets:
  - name: my-secret
    valueFrom:
      secretKeyRef:
        name: my-secret
        key: username
  - name: my-secret
    valueFrom:
      secretKeyRef:
        name: my-secret
        key: password
```

In this example, we're referencing the `my-secret` Kubernetes Secret and specifying that we want to use the `username` and `password` keys.

## Step 3: Use the Secret Values in Your Helm Templates

In your Helm templates (e.g., in `templates/deployment.yaml`), you can access the secret values using `.Values.secrets`:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: my-pod
spec:
  containers:
  - name: my-container
    image: my-image
    env:
    - name: USERNAME
      valueFrom:
        secretKeyRef:
          name: {{ .Values.secrets[0].name }}
          key: {{ .Values.secrets[0].valueFrom.secretKeyRef.key }}
    - name: PASSWORD
      valueFrom:
        secretKeyRef:
          name: {{ .Values.secrets[1].name }}
          key: {{ .Values.secrets[1].valueFrom.secretKeyRef.key }}
```

This example shows how to use the secret values as environment variables in a pod.

## Step 4: Install or Upgrade the Helm Chart

Install or upgrade your Helm chart:

```bash
helm install my-release .  # or `helm upgrade my-release .` if the release already exists
```

The Helm chart will use the secret values from `values.yaml` during the deployment.

## Tips:

- You can use Helm's `--set` option to override values from the `values.yaml` file during installation or upgrade.

- Ensure that you have the appropriate access permissions to create and use Secrets in your Kubernetes cluster.

- Always refer to the official Helm documentation for best practices and advanced configurations.

Remember that this is a simplified guide, and actual configurations may vary based on your specific environment and requirements. Always refer to the official documentation for Helm and Kubernetes for best practices and advanced configurations.
