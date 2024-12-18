### **Ruby on Rails - Installation Guide**

To get started with Ruby on Rails, you'll need to install Ruby, Rails, and a database system on your machine. Below is a step-by-step guide to help you install Ruby on Rails on your computer.

### **Prerequisites**

Before installing Rails, make sure you have the following:

1. **Ruby** installed (Rails is built on Ruby).
2. **Rails** installed (we will install it using RubyGems).
3. A **Database system** like SQLite (default), PostgreSQL, or MySQL.
4. **Node.js** and **Yarn** (for managing JavaScript dependencies).

### **Step-by-Step Installation**

#### **1. Install Ruby**

Rails is built on Ruby, so the first step is to install Ruby. You can install Ruby using a version manager like **RVM** (Ruby Version Manager) or **rbenv**. Alternatively, you can install Ruby directly from the official Ruby website.

**Option 1: Install Ruby using RVM (Recommended)**

1. **Install RVM** (Ruby Version Manager):
   - First, install the required dependencies:
     ```bash
     sudo apt-get update
     sudo apt-get install curl gpg
     ```
   - Then install RVM:
     ```bash
     \curl -sSL https://get.rvm.io | bash -s stable
     ```
   - Close and reopen your terminal, or run:
     ```bash
     source ~/.rvm/scripts/rvm
     ```

2. **Install Ruby using RVM**:
   - Install the latest stable version of Ruby:
     ```bash
     rvm install ruby
     ```

3. **Set the default Ruby version**:
   ```bash
   rvm use ruby --default
   ```

**Option 2: Install Ruby using rbenv**

1. Install rbenv and ruby-build:
   ```bash
   sudo apt-get install rbenv
   ```

2. Install Ruby using rbenv:
   ```bash
   rbenv install 3.1.2  # Example version
   rbenv global 3.1.2
   ```

**Option 3: Install Ruby using Homebrew (macOS)**

1. Install Homebrew (if you don't have it):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. Install Ruby using Homebrew:
   ```bash
   brew install ruby
   ```

#### **2. Install Rails**

Once Ruby is installed, you can install Rails via the **RubyGems** package manager.

1. **Install Rails**:
   ```bash
   gem install rails
   ```

2. **Verify the Installation**:
   After installation, check the Rails version to confirm it's installed correctly:
   ```bash
   rails -v
   ```

   You should see the version of Rails printed in the terminal.

#### **3. Install Node.js and Yarn**

Rails requires **Node.js** and **Yarn** to manage JavaScript dependencies.

1. **Install Node.js**:
   You can install Node.js via **Node Version Manager (nvm)** or directly via a package manager.

   Using **nvm** (recommended for managing multiple versions):
   ```bash
   curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash
   source ~/.bashrc  # or source ~/.zshrc if using zsh
   nvm install node
   ```

   Alternatively, you can install Node.js using your system’s package manager (e.g., Homebrew for macOS or apt for Ubuntu).

2. **Install Yarn** (JavaScript package manager):
   Follow the installation instructions for **Yarn** from [Yarn's website](https://yarnpkg.com/getting-started/install) or use the following commands for Ubuntu:

   ```bash
   npm install --global yarn
   ```

#### **4. Install a Database**

Ruby on Rails can work with several types of databases, but by default, it uses **SQLite** for development and testing. If you want to use PostgreSQL or MySQL, you will need to install those.

- **Install SQLite** (default for Rails):
  ```bash
  sudo apt-get install sqlite3 libsqlite3-dev
  ```

- **Install PostgreSQL**:
  ```bash
  sudo apt-get install postgresql postgresql-contrib libpq-dev
  ```

- **Install MySQL**:
  ```bash
  sudo apt-get install mysql-server mysql-client libmysqlclient-dev
  ```

#### **5. Create a New Rails Application**

Once Ruby, Rails, Node.js, and a database are installed, you can create a new Rails application.

1. **Create a new Rails app**:
   ```bash
   rails new myapp
   ```

   This will create a new directory (`myapp`) containing all the necessary files for a Rails project.

2. **Navigate into your new Rails app**:
   ```bash
   cd myapp
   ```

3. **Start the Rails server**:
   ```bash
   rails server
   ```

   By default, the application will be available at `http://localhost:3000`.

4. **Visit the application in your browser**:
   Open a web browser and go to `http://localhost:3000`. You should see the Rails welcome page, confirming that the application is running.

#### **6. Install Additional Dependencies (Optional)**

You may want to install additional tools or dependencies based on your project needs, such as image handling libraries, authentication gems, or more advanced database systems.

### **Summary of Commands**

```bash
# Install Ruby (using RVM or rbenv)
\curl -sSL https://get.rvm.io | bash -s stable  # For RVM
rvm install ruby  # Install Ruby

# Install Rails
gem install rails

# Install Node.js (using nvm)
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash
nvm install node

# Install Yarn (using npm)
npm install --global yarn

# Install SQLite, PostgreSQL, or MySQL
sudo apt-get install sqlite3 libsqlite3-dev  # For SQLite
sudo apt-get install postgresql libpq-dev    # For PostgreSQL
sudo apt-get install mysql-server libmysqlclient-dev  # For MySQL

# Create a new Rails app
rails new myapp

# Start the Rails server
cd myapp
rails server
```

---

This guide should help you get Ruby on Rails installed and running on your machine. 
