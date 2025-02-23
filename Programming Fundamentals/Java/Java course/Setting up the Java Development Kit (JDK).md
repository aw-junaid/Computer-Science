Setting up the **Java Development Kit (JDK)** is the first step to start developing and running Java applications. The JDK includes the tools needed to compile, debug, and run Java programs, such as the **Java Compiler (`javac`)**, the **Java Runtime Environment (JRE)**, and other utilities. Below is a step-by-step guide to setting up the JDK on different operating systems.

---

### **1. Download the JDK**
1. Go to the official Oracle JDK website or an open-source alternative like **Adoptium** (Eclipse Temurin):
   - **Oracle JDK**: [Oracle JDK Downloads](https://www.oracle.com/java/technologies/javase-downloads.html)
   - **Adoptium (Eclipse Temurin)**: [Adoptium JDK Downloads](https://adoptium.net/)
2. Choose the appropriate version of the JDK (e.g., Java 17 LTS or the latest version).
3. Select the installer for your operating system (Windows, macOS, or Linux).

---

### **2. Install the JDK**

#### **Windows**
1. Run the downloaded installer (e.g., `jdk-17_windows-x64_bin.exe`).
2. Follow the installation wizard:
   - Accept the license agreement.
   - Choose the installation directory (e.g., `C:\Program Files\Java\jdk-17`).
3. Complete the installation.

#### **macOS**
1. Open the downloaded `.dmg` file (e.g., `jdk-17_macos-x64_bin.dmg`).
2. Run the installer package (e.g., `JDK 17.pkg`).
3. Follow the installation instructions.
4. Complete the installation.

#### **Linux**
1. Extract the downloaded `.tar.gz` file (e.g., `jdk-17_linux-x64_bin.tar.gz`):
   ```bash
   tar -xzf jdk-17_linux-x64_bin.tar.gz
   ```
2. Move the extracted folder to a suitable location (e.g., `/usr/local/java`):
   ```bash
   sudo mv jdk-17 /usr/local/java/
   ```

---

### **3. Set Up Environment Variables**
To use the JDK tools from the command line, you need to set up the **JAVA_HOME** and **PATH** environment variables.

#### **Windows**
1. Open **System Properties**:
   - Right-click on **This PC** or **My Computer** and select **Properties**.
   - Click on **Advanced system settings**.
   - Click on **Environment Variables**.
2. Add a new system variable:
   - Variable name: `JAVA_HOME`
   - Variable value: Path to the JDK installation directory (e.g., `C:\Program Files\Java\jdk-17`).
3. Update the `PATH` variable:
   - Find the `Path` variable in the system variables list and click **Edit**.
   - Add a new entry: `%JAVA_HOME%\bin`.

#### **macOS and Linux**
1. Open a terminal.
2. Edit the shell configuration file:
   - For **bash**: `~/.bashrc` or `~/.bash_profile`
   - For **zsh**: `~/.zshrc`
3. Add the following lines:
   ```bash
   export JAVA_HOME=/usr/local/java/jdk-17
   export PATH=$JAVA_HOME/bin:$PATH
   ```
4. Save the file and reload the shell configuration:
   ```bash
   source ~/.bashrc  # or source ~/.zshrc
   ```

---

### **4. Verify the Installation**
To ensure the JDK is installed and configured correctly, open a terminal or command prompt and run the following commands:

1. Check the Java version:
   ```bash
   java -version
   ```
   Output should look like:
   ```
   java version "17" 2021-09-14
   Java(TM) SE Runtime Environment (build 17+35-LTS-2724)
   Java HotSpot(TM) 64-Bit Server VM (build 17+35-LTS-2724, mixed mode, sharing)
   ```

2. Check the Java compiler version:
   ```bash
   javac -version
   ```
   Output should look like:
   ```
   javac 17
   ```

---

### **5. Write and Run a Simple Java Program**
1. Create a file named `HelloWorld.java`:
   ```java
   public class HelloWorld {
       public static void main(String[] args) {
           System.out.println("Hello, World!");
       }
   }
   ```
2. Compile the program:
   ```bash
   javac HelloWorld.java
   ```
   This generates a `HelloWorld.class` file.
3. Run the program:
   ```bash
   java HelloWorld
   ```
   Output:
   ```
   Hello, World!
   ```

---

### **6. (Optional) Install an Integrated Development Environment (IDE)**
While you can write and run Java programs using a text editor and the command line, using an IDE can make development easier. Popular Java IDEs include:
- **IntelliJ IDEA**: [Download IntelliJ IDEA](https://www.jetbrains.com/idea/)
- **Eclipse**: [Download Eclipse](https://www.eclipse.org/downloads/)
- **NetBeans**: [Download NetBeans](https://netbeans.apache.org/)

---

### **7. Troubleshooting**
- **"java" or "javac" is not recognized**: Ensure the `PATH` environment variable is set correctly.
- **Incorrect Java version**: Verify that the `JAVA_HOME` and `PATH` variables point to the correct JDK installation.
- **Permission issues (Linux/macOS)**: Use `sudo` to move files or modify system directories.

---

### **Conclusion**
Setting up the JDK is a straightforward process that involves downloading, installing, and configuring the JDK on your system. Once set up, you can start writing, compiling, and running Java programs. With the JDK installed, you’re ready to explore the world of Java development!
