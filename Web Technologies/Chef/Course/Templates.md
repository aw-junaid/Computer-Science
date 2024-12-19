### **Chef - Templates**

In Chef, templates are used to dynamically generate configuration files based on the node's attributes, roles, or other environmental factors. Templates are essential for generating dynamic content in configuration files, which is common when dealing with server configurations like NGINX, Apache, MySQL, etc. By using templates, you can keep your configuration files flexible and maintainable.

Templates in Chef use **Embedded Ruby (ERB)**, a Ruby-based templating system, to generate files dynamically.

---

### **1. What is a Template in Chef?**

A **template** in Chef is a text file that includes **ERB (Embedded Ruby)** code that will be evaluated at runtime to generate dynamic content. The **ERB syntax** allows you to embed Ruby code into a static file, making it possible to replace or insert variables dynamically based on the node's attributes or other data.

For example, a typical configuration file might change depending on the environment (e.g., different database credentials in `development` vs `production`), and templates can make it easy to manage those variations.

---

### **2. How Templates Work in Chef**

Templates in Chef work by taking a static file and embedding dynamic Ruby code inside it. Chef's **`template` resource** is used to create a file from a template, which dynamically populates the file based on node attributes and other variables.

#### **Basic Structure of a Template**

- **Template file**: This is the file that contains static content and dynamic Ruby code using ERB syntax (`<%= %>` or `<% %>`).
- **Template resource**: This is a Chef resource that tells Chef to create the file using the template.

---

### **3. Creating and Using Templates in Chef**

#### **1. Create a Template File**

First, you need to create the template file. The template file will be located in the **`templates` directory** within your cookbook.

For example, you might create a template for an NGINX configuration file:

**`cookbooks/my_cookbook/templates/default/nginx.conf.erb`**:
```erb
server {
    listen <%= node['nginx']['port'] %>;
    server_name <%= node['hostname'] %>;

    location / {
        root <%= node['nginx']['root'] %>;
        index index.html;
    }
}
```

In this example:
- `<%= %>`: The ERB tags are used to embed Ruby code in the template. Here we are dynamically inserting the `node['nginx']['port']` and `node['nginx']['root']` attributes from the Chef node.

#### **2. Use the Template Resource**

Next, use the **`template` resource** in your recipe to create the actual file from the template. Chef will evaluate the Ruby code inside the template and generate a file.

**`cookbooks/my_cookbook/recipes/default.rb`**:
```ruby
template '/etc/nginx/nginx.conf' do
  source 'nginx.conf.erb'    # The template file located in the 'templates' directory
  owner 'root'               # File ownership
  group 'root'
  mode '0644'                # Permissions for the file
  variables({
    nginx_port: node['nginx']['port'],
    nginx_root: node['nginx']['root']
  })                          # Passing node attributes as variables to the template
  notifies :reload, 'service[nginx]', :delayed  # Reload NGINX service if the file is updated
end
```

In this recipe:
- `source 'nginx.conf.erb'`: Points to the template file created in the `templates` directory.
- `variables`: A hash passed to the template, allowing you to inject values into the template dynamically. In this case, `nginx_port` and `nginx_root` are passed to the template.
- `notifies :reload, 'service[nginx]', :delayed`: Tells Chef to reload the NGINX service if the configuration file is modified.

---

### **4. ERB Syntax in Chef Templates**

The syntax used in Chef templates is based on **Embedded Ruby (ERB)**. Here are the main components:

- **`<%= ... %>`**: Outputs the result of Ruby code.
  - Example: `<%= node['nginx']['port'] %>` will output the value of `node['nginx']['port']`.

- **`<% ... %>`**: Executes Ruby code but does not output the result.
  - Example: `<% if node['platform'] == 'ubuntu' %>` will check the platform, but no output is shown.
  
- **Loops**: You can loop through arrays or hashes.
  ```erb
  <% node['nginx']['servers'].each do |server| %>
    server_name <%= server['name'] %>;
  <% end %>
  ```

- **Conditionals**: You can use conditionals to control the flow.
  ```erb
  <% if node['nginx']['enable_ssl'] %>
    listen 443 ssl;
  <% else %>
    listen 80;
  <% end %>
  ```

---

### **5. Best Practices for Templates**

- **Use Variables to Pass Data**: Always use the `variables` parameter in the `template` resource to pass data into the template. This keeps your templates flexible and reusable.
  
  ```ruby
  template '/etc/myapp/config.yml' do
    source 'config.yml.erb'
    variables({
      db_host: node['database']['host'],
      db_port: node['database']['port']
    })
  end
  ```

- **Do Not Hardcode Values**: Avoid hardcoding values directly in templates. Instead, pass attributes or data as variables, which makes the template adaptable to different nodes or environments.

- **Organize Templates**: Store templates in the `templates` directory of the cookbook, with separate subdirectories for different operating systems or configurations if necessary.
  
- **Use Notifications for Dynamic Configurations**: When using templates to modify system configuration files, use notifications to trigger service restarts or reloads when the configuration changes (e.g., `notifies :restart, 'service[nginx]'`).

- **Ensure Idempotency**: Chef resources should be idempotent, meaning they should only make changes if necessary. Templates naturally follow this principle because Chef only updates the file if the content has changed.

---

### **6. Example: Dynamic Configuration with Templates**

Here's a more complex example, where we generate a configuration file for a service that uses a combination of node attributes and environment-specific configurations.

**Example Template (`nginx.conf.erb`)**:
```erb
user <%= node['nginx']['user'] %>;
worker_processes <%= node['cpu']['total'] %>;

events {
    worker_connections <%= node['nginx']['worker_connections'] %>;
}

http {
    include       mime.types;
    server {
        listen       <%= node['nginx']['port'] %>;
        server_name  <%= node['hostname'] %>;

        location / {
            root   <%= node['nginx']['root'] %>;
            index  index.html index.htm;
        }

        <%- if node['nginx']['ssl_enabled'] %>
        ssl_certificate <%= node['nginx']['ssl_cert'] %>;
        ssl_certificate_key <%= node['nginx']['ssl_key'] %>;
        <%- end %>
    }
}
```

In this example, the template:
- Uses `node['nginx']['user']`, `node['nginx']['port']`, and `node['hostname']` to configure the NGINX server.
- Checks if SSL is enabled and includes SSL configuration dynamically.

The recipe could look like this:

```ruby
template '/etc/nginx/nginx.conf' do
  source 'nginx.conf.erb'
  variables(
    nginx_user: node['nginx']['user'],
    nginx_port: node['nginx']['port'],
    nginx_root: node['nginx']['root'],
    ssl_enabled: node['nginx']['ssl_enabled'],
    ssl_cert: node['nginx']['ssl_cert'],
    ssl_key: node['nginx']['ssl_key']
  )
  notifies :reload, 'service[nginx]', :delayed
end
```

This approach makes the NGINX configuration flexible, adapting based on the environment or node-specific attributes.

---

### **7. Conclusion**

Templates in Chef are a powerful way to dynamically generate configuration files for your infrastructure. By using the `template` resource and ERB syntax, you can easily generate files that reflect your node’s attributes, roles, environments, and other dynamic factors. This allows for highly adaptable and maintainable infrastructure code, ensuring that configurations are both flexible and consistent across different nodes and environments.

With templates, you can:
- Dynamically populate files based on node attributes or external data.
- Make your infrastructure code more modular and maintainable.
- Avoid hardcoding values in configuration files, allowing for easier management of changes over time.
