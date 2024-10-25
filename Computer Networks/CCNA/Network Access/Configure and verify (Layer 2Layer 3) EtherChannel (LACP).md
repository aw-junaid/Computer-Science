**EtherChannel** is a technology that allows the grouping of multiple physical Ethernet links into a single logical link, providing increased bandwidth and redundancy. The Link Aggregation Control Protocol (LACP) is a standardized method (IEEE 802.3ad) for negotiating and forming EtherChannels dynamically. Below are the steps to configure and verify Layer 2 and Layer 3 EtherChannel with LACP on Cisco devices:

### Configure Layer 2 EtherChannel with LACP:

#### 1. **Access Interface Configuration Mode:**
   - Access the interface configuration mode for each interface participating in the EtherChannel:

     ```bash
     Switch(config)# interface range <interface_range>
     ```

   - Replace `<interface_range>` with the range of interfaces (e.g., `GigabitEthernet0/1 - 2`) to be part of the EtherChannel.

#### 2. **Enable LACP:**
   - Enable LACP on the interfaces:

     ```bash
     Switch(config-if-range)# channel-group <channel_group_number> mode active
     ```

   - Replace `<channel_group_number>` with a number representing the EtherChannel group.

#### 3. **Verify Configuration:**
   - Check the EtherChannel configuration:

     ```bash
     Switch# show etherchannel summary
     ```

   - Verify that the interfaces are bundled into the EtherChannel.

### Configure Layer 3 EtherChannel with LACP:

#### 1. **Configure Layer 3 Interfaces:**
   - Create Layer 3 interfaces for the EtherChannel bundle:

     ```bash
     Switch(config)# interface port-channel <channel_group_number>
     Switch(config-if)# description Layer3_EtherChannel
     Switch(config-if)# ip address <ip_address> <subnet_mask>
     ```

   - Replace `<channel_group_number>`, `<ip_address>`, and `<subnet_mask>` with appropriate values.

#### 2. **Configure Physical Interfaces:**
   - Configure the physical interfaces:

     ```bash
     Switch(config)# interface range <interface_range>
     Switch(config-if-range)# channel-group <channel_group_number> mode active
     ```

   - Replace `<interface_range>` and `<channel_group_number>` as before.

#### 3. **Verify Configuration:**
   - Verify Layer 3 EtherChannel configuration:

     ```bash
     Switch# show etherchannel summary
     ```

     ```bash
     Switch# show ip interface brief
     ```

     Verify the port-channel interface and its associated IP address.

### Verification Commands:

- **Show EtherChannel Summary:**
  ```bash
  Switch# show etherchannel summary
  ```

- **Show EtherChannel Details:**
  ```bash
  Switch# show etherchannel <channel_group_number> detail
  ```

- **Show IP Interface Brief (for Layer 3 EtherChannel):**
  ```bash
  Switch# show ip interface brief
  ```

### Common Troubleshooting Tips:

1. **Check LACP Status:**
   - Ensure that LACP is in the "active" mode on all participating interfaces.

2. **Verify Interface Configuration:**
   - Double-check the interface configurations for errors.

3. **Check Compatibility:**
   - Ensure that both ends of the EtherChannel have compatible settings (LACP mode, speed, and duplex).

4. **Physical Connectivity:**
   - Verify physical connectivity between devices and ensure that all cables are properly connected.

5. **Check VLAN Consistency:**
   - Ensure that the VLAN configuration is consistent on all interfaces in the EtherChannel.

EtherChannel with LACP provides a scalable and resilient solution for aggregating multiple links into a single logical link, improving both bandwidth and redundancy. Use the verification commands to confirm that the EtherChannel is formed and operational as expected.
