Setting up Egress Network Policies in Kubernetes allows you to control the outgoing traffic from pods. This is useful for restricting which external services pods can communicate with. Here's a step-by-step guide:

## Step 1: Enable Network Policies

First, ensure that your Kubernetes cluster supports Network Policies. Not all cloud providers or Kubernetes distributions have Network Policies enabled by default.

If you're using a managed Kubernetes service (like GKE, EKS, AKS), consult their documentation on enabling Network Policies.

## Step 2: Create an Egress Network Policy

Create a file named `egress-network-policy.yaml` with the following content:

```yaml
apiVersion: networking.k8s.io/v1
kind: NetworkPolicy
metadata:
  name: egress-allow
spec:
  podSelector: {}
  policyTypes:
  - Egress
  egress:
  - to:
    - ipBlock:
        cidr: 0.0.0.0/0
        except:
        - 192.168.0.0/24
```

In this example, the Network Policy allows all pods to send traffic to any IP address except for those in the `192.168.0.0/24` range.

## Step 3: Apply the Network Policy

Apply the network policy:

```bash
kubectl apply -f egress-network-policy.yaml
```

## Step 4: Verify Egress Rules

To verify that the Egress Network Policy is working, you can try to access external services from your pods. Only traffic to IP addresses outside of the `192.168.0.0/24` range should be allowed.

## Tips:

- Adjust the `cidr` and `except` fields in the Network Policy to specify the allowed and excluded IP ranges as per your requirements.

- You can also use other selectors like `namespaceSelector` and `podSelector` to narrow down which pods the policy applies to.

- Remember that Network Policies are namespace-specific. Make sure you create them in the correct namespace, or in the case of a single-namespace cluster, use the default namespace.

Always refer to the official Kubernetes documentation for best practices and advanced configurations when working with Network Policies.
