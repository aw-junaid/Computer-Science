Configuring Role-Based Access Control (RBAC) in Kubernetes helps you control who can access and perform operations within your cluster. Here are the steps to set up RBAC:

## Step 1: Enable RBAC

Ensure that RBAC is enabled in your Kubernetes cluster. It is usually enabled by default in modern Kubernetes installations.

## Step 2: Create a Service Account

1. Create a YAML file named `custom-service-account.yaml`:

```yaml
apiVersion: v1
kind: ServiceAccount
metadata:
  name: custom-service-account
```

2. Apply the Service Account:

```bash
kubectl apply -f custom-service-account.yaml
```

## Step 3: Create a Role

1. Create a YAML file named `custom-role.yaml`:

```yaml
kind: Role
apiVersion: rbac.authorization.k8s.io/v1
metadata:
  namespace: default
  name: custom-role
rules:
- apiGroups: [""] 
  resources: ["pods", "pods/log", "services", "deployments"]
  verbs: ["get", "list", "watch", "create", "update", "patch", "delete"]
```

2. Apply the Role:

```bash
kubectl apply -f custom-role.yaml
```

## Step 4: Bind Role to Service Account

1. Create a YAML file named `role-binding.yaml`:

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  name: custom-role-binding
subjects:
- kind: ServiceAccount
  name: custom-service-account
roleRef:
  kind: Role
  name: custom-role
  apiGroup: rbac.authorization.k8s.io
```

2. Apply the Role Binding:

```bash
kubectl apply -f role-binding.yaml
```

## Step 5: Verify RBAC Configuration

Check if the RBAC resources have been created:

```bash
kubectl get serviceaccounts,roles,rolebindings
```

You should see `custom-service-account`, `custom-role`, and `custom-role-binding` listed.

## Step 6: Use the Service Account

To use this custom service account, you'll need to specify it when creating or deploying resources. For example, when creating a pod:

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: mypod
  annotations:
    "eks.amazonaws.com/role-arn": "arn:aws:iam::123456789012:role/your-role"
spec:
  serviceAccountName: custom-service-account
  containers:
  - name: mycontainer
    image: nginx
```

This ensures that the pod uses the custom service account for permissions.

Remember to replace the `arn:aws:iam::123456789012:role/your-role` with an actual IAM role if you're running on AWS.

These steps outline the process for setting up basic RBAC in Kubernetes. Depending on your specific use case, you might need more fine-grained control or additional RBAC resources. Always refer to the official Kubernetes documentation for best practices and advanced configurations.
