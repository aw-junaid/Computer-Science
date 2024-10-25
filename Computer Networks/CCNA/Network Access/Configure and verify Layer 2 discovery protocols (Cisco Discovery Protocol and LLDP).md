Layer 2 discovery protocols, such as Cisco Discovery Protocol (CDP) and Link Layer Discovery Protocol (LLDP), are used to discover and provide information about neighboring devices in a network. These protocols are commonly employed in networking environments to aid in device management, troubleshooting, and network monitoring. Here are the steps to configure and verify CDP and LLDP on Cisco devices:

### Configure CDP:

#### 1. **Enable CDP Globally:**
   - To enable CDP globally on a Cisco device, use the following command:

     ```bash
     Router(config)# cdp run
     ```

#### 2. **Enable CDP on Specific Interfaces:**
   - To enable CDP on a specific interface, use the following command in interface configuration mode:

     ```bash
     Router(config-if)# cdp enable
     ```

### Verify CDP Configuration:

#### 1. **Check CDP Status:**
   - Use the following command to check the CDP status on a Cisco device:

     ```bash
     Router# show cdp
     ```

   - This command displays information about neighboring devices, including their device ID, local interface, and capabilities.

#### 2. **Verify CDP on a Specific Interface:**
   - To check CDP information on a specific interface, use the following command:

     ```bash
     Router# show cdp interface <interface>
     ```

   - Replace `<interface>` with the specific interface, such as `GigabitEthernet0/1`.

### Configure LLDP:

#### 1. **Enable LLDP Globally:**
   - To enable LLDP globally on a Cisco device, use the following command:

     ```bash
     Router(config)# lldp run
     ```

#### 2. **Enable LLDP on Specific Interfaces:**
   - To enable LLDP on a specific interface, use the following command in interface configuration mode:

     ```bash
     Router(config-if)# lldp transmit
     Router(config-if)# lldp receive
     ```

### Verify LLDP Configuration:

#### 1. **Check LLDP Status:**
   - Use the following command to check the LLDP status on a Cisco device:

     ```bash
     Router# show lldp
     ```

   - This command displays information about neighboring devices, similar to the `show cdp` command.

#### 2. **Verify LLDP on a Specific Interface:**
   - To check LLDP information on a specific interface, use the following command:

     ```bash
     Router# show lldp interface <interface>
     ```

   - Replace `<interface>` with the specific interface, such as `GigabitEthernet0/1`.

### Common Verification Tips:

- Verify that both CDP and LLDP are running on the device:

  ```bash
  Router# show cdp
  Router# show lldp
  ```

- Ensure that CDP and LLDP are enabled on the relevant interfaces.

- Check the output of the commands for neighboring devices, their capabilities, and the local interfaces through which they are connected.

- Periodically monitor CDP and LLDP information for changes and updates.

These commands and configurations are specific to Cisco devices. For devices from other vendors, the configuration and verification steps may differ. Additionally, ensure that CDP and LLDP are supported and compatible with the devices in your network.
