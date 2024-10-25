Configuring and verifying VLANs spanning multiple switches involves creating VLANs, assigning VLAN IDs to ports, and configuring trunk links between switches. This ensures that devices in the same VLAN can communicate with each other, even if they are connected to different switches. Here are the general steps for configuring and verifying VLANs in a network with multiple switches:

### Configuration Steps:

#### 1. **Create VLANs on Each Switch:**
   - Access the command-line interface (CLI) of each switch.
   - Create VLANs using the following commands:

     ```bash
     Switch1(config)# vlan 10
     Switch1(config-vlan)# name Sales
     ```

     ```bash
     Switch2(config)# vlan 10
     Switch2(config-vlan)# name Sales
     ```

     Repeat this for each VLAN you want to create.

#### 2. **Assign VLANs to Access Ports:**
   - Assign VLANs to access ports on each switch:

     ```bash
     Switch1(config)# interface FastEthernet0/1
     Switch1(config-if)# switchport mode access
     Switch1(config-if)# switchport access vlan 10
     ```

     ```bash
     Switch2(config)# interface FastEthernet0/1
     Switch2(config-if)# switchport mode access
     Switch2(config-if)# switchport access vlan 10
     ```

     Repeat this for all access ports in each VLAN.

#### 3. **Configure Trunk Links:**
   - Configure trunk links between switches to carry traffic for multiple VLANs:

     ```bash
     Switch1(config)# interface GigabitEthernet0/1
     Switch1(config-if)# switchport mode trunk
     ```

     ```bash
     Switch2(config)# interface GigabitEthernet0/1
     Switch2(config-if)# switchport mode trunk
     ```

#### 4. **Verify VLAN Configuration:**
   - Verify VLAN configuration on each switch:

     ```bash
     Switch1# show vlan
     ```

     ```bash
     Switch2# show vlan
     ```

   - Verify VLAN configuration on a specific port:

     ```bash
     Switch1# show interfaces FastEthernet0/1 switchport
     ```

     ```bash
     Switch2# show interfaces FastEthernet0/1 switchport
     ```

   - Verify trunk configuration:

     ```bash
     Switch1# show interfaces GigabitEthernet0/1 switchport
     ```

     ```bash
     Switch2# show interfaces GigabitEthernet0/1 switchport
     ```

### Verification Steps:

#### 1. **Ping Between Devices in the Same VLAN:**
   - Connect devices to access ports in the same VLAN on different switches.
   - Ensure that devices can ping each other successfully.

#### 2. **Ping Between Devices in Different VLANs:**
   - Connect devices to access ports in different VLANs on different switches.
   - Ensure that devices cannot ping each other, as they are in different VLANs.

#### 3. **Verify Trunk Links:**
   - Check the status and configuration of trunk links:

     ```bash
     Switch1# show interfaces GigabitEthernet0/1 switchport
     ```

     ```bash
     Switch2# show interfaces GigabitEthernet0/1 switchport
     ```

   - Confirm that the trunk links are in the desired VLANs.

#### 4. **Check VLAN Information:**
   - Verify VLAN information on each switch:

     ```bash
     Switch1# show vlan
     ```

     ```bash
     Switch2# show vlan
     ```

   - Ensure that the VLANs are listed and have the correct associated ports.

By following these configuration and verification steps, you can successfully set up VLANs spanning multiple switches, allowing for efficient network segmentation and communication between devices within the same VLAN.
