To manually start and stop a server on Linux, you typically need to use the service management commands specific to your Linux distribution and init system. The two most common init systems used in modern Linux distributions are systemd and SysVinit. Below, I'll provide instructions for both init systems:

**1. Systemd:**
   - To start a server using systemd, you can use the `systemctl` command:
     ```
     sudo systemctl start service-name
     ```
     Replace `service-name` with the actual name of the service you want to start. For example, to start the Apache web server, you would use:
     ```
     sudo systemctl start apache2
     ```

   - To stop a server, you can use the `stop` parameter with `systemctl`:
     ```
     sudo systemctl stop service-name
     ```
     For example, to stop the Apache web server:
     ```
     sudo systemctl stop apache2
     ```

   - To restart a server, you can use the `restart` parameter with `systemctl`:
     ```
     sudo systemctl restart service-name
     ```
     For example, to restart the Apache web server:
     ```
     sudo systemctl restart apache2
     ```

**2. SysVinit:**
   - In older Linux distributions that use SysVinit, you can use the service command to start and stop services:

   - To start a server, use the `start` parameter with the `service` command:
     ```
     sudo service service-name start
     ```
     Replace `service-name` with the actual name of the service you want to start. For example, to start the Apache web server:
     ```
     sudo service apache2 start
     ```

   - To stop a server, use the `stop` parameter with the `service` command:
     ```
     sudo service service-name stop
     ```
     For example, to stop the Apache web server:
     ```
     sudo service apache2 stop
     ```

   - To restart a server, use the `restart` parameter with the `service` command:
     ```
     sudo service service-name restart
     ```
     For example, to restart the Apache web server:
     ```
     sudo service apache2 restart
     ```

Keep in mind that the actual service names can vary depending on the Linux distribution and the service you are using. Always use the correct service name for the specific server you want to start or stop. Additionally, with modern Linux distributions moving to systemd, it is recommended to use `systemctl` commands for service management whenever possible.
