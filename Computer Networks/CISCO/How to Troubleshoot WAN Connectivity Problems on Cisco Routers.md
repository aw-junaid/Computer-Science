Troubleshooting WAN connectivity problems on Cisco routers involves a systematic approach to identify and resolve issues. Here are steps to help you troubleshoot common WAN connectivity problems:

### Step 1: Physical Layer Checks

1. **Check Physical Connections**: Ensure all cables, connectors, and interfaces are securely connected.

2. **Inspect Lights and LEDs**: Examine status lights on WAN interfaces. They can provide information about link status, activity, and speed.

### Step 2: Verify Configuration Settings

1. **Check Interface Configuration**: Verify that the WAN interface is correctly configured with the appropriate IP address, subnet mask, and default gateway.

2. **Check WAN Protocols**: Ensure that the correct encapsulation method (e.g., PPP, HDLC) is configured on the WAN interface.

3. **Check Authentication**: If applicable, verify that authentication (e.g., CHAP, PAP) is correctly configured for the WAN connection.

### Step 3: Verify WAN Protocol Status

1. **Check Interface Status**: Use the following command to view the status of the WAN interface:

```shell
show interface <interface-type> <interface-number>
```

2. **Check Protocol Status**: Verify that the WAN protocol (e.g., PPP, Frame Relay) is up. Look for the 'line protocol' status.

### Step 4: Test Basic Connectivity

1. **Ping Gateway**: Use the `ping` command to verify if you can reach the gateway IP address of the WAN provider.

```shell
ping <gateway-IP>
```

2. **Ping Remote Hosts**: Test connectivity to remote hosts on the WAN.

### Step 5: Check WAN Provider Equipment (For Leased Lines)

1. **Contact Service Provider**: If you have a leased line, contact your service provider to check for any issues on their end.

2. **Verify WAN Provider Equipment**: Ensure that modems, CSU/DSUs, or other WAN termination equipment are functioning properly.

### Step 6: Review Routing Table

1. **Check Routing Table**: Verify that there are appropriate routes to reach remote networks.

```shell
show ip route
```

2. **Check Default Route**: Ensure that a default route is configured if needed.

### Step 7: Check Firewall and Security Policies

1. **Verify Firewall Rules**: Ensure that the router's firewall or access control lists (ACLs) are not blocking necessary traffic.

### Step 8: Check NAT and PAT Configurations

1. **Verify NAT and PAT**: If Network Address Translation (NAT) or Port Address Translation (PAT) is configured, ensure it is functioning correctly.

### Step 9: Test DNS Resolution

1. **Check DNS Configuration**: Verify that DNS servers are configured correctly.

```shell
show ip name-server
```

2. **Test DNS Resolution**: Use the `ping` command to test DNS resolution.

```shell
ping <hostname>
```

### Step 10: Review Logs and Error Messages

1. **Check System Logs**: Examine system logs and error messages for any indications of WAN connectivity issues.

```shell
show logging
```

### Step 11: Use Debugging Commands (Caution!)

As a last resort, use debug commands to gain detailed information about the WAN connection process. Be cautious, as excessive use of debug commands can impact router performance.

### Step 12: Contact Service Provider Support

If the issue persists and it is related to the WAN service itself, contact your service provider's support team for assistance.

Remember to save configurations and document any changes made during troubleshooting. If you're unsure about any steps, consult Cisco documentation or seek assistance from a qualified network engineer.
