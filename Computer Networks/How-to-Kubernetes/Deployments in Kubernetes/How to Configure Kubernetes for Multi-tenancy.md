Configuring Kubernetes for multi-tenancy involves setting up policies and resource quotas to isolate and manage resources for different user groups or applications. Here's a step-by-step guide:

## Step 1: Enable RBAC

Role-Based Access Control (RBAC) allows you to define fine-grained permissions for different users or groups. Ensure that RBAC is enabled in your Kubernetes cluster.

## Step 2: Create Namespaces

Namespaces provide a way to divide cluster resources between multiple users or teams. Create namespaces for each tenant:

```bash
kubectl create namespace tenant1
kubectl create namespace tenant2
```

## Step 3: Assign Service Accounts

Create service accounts for each namespace:

```bash
kubectl create serviceaccount -n tenant1 tenant1-sa
kubectl create serviceaccount -n tenant2 tenant2-sa
```

## Step 4: Define Role and RoleBinding

Create a Role that defines the permissions for a specific tenant in their namespace:

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: Role
metadata:
  namespace: tenant1
  name: tenant1-role
rules:
- apiGroups: [""]
  resources: ["pods", "services", "configmaps", "secrets"]
  verbs: ["get", "list", "watch", "create", "update", "delete"]
```

Create a RoleBinding to associate the Role with the ServiceAccount:

```yaml
apiVersion: rbac.authorization.k8s.io/v1
kind: RoleBinding
metadata:
  namespace: tenant1
  name: tenant1-rolebinding
subjects:
- kind: ServiceAccount
  name: tenant1-sa
roleRef:
  kind: Role
  name: tenant1-role
  apiGroup: rbac.authorization.k8s.io
```

## Step 5: Create Resource Quotas

Resource quotas help to limit the amount of resources a namespace can consume. Define quotas for each namespace:

```yaml
apiVersion: v1
kind: ResourceQuota
metadata:
  namespace: tenant1
spec:
  hard:
    pods: "10"
    services: "5"
    configmaps: "5"
    secrets: "5"
```

Apply these YAML files to create the roles, role bindings, and resource quotas for each tenant.

## Step 6: Isolate Network Policies

Define Network Policies to isolate network traffic between namespaces:

```yaml
apiVersion: networking.k8s.io/v1
kind: NetworkPolicy
metadata:
  namespace: tenant1
  name: allow-same-namespace
spec:
  podSelector: {}
  ingress:
  - from:
    - podSelector: {}
```

## Step 7: Configure LimitRanges

LimitRanges allow you to specify the minimum and maximum resource requirements for a namespace.

```yaml
apiVersion: v1
kind: LimitRange
metadata:
  namespace: tenant1
  name: tenant1-limitrange
spec:
  limits:
  - type: Pod
    max:
      memory: "64Mi"
      cpu: "250m"
    min:
      memory: "32Mi"
      cpu: "50m"
```

Apply these YAML files to set up network policies and limit ranges.

## Step 8: Monitor and Enforce

Continuously monitor resource usage and adjust quotas and policies as needed. Regularly review RBAC roles and bindings to ensure they are correctly assigned.

By following these steps, you can configure Kubernetes for multi-tenancy, allowing multiple users or teams to share a single cluster while maintaining isolation and resource allocation for each tenant. Always refer to the official Kubernetes documentation for best practices and advanced configurations.
