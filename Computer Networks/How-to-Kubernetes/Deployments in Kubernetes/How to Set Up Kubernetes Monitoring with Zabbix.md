Setting up Kubernetes monitoring with Zabbix involves deploying a Zabbix server, agents, and configuring them to collect metrics from your Kubernetes cluster. Here's a step-by-step guide:

## Prerequisites:

1. **A Running Kubernetes Cluster**: Ensure you have a Kubernetes cluster up and running.

2. **Zabbix Server and Agents**: Set up a Zabbix server and agents. You can follow the [official documentation](https://www.zabbix.com/documentation/current/manual/installation) for installation instructions.

## Step 1: Deploy Zabbix Server

1. **Install and Configure Zabbix Server**:

   Follow the official documentation to install and configure the Zabbix server.

2. **Configure Data Collection**:

   In Zabbix, go to `Configuration` > `Templates` and add templates for Kubernetes monitoring. You can use pre-built templates available in the [Zabbix Share](https://share.zabbix.com/cat-app/kubernetes).

## Step 2: Deploy Zabbix Agents in Kubernetes

1. **Create a ConfigMap for Zabbix Agent**:

   Create a ConfigMap YAML file (for example, `zabbix-agent-config.yaml`) with the Zabbix agent configuration:

   ```yaml
   apiVersion: v1
   kind: ConfigMap
   metadata:
     name: zabbix-agent-config
   data:
     zabbix_agentd.conf: |
       Server=<ZABBIX_SERVER_IP>
       ServerActive=<ZABBIX_SERVER_IP>
       Hostname=<AGENT_HOSTNAME>
   ```

   Replace `<ZABBIX_SERVER_IP>` with the IP address or hostname of your Zabbix server, and `<AGENT_HOSTNAME>` with the name you want to give to the agent.

   Apply the ConfigMap:

   ```bash
   kubectl apply -f zabbix-agent-config.yaml
   ```

2. **Deploy Zabbix Agent DaemonSet**:

   Create a DaemonSet YAML file (for example, `zabbix-agent-daemonset.yaml`) to deploy Zabbix agents on each node:

   ```yaml
   apiVersion: apps/v1
   kind: DaemonSet
   metadata:
     name: zabbix-agent
   spec:
     selector:
       matchLabels:
         app: zabbix-agent
     template:
       metadata:
         labels:
           app: zabbix-agent
       spec:
         containers:
         - name: zabbix-agent
           image: zabbix/zabbix-agent:latest
           volumeMounts:
           - name: zabbix-agent-config
             mountPath: /etc/zabbix/
           ports:
           - containerPort: 10050
     volumes:
     - name: zabbix-agent-config
       configMap:
         name: zabbix-agent-config
   ```

   Apply the DaemonSet:

   ```bash
   kubectl apply -f zabbix-agent-daemonset.yaml
   ```

## Step 3: Monitor Kubernetes in Zabbix

1. **Add Kubernetes Nodes to Zabbix**:

   In Zabbix, go to `Configuration` > `Hosts` and add the Kubernetes nodes using the agent hostname.

2. **Import Kubernetes Templates**:

   Import the Kubernetes monitoring templates that you added in Step 1.

3. **Monitor Kubernetes Cluster**:

   You should now be able to monitor your Kubernetes cluster in Zabbix, including nodes, pods, containers, and other relevant metrics.

## Notes:

- Customize the Zabbix agent configuration and DaemonSet YAML according to your specific requirements.

- Ensure that you have proper network connectivity between the Kubernetes nodes and the Zabbix server.

- Always refer to the official documentation for Zabbix and Kubernetes for best practices and advanced configurations.

Remember that this is a simplified guide, and actual configurations may vary based on your specific environment and requirements. Always refer to the official documentation for Zabbix, Kubernetes, and related tools for best practices and advanced configurations.
