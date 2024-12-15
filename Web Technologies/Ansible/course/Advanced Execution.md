### **Ansible Advanced Execution**

In Ansible, advanced execution techniques provide you with the flexibility to control how tasks are executed on target systems. These features allow for more fine-grained control over task execution, concurrency, and error handling. Here's an overview of some of the advanced execution features in Ansible.

---

### **1. Parallelism and Concurrency**

Ansible allows you to control how many tasks are executed in parallel across hosts, making it scalable and efficient when working with a large number of systems.

#### **Using `forks`**

You can control the number of parallel connections (forks) with the `-f` or `--forks` flag when running an Ansible playbook.

```bash
ansible-playbook -i inventory.ini playbook.yml -f 10
```

This command runs the playbook with 10 parallel forks.

#### **Setting `forks` in Configuration File**

You can also set the number of forks in the Ansible configuration file (`ansible.cfg`):

```ini
[defaults]
forks = 10
```

#### **Using `serial` in a Playbook**

If you want to limit the number of hosts being executed at the same time within a playbook, you can use the `serial` directive in your playbook. This is useful when you need to apply changes to a small subset of hosts at a time (e.g., rolling updates).

Example:

```yaml
---
- name: Deploy updates to web servers
  hosts: web_servers
  serial: 5  # Run the play on 5 hosts at a time
  tasks:
    - name: Update web server packages
      ansible.builtin.yum:
        name: "*"
        state: latest
```

This playbook will run the tasks on only 5 hosts at a time from the `web_servers` group.

---

### **2. Asynchronous Execution and Polling**

Sometimes you might have tasks that take a long time to complete (e.g., installing software, restarting services, waiting for a task to finish). In these cases, you can use **asynchronous execution** to run tasks in the background.

#### **Using `async` and `poll`**

You can run a task asynchronously by setting the `async` parameter, which specifies how long the task will run before being considered complete. You also specify the `poll` parameter to control the polling interval.

```yaml
---
- name: Run a long-running task asynchronously
  hosts: localhost
  tasks:
    - name: Start long-running task
      ansible.builtin.command: /bin/sleep 600  # Sleep for 10 minutes
      async: 600  # Allow this task to run for 600 seconds (10 minutes)
      poll: 0  # Don't wait for the task to finish
      register: sleep_task

    - name: Check on task completion
      ansible.builtin.async_status:
        jid: "{{ sleep_task.ansible_job_id }}"
      register: job_result
      until: job_result.finished
      retries: 5
      delay: 10  # Check every 10 seconds
```

- **`async`**: This specifies the maximum amount of time (in seconds) the task is allowed to run asynchronously.
- **`poll`**: Set to `0` to not wait for the task to finish immediately. Instead, Ansible will continue executing the rest of the playbook.
- **`ansible.builtin.async_status`**: This task checks the status of the asynchronous task, and `until` retries until the task is complete.

---

### **3. Error Handling and Control Flow**

In Ansible, you can control error handling and task flow using **conditional statements**, **error handlers**, and **task retries**.

#### **Using `ignore_errors`**

If you want to ignore errors in a specific task and continue executing the playbook, you can use `ignore_errors: yes`.

```yaml
---
- name: Install software
  hosts: all
  tasks:
    - name: Install Apache
      ansible.builtin.yum:
        name: httpd
        state: present
      ignore_errors: yes  # Continue even if this task fails
```

#### **Using `block` for Grouping Tasks**

You can group related tasks using `block` and apply error handling for the entire block of tasks. This is useful if you want to handle errors at a higher level of granularity.

```yaml
---
- name: Deploy software with error handling
  hosts: all
  tasks:
    - block:
        - name: Install Apache
          ansible.builtin.yum:
            name: httpd
            state: present
        - name: Start Apache service
          ansible.builtin.service:
            name: httpd
            state: started
      rescue:
        - name: Notify failure
          debug:
            msg: "The Apache installation failed"
      always:
        - name: Clean up
          debug:
            msg: "Cleaning up resources after failure"
```

- **`block`**: Groups tasks together.
- **`rescue`**: Defines the tasks to be executed if any task in the block fails.
- **`always`**: Defines tasks that will always be executed, regardless of whether the block succeeds or fails.

#### **Using `retries` and `delay`**

You can specify how many times a task should retry on failure and how long to wait between retries using `retries` and `delay`.

```yaml
---
- name: Try installing software
  hosts: all
  tasks:
    - name: Install Apache
      ansible.builtin.yum:
        name: httpd
        state: present
      retries: 3  # Retry 3 times
      delay: 5  # Wait 5 seconds between retries
```

---

### **4. Using `when` for Conditional Execution**

Ansible provides the `when` statement to conditionally execute tasks based on the value of a variable, fact, or another condition.

#### **Simple `when` Condition**

```yaml
---
- name: Install Apache only if not already installed
  hosts: web_servers
  tasks:
    - name: Check if Apache is installed
      ansible.builtin.package_facts:

    - name: Install Apache
      ansible.builtin.yum:
        name: httpd
        state: present
      when: "'httpd' not in ansible_facts.packages"  # Only install if Apache is not installed
```

#### **Using `when` with Multiple Conditions**

You can also use `when` with multiple conditions (logical AND/OR):

```yaml
- name: Install Apache only if the system is RHEL and has port 80 open
  hosts: all
  tasks:
    - name: Check if system is RHEL
      ansible.builtin.setup:
        filter: ansible_distribution

    - name: Install Apache
      ansible.builtin.yum:
        name: httpd
        state: present
      when: ansible_facts['ansible_distribution'] == 'RedHat' and apache_port == 80
```

---

### **5. Ansible Callbacks and Customizing Output**

Ansible provides a flexible framework for controlling how output is displayed. This includes adjusting verbosity, custom callbacks, and using tools like `ANSIBLE_STDOUT_CALLBACK` to control how the output is rendered.

#### **Using `-v` for Verbosity**

By default, Ansible provides simple output. You can increase the verbosity by using one or more `-v` flags to see more detailed output:

```bash
ansible-playbook -i inventory.ini playbook.yml -v  # Minimal verbosity
ansible-playbook -i inventory.ini playbook.yml -vv # More detailed output
ansible-playbook -i inventory.ini playbook.yml -vvv # Debugging output
```

#### **Custom Output with `ANSIBLE_STDOUT_CALLBACK`**

Ansible allows you to customize the output format using the `ANSIBLE_STDOUT_CALLBACK` environment variable. For example, to use the `yaml` callback:

```bash
ANSIBLE_STDOUT_CALLBACK=yaml ansible-playbook -i inventory.ini playbook.yml
```

You can set this in the Ansible configuration file (`ansible.cfg`) under the `stdout_callback` setting:

```ini
[defaults]
stdout_callback = yaml
```

---

### **6. Ansible Vault for Secure Execution**

Ansible Vault allows you to encrypt sensitive data such as passwords, API keys, and configuration files. This is especially useful when you're automating tasks that require access to secrets.

#### **Encrypting a File**

To encrypt a file:

```bash
ansible-vault encrypt secrets.yml
```

#### **Decrypting a File**

To decrypt a file:

```bash
ansible-vault decrypt secrets.yml
```

#### **Using Vault in Playbooks**

You can use Vault-encrypted files in your playbooks by referencing them with `--ask-vault-pass` or `--vault-password-file`.

Example:

```bash
ansible-playbook --ask-vault-pass playbook.yml
```

---

### **Conclusion**

Advanced execution techniques in Ansible enhance flexibility, scalability, and error handling, making automation more efficient and manageable. By using features such as parallelism, asynchronous execution, error handling, conditional execution, and Ansible Vault, you can tailor your playbooks to meet specific needs, especially in large-scale environments. Mastering these techniques is crucial for more complex and real-world automation scenarios.
