Route maps on Cisco routers are used to control the redistribution and manipulation of routing information between different routing protocols. They provide a powerful tool for customizing routing behavior. Here's a guide on how to create and apply route maps:

### Creating a Route Map:

1. **Access the Router's CLI**:

   Connect to your Cisco router using a console cable or through SSH/Telnet.

2. **Enter Privileged Exec Mode**:

   ```
   enable
   ```

   Provide the enable password if prompted.

3. **Enter Global Configuration Mode**:

   ```
   configure terminal
   ```

4. **Create the Route Map**:

   ```
   route-map <name> <permit|deny> <sequence-number>
   ```

   - `<name>`: A name to identify the route map.
   - `<permit|deny>`: Specifies whether to permit or deny routes matching the criteria.
   - `<sequence-number>`: A numerical value to determine the order of execution.

   Example:

   ```
   route-map MY_ROUTE_MAP permit 10
   ```

5. **Enter Route Map Configuration Mode**:

   ```
   route-map <name> <sequence-number>
   ```

   Example:

   ```
   route-map MY_ROUTE_MAP 10
   ```

6. **Set Match Criteria**:

   Define the criteria that routes must meet to be affected by the route map. This could include things like access lists, prefixes, AS-path, etc.

   ```
   match <criteria>
   ```

   Example:

   ```
   match ip address 10
   ```

7. **Set Actions**:

   Determine what should happen to routes that match the criteria. This can include setting attributes like next-hop, modifying metric values, etc.

   ```
   set <action>
   ```

   Example:

   ```
   set metric 100
   ```

8. **Exit Route Map Configuration Mode**:

   ```
   exit
   ```

9. **Repeat Steps 5-8 as Needed**:

   You can add multiple match and set statements to your route map.

10. **Save Configuration**:

    ```
    write memory
    ```

    or

    ```
    copy running-config startup-config
    ```

### Applying a Route Map:

Once you have created a route map, you need to apply it to a specific interface, routing process, or redistribution configuration.

**For Example, Applying a Route Map to a Redistribution Configuration**:

1. **Enter Router Configuration Mode**:

   ```
   configure terminal
   ```

2. **Access Redistribution Configuration**:

   ```
   router <routing-protocol>
   redistribute <source-protocol> <route-map-name>
   ```

   - `<routing-protocol>`: The protocol you're configuring (e.g., ospf, eigrp).
   - `<source-protocol>`: The protocol whose routes you're redistributing.
   - `<route-map-name>`: The name of the route map you created.

   Example:

   ```
   router ospf 1
   redistribute eigrp 100 route-map MY_ROUTE_MAP
   ```

3. **Save Configuration**:

   ```
   write memory
   ```

   or

   ```
   copy running-config startup-config
   ```

Remember to replace placeholders like `<name>`, `<criteria>`, `<action>`, etc., with your actual values. The exact commands and syntax might vary depending on the specific Cisco router model and IOS version you are using. Always consult the documentation for your specific router if you encounter any issues.
