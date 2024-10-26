Configuring guest access on Cisco wireless networks allows you to provide internet access to visitors or other users without compromising the security of your main network. Here's a step-by-step guide:

### Step 1: Access the Cisco Wireless Controller

1. Connect to the Cisco Wireless Controller through a web browser or SSH.

2. Log in with the appropriate credentials (username and password).

### Step 2: Create a Guest WLAN

1. Navigate to the WLANs section of the controller's interface.

2. Create a new WLAN for guest access. Configure the SSID, VLAN, and security settings:

   - **SSID**: Provide a name for the guest network.
   - **VLAN**: Assign a dedicated VLAN for guest traffic.
   - **Security**: Choose an appropriate security method (e.g., WPA2 Personal, WPA2 Enterprise).

### Step 3: Configure Security Settings

1. For WPA2 Personal Security:
   - Set a strong pre-shared key (PSK) that guests will use to connect.

2. For WPA2 Enterprise Security:
   - Integrate with an authentication server like RADIUS or LDAP for user authentication.

### Step 4: Set Up a Web Authentication Portal (Optional)

If you want to provide a captive portal for guests to authenticate, follow these steps:

1. Navigate to the **Security** section of the controller.

2. Set up a web authentication portal using an external server or the built-in local web server.

### Step 5: Create an Access Control List (ACL)

To control guest traffic, create an ACL that allows only necessary traffic and denies access to your internal network:

1. Navigate to the **Security** section and create a new ACL.

2. Define rules to allow access to the internet and any specific resources you want to provide.

### Step 6: Set Up a Guest VLAN

Create a separate VLAN for guest traffic to ensure isolation from your main network:

1. Navigate to the VLANs section and create a new VLAN.

2. Assign an appropriate VLAN ID and IP subnet for the guest network.

### Step 7: Configure DHCP for the Guest VLAN

Set up a DHCP server or DHCP relay for the guest VLAN to provide IP addresses to guest clients:

1. Navigate to the **Interfaces** section.

2. Configure DHCP settings for the guest VLAN.

### Step 8: Apply VLAN and WLAN Settings

Associate the guest WLAN with the guest VLAN:

1. Navigate back to the WLANs section.

2. Edit the guest WLAN and associate it with the guest VLAN you created.

### Step 9: Create a Guest Anchor Controller (Optional)

If you have multiple controllers and want to provide guest access across multiple locations, consider setting up a Guest Anchor Controller:

1. Set up a separate controller as the anchor controller for guest traffic.

2. Configure mobility groups to allow seamless roaming between controllers.

### Step 10: Test Guest Access

Connect a test device to the guest network and verify that it obtains an IP address, connects to the internet, and accesses the authentication portal (if configured).

### Step 11: Monitor and Fine-Tune

Regularly monitor guest access usage and security logs. Make adjustments as needed to improve performance and security.

Remember to consult the specific documentation for your Cisco Wireless Controller model and firmware version, as there may be slight variations in the configuration process.
