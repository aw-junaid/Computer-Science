Implementing Port-Based Authentication (802.1X) on Cisco switches involves configuring the switch to enforce authentication for devices trying to connect to a network. Here's a step-by-step guide:

### Step 1: Access the Switch's CLI

Connect to your Cisco switch using a console cable or through SSH/Telnet.

### Step 2: Enter Privileged Exec Mode

```shell
enable
```

Provide the enable password if prompted.

### Step 3: Enter Global Configuration Mode

```shell
configure terminal
```

### Step 4: Enable 802.1X on the Interface

Configure the interface to use 802.1X authentication:

```shell
interface <interface-type> <interface-number>
```

Example:

```shell
interface GigabitEthernet0/1
```

### Step 5: Enable 802.1X Authentication

```shell
dot1x port-control auto
```

This command enables 802.1X port-based authentication on the interface.

### Step 6: Configure the Authentication Method (Optional)

You can specify the authentication method (EAP, MD5, etc.):

```shell
dot1x authentication <eap|md5>
```

Example:

```shell
dot1x authentication eap
```

### Step 7: Set the Reauthentication Period (Optional)

You can specify how often the switch reauthenticates devices:

```shell
dot1x reauthentication
dot1x timeout reauth-period <seconds>
```

Example:

```shell
dot1x timeout reauth-period 300
```

This sets the reauthentication period to 300 seconds (5 minutes).

### Step 8: Enable 802.1X Globally

```shell
dot1x system-auth-control
```

This command globally enables 802.1X authentication on the switch.

### Step 9: Save Configuration

```shell
write memory
```

or

```shell
copy running-config startup-config
```

### Step 10: Verify 802.1X Configuration

Use the command `show dot1x interface <interface-type> <interface-number>` to verify the 802.1X configuration on a specific interface.

### Important Notes:

- For 802.1X to work, you need a RADIUS server set up with the appropriate user database.

- Ensure the RADIUS server and shared secret are correctly configured on the switch.

- The exact commands and syntax might vary depending on the specific Cisco switch model and IOS version you are using. Always consult the documentation for your specific switch if you encounter any issues.

- Make sure you have a backup plan (like a local username/password) for accessing the switch in case RADIUS authentication fails.
