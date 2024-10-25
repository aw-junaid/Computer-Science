Setting up Pod Disruption Budgets (PDBs) with Thanos in Kubernetes involves configuring both PDBs and Thanos components. Here's a step-by-step guide:

## Prerequisites:

1. **A Running Kubernetes Cluster**: Ensure you have a Kubernetes cluster up and running.

2. **Thanos Components**: Set up Thanos components (such as Thanos Sidecar, Query, Store, etc.). You can follow the [official Thanos documentation](https://thanos.io/docs/getting-started.md) for installation instructions.

## Step 1: Create a Pod Disruption Budget (PDB)

1. **Define the PDB**:

   Create a Pod Disruption Budget (PDB) YAML file (for example, `pdb.yaml`) with the following content:

   ```yaml
   apiVersion: policy/v1beta1
   kind: PodDisruptionBudget
   metadata:
     name: my-pdb
   spec:
     selector:
       matchLabels:
         app: thanos-store
     maxUnavailable: 1
   ```

   In this example, we're allowing a maximum of 1 unavailable pod at a time. Make sure to replace `app: thanos-store` with the appropriate label selector for your Thanos Store pods.

2. **Apply the PDB**:

   Apply the PDB definition:

   ```bash
   kubectl apply -f pdb.yaml
   ```

## Step 2: Update Thanos Components

1. **Update Thanos Deployment YAMLs**:

   In your Thanos deployment YAMLs (e.g., `thanos-sidecar.yaml`, `thanos-query.yaml`, `thanos-store.yaml`, etc.), make sure to add the following annotations to the pod spec:

   ```yaml
   apiVersion: apps/v1
   kind: Deployment
   metadata:
     name: thanos-store
   spec:
     template:
       metadata:
         annotations:
           poddisruptionbudget.alpha.kubernetes.io/allowed-down-time: "5m"
   ```

   This annotation allows pods controlled by this deployment to be disrupted for up to 5 minutes.

2. **Apply the Updated Deployments**:

   Apply the updated deployment YAMLs:

   ```bash
   kubectl apply -f thanos-store.yaml
   ```

   Repeat this step for all the relevant Thanos components.

## Step 3: Verify PDB and Thanos Components

1. **View Pod Disruption Budget**:

   Check if the Pod Disruption Budget is applied:

   ```bash
   kubectl get pdb my-pdb
   ```

2. **Verify Thanos Components**:

   Ensure that the Thanos components (Sidecar, Query, Store, etc.) are running without any disruptions:

   ```bash
   kubectl get pods -l app=thanos
   ```

## Notes:

- Customize the Pod Disruption Budget and Thanos annotations according to your specific requirements.

- Always refer to the official documentation of Kubernetes and Thanos for best practices and advanced configurations.

Remember that this is a simplified guide, and actual configurations may vary based on your specific environment and requirements. Always refer to the official documentation for Kubernetes, Thanos, and related tools for best practices and advanced configurations.
