Configuring a DHCP (Dynamic Host Configuration Protocol) scope involves setting up a range of IP addresses, along with other relevant information, to be dynamically allocated to hosts on a network. Here's a step-by-step guide using a generic DHCP server configuration:

### Step 1: Access DHCP Server Configuration

1. **Access DHCP Server:**
   - Log in to the DHCP server where you want to configure the DHCP scope.

### Step 2: Enter DHCP Configuration Mode

2. **Enter DHCP Configuration Mode:**
   - The exact command may vary depending on the DHCP server software you are using.
   
   ```bash
   dhcp-server(config)# dhcp
   ```

### Step 3: Configure DHCP Scope

3. **Create DHCP Pool/Scope:**
   ```bash
   dhcp-server(config)# pool DHCP_Scope_Name
   ```

   Replace `DHCP_Scope_Name` with a meaningful name for your DHCP scope.

4. **Specify IP Address Range:**
   ```bash
   dhcp-server(dhcp-config)# network 192.168.1.0 /24
   dhcp-server(dhcp-config)# address-range 192.168.1.10 192.168.1.50
   ```

   Adjust the IP address range according to your network requirements. The example above allocates addresses from 192.168.1.10 to 192.168.1.50.

5. **Set Default Gateway:**
   ```bash
   dhcp-server(dhcp-config)# default-router 192.168.1.1
   ```

   Set the default gateway (router) for the DHCP clients.

6. **Configure DNS Server:**
   ```bash
   dhcp-server(dhcp-config)# dns-server 8.8.8.8
   ```

   Set the DNS server(s) that DHCP clients should use.

7. **Specify Lease Duration (Optional):**
   ```bash
   dhcp-server(dhcp-config)# lease 7
   ```

   Set the lease duration for IP addresses. The example above sets it to 7 days. Adjust according to your network policies.

8. **Exclude Addresses (Optional):**
   ```bash
   dhcp-server(dhcp-config)# excluded-address 192.168.1.1 192.168.1.9
   ```

   Exclude specific addresses from the DHCP pool. These addresses won't be allocated to clients.

### Step 4: Exit DHCP Configuration Mode

9. **Exit DHCP Configuration Mode:**
   ```bash
   dhcp-server(dhcp-config)# exit
   ```

### Step 5: Save Configuration

10. **Save Configuration:**
   - The method to save configuration varies based on the DHCP server. Commonly, it's done using a `write` or `save` command.

### Step 6: Verify DHCP Configuration

11. **Verify DHCP Configuration:**
   - Depending on your DHCP server, use the appropriate command to check the active DHCP configurations and leases.

### Notes:

- **DHCP Server Software:**
  - The commands above are generic and may vary based on the DHCP server software you are using. Common DHCP server software includes ISC DHCP, Microsoft DHCP, and others.

- **IP Address Range:**
  - Ensure that the IP address range specified in the DHCP scope does not overlap with statically assigned addresses or other DHCP scopes in your network.

- **DNS and Default Gateway:**
  - Set DNS server(s) and the default gateway to enable proper network connectivity for DHCP clients.

- **Lease Duration:**
  - Choose a lease duration based on your network requirements. Shorter leases may lead to more frequent renewals, while longer leases may lead to IP address exhaustion.

This guide provides a basic setup for a DHCP scope. Adjustments might be necessary based on your network topology, policies, and the specific DHCP server software you are using.
