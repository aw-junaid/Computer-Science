### **Chef - Environment Variables**

In Chef, **Environment Variables** refer to values that are set in the operating system environment and can be accessed during the execution of Chef recipes, cookbooks, or other Chef processes. These environment variables are used to store configuration settings that can be accessed by applications and scripts, making them highly useful for tasks like managing configuration, setting paths, or customizing behavior based on the environment.

Chef allows you to define environment variables for both the **Chef Client** and for the **nodes** being managed by Chef.

---

### **Types of Environment Variables in Chef**

1. **System Environment Variables**:
   These are environment variables set at the operating system level. They are used by the system and by applications running on the machine.

   - Example: `PATH`, `HOME`, `USER`, `JAVA_HOME`, etc.
   - These variables are accessed by Chef cookbooks during the Chef Client run and can be used for configuring system behavior, such as specifying paths or configuration files.

2. **Node-Specific Environment Variables**:
   Chef allows you to define environment variables on a per-node basis within recipes or roles. These can be dynamically generated or set based on the node's attributes or environment.

---

### **How to Use Environment Variables in Chef**

There are several ways to set and access environment variables within Chef:

---

### **1. Using `ENV` in Recipes**

You can access environment variables in Chef recipes by referencing the Ruby `ENV` object, which is a hash-like object that stores all environment variables.

#### **Example: Accessing an Environment Variable in a Recipe**

```ruby
# In your recipe
env_value = ENV['MY_ENV_VAR']

log 'print_env_var' do
  message "The value of MY_ENV_VAR is #{env_value}"
  level :info
end
```

In this example:
- The `ENV['MY_ENV_VAR']` accesses the value of the `MY_ENV_VAR` environment variable, if it is set.
- The `log` resource is used to output the value of this environment variable to the Chef log.

---

### **2. Setting Environment Variables in Recipes**

You can also set environment variables within a recipe by modifying the system's environment during the Chef Client run. This is typically done using the `execute` resource or within the `bash` or `script` resources.

#### **Example: Setting an Environment Variable in a Recipe**

```ruby
# Set an environment variable in a bash resource
bash 'set_env_var' do
  code <<-EOH
    export MY_ENV_VAR="some_value"
    echo "MY_ENV_VAR is set to $MY_ENV_VAR"
  EOH
end
```

In this example:
- The `bash` resource runs a shell command to set the `MY_ENV_VAR` environment variable.
- Any subsequent shell commands executed within this block will have access to the newly set environment variable.

However, note that changes to environment variables within a single resource block will only persist for the duration of that resource execution. If you need to set environment variables globally across the entire node or for the Chef Client run, you should configure them through system-level configuration files.

---

### **3. Using `environment` in Resources**

Some Chef resources allow you to define environment variables for the commands or scripts they execute. For example, the `execute`, `bash`, or `script` resources allow you to specify environment variables using the `environment` attribute.

#### **Example: Using Environment Variables in the `execute` Resource**

```ruby
execute 'run_with_env_var' do
  command 'my_script.sh'
  environment(
    'MY_ENV_VAR' => 'some_value'
  )
end
```

In this example:
- The `environment` attribute is used to pass the `MY_ENV_VAR` to the `my_script.sh` command, making it available during the execution of this command.

---

### **4. Setting Node-Specific Environment Variables**

You can set node-specific environment variables in Chef by using node attributes or roles. These variables are then accessible during the Chef Client run.

#### **Example: Defining Environment Variables via Node Attributes**

```ruby
# In attributes/default.rb
default['my_cookbook']['env_var'] = 'some_value'
```

In a recipe, you can access this environment variable as follows:

```ruby
# In a recipe
env_var = node['my_cookbook']['env_var']

log 'print_env_var' do
  message "The node-specific environment variable is #{env_var}"
  level :info
end
```

---

### **5. Using Environment Variables in Chef Server Environments**

Chef Environments allow you to define variables that can be used in different environments (e.g., production, staging, development). These variables are useful when you need to have different configurations for nodes based on the environment they belong to.

#### **Example: Setting Environment Variables in an Environment File**

In Chef, environments are stored in the Chef server and can be used to define attributes that change based on the environment.

```json
{
  "name": "production",
  "description": "Production environment",
  "default_attributes": {
    "my_cookbook": {
      "env_var": "prod_value"
    }
  },
  "override_attributes": {}
}
```

In this example:
- The `my_cookbook['env_var']` attribute is set differently for nodes in the **production** environment, which will then affect the Chef recipes running on those nodes.

---

### **6. Chef-Specific Environment Variables**

Chef also defines a set of environment variables that are specific to the Chef ecosystem, typically used for managing the Chef Client run or debugging.

#### **Common Chef Environment Variables:**
- **`CHEF_SERVER_URL`**: The URL of the Chef Server.
- **`CHEF_NODE_NAME`**: The name of the node being managed by Chef.
- **`CHEF_ENVIRONMENT`**: The environment to which the node belongs.
- **`CHEF_CLIENT_KEY`**: The private key used by the Chef Client for authentication with the Chef Server.
- **`CHEF_CONFIG`**: The location of the Chef configuration file (`client.rb`).

These environment variables are automatically set during the Chef Client run, and you can use them in your recipes or scripts to customize behavior.

---

### **Best Practices for Using Environment Variables in Chef**

- **Security**: Avoid storing sensitive information like passwords or API keys directly in environment variables. Instead, use encrypted data bags or Chef Vault for sensitive data management.
- **Consistency**: Ensure that environment variables used in Chef are defined consistently across environments (development, staging, production).
- **Scope**: Define environment variables with appropriate scope. Use system-wide variables for general configuration and node-specific variables for configurations that differ between nodes or environments.
- **Debugging**: Use environment variables like `CHEF_LOG_LEVEL` and `CHEF_LOG_LOCATION` for debugging Chef runs. Set the log level and location to capture detailed output for troubleshooting.

---

### **Conclusion**

Environment variables in Chef are essential for managing dynamic configurations, customizing behavior, and enabling flexibility in infrastructure automation. They allow you to define system-level configurations, pass data between resources, and customize execution during Chef Client runs. Understanding how to manage and use environment variables effectively is crucial for building scalable, maintainable, and secure infrastructure with Chef.
