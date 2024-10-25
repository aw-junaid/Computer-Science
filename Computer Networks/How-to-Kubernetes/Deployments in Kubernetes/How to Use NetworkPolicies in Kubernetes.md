Using Network Policies in Kubernetes allows you to control the traffic flow between pods. It provides fine-grained control over which pods can communicate with each other. Here's a step-by-step guide:

## Step 1: Enable Network Policies

First, ensure that your Kubernetes cluster supports Network Policies. Not all cloud providers or Kubernetes distributions have Network Policies enabled by default.

If you're using a managed Kubernetes service (like GKE, EKS, AKS), consult their documentation on enabling Network Policies.

## Step 2: Create a Network Policy

Create a file named `network-policy.yaml` with the following content:

```yaml
apiVersion: networking.k8s.io/v1
kind: NetworkPolicy
metadata:
  name: allow-nginx
spec:
  podSelector:
    matchLabels:
      app: nginx
  policyTypes:
  - Ingress
  - Egress
  ingress:
  - from:
    - podSelector:
        matchLabels:
          role: db
    ports:
    - protocol: TCP
      port: 80
  egress:
  - to:
    - podSelector:
        matchLabels:
          role: api
    ports:
    - protocol: TCP
      port: 8080
```

This Network Policy allows pods labeled with `app: nginx` to receive incoming traffic from pods labeled with `role: db` on port 80. It also allows pods labeled with `app: nginx` to send traffic to pods labeled with `role: api` on port 8080.

## Step 3: Apply the Network Policy

Apply the network policy:

```bash
kubectl apply -f network-policy.yaml
```

## Step 4: Label Pods

Make sure your pods have the appropriate labels (`app: nginx`, `role: db`, `role: api`) as defined in the Network Policy.

## Step 5: Verify Network Policy

To verify that the Network Policy is working, you can try to access the nginx pods from other pods that do not meet the criteria specified in the policy. They should not be able to establish a connection.

## Tips:

- Network Policies are namespace-specific. Make sure you create them in the correct namespace, or in the case of a single-namespace cluster, use the default namespace.

- Remember that Network Policies are additive. If multiple policies apply to a pod, the most restrictive rules will take precedence.

- Always refer to the official Kubernetes documentation for best practices and advanced configurations when working with Network Policies.
