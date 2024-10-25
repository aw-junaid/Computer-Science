Setting up Pod Disruption Budgets (PDBs) with Prometheus in Kubernetes allows you to monitor and control the disruption of your pods during events like maintenance or upgrades. This helps ensure the availability of your applications. Here's a step-by-step guide:

## Step 1: Deploy Prometheus Operator

1. **Install the Prometheus Operator**:

   The Prometheus Operator simplifies the deployment and management of Prometheus. You can install it using Helm:

   ```bash
   helm repo add prometheus-community https://prometheus-community.github.io/helm-charts
   helm repo update
   helm install prometheus prometheus-community/kube-prometheus-stack
   ```

   This will install Prometheus, Alertmanager, Grafana, and related components.

## Step 2: Create a Pod Disruption Budget (PDB)

1. **Define the PDB**:

   Create a Pod Disruption Budget (PDB) YAML file, for example, `pdb.yaml`, with the following content:

   ```yaml
   apiVersion: policy/v1beta1
   kind: PodDisruptionBudget
   metadata:
     name: my-pdb
   spec:
     selector:
       matchLabels:
         app: my-app
     maxUnavailable: 1
   ```

   In this example, we're allowing a maximum of 1 unavailable pod at a time.

2. **Apply the PDB**:

   Apply the PDB definition:

   ```bash
   kubectl apply -f pdb.yaml
   ```

## Step 3: Configure Prometheus Alert Rules

1. **Edit Prometheus Rules**:

   Edit the Prometheus rules by modifying the `prometheusrules` CustomResource:

   ```bash
   kubectl edit prometheusrules prometheus-kube-prometheus-prometheusrules
   ```

   Add a new alert rule targeting your application pods:

   ```yaml
   - alert: MyPDBViolation
     expr: sum(pdb_controller_pod_disruptions_total{namespace="default",pod="<YOUR_APP_POD_NAME>",pdb="my-pdb"}) by (pod) > 0
     for: 5m
     labels:
       severity: warning
     annotations:
       summary: "PDB Violation: {{ $labels.pod }}"
       description: "PDB Violation: {{ $labels.pod }}"
   ```

   Replace `<YOUR_APP_POD_NAME>` with the name of your application pod.

2. **Save and Exit**:

   Save and exit the editor to apply the changes.

## Step 4: Monitor PDB Violations in Grafana

1. **Access Grafana Dashboard**:

   Port forward the Grafana service:

   ```bash
   kubectl port-forward svc/prometheus-grafana 3000
   ```

   Access Grafana at [http://localhost:3000](http://localhost:3000) (default login: admin/admin).

2. **Import PDB Violation Dashboard**:

   - In Grafana, go to `+` (plus sign) > `Import`.
   - Use the Dashboard ID `315` to import the "Pod Disruption Budget Violations" dashboard.

   This dashboard will visualize PDB violations based on the alert rule.

## Step 5: Test PDB Violation Alert

1. **Trigger a PDB Violation**:

   Simulate a PDB violation by deleting a pod controlled by the PDB:

   ```bash
   kubectl delete pod <POD_NAME>
   ```

   Replace `<POD_NAME>` with the name of a pod controlled by the PDB.

2. **Verify Alert**:

   Check Prometheus for the alert:

   ```bash
   kubectl port-forward svc/prometheus-kube-prometheus-prometheus 9090
   ```

   Access Prometheus at [http://localhost:9090](http://localhost:9090) and go to the "Alerts" tab.

## Notes:

- Ensure that you customize alerting rules based on your specific PDB and application configurations.

- Always refer to the official documentation of Prometheus, Grafana, and Kubernetes for best practices and advanced configurations.

Remember that this is a simplified guide, and actual configurations may vary based on your specific environment and requirements. Always refer to the official documentation for Prometheus, Grafana, and Kubernetes for best practices and advanced configurations.
