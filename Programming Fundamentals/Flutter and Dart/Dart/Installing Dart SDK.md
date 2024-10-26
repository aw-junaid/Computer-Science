To start with Dart development, you'll need to install the Dart SDK, which provides the Dart runtime, core libraries, and essential tools like the Dart analyzer and `dart` command-line tool.

### Installation Steps

#### 1. **Installing Dart on Windows**

   - **Using the Dart Installer**:
     1. Go to the [Dart download page](https://dart.dev/get-dart) and download the Windows installer.
     2. Run the installer and follow the installation steps.

   - **Using `choco` (Chocolatey)**:
     1. Open Command Prompt or PowerShell as Administrator.
     2. Run the following command:
        ```bash
        choco install dart-sdk
        ```
     3. Once installed, verify the installation by running:
        ```bash
        dart --version
        ```

#### 2. **Installing Dart on macOS**

   - **Using Homebrew**:
     1. Open Terminal.
     2. Run the following command to install Dart:
        ```bash
        brew tap dart-lang/dart
        brew install dart
        ```
     3. Verify the installation:
        ```bash
        dart --version
        ```

   - **Using the Installer**:
     1. Go to the [Dart download page](https://dart.dev/get-dart) and download the macOS installer.
     2. Run the installer and follow the setup steps.

#### 3. **Installing Dart on Linux**

   - **Using `apt` (Debian/Ubuntu)**:
     1. Open Terminal.
     2. Add the Dart repository and import the key:
        ```bash
        sudo apt update
        sudo apt install apt-transport-https
        sudo sh -c 'wget -qO- https://dl-ssl.google.com/linux/linux_signing_key.pub | apt-key add -'
        sudo sh -c 'wget -qO- https://storage.googleapis.com/download.dartlang.org/linux/debian/dart_stable.list > /etc/apt/sources.list.d/dart_stable.list'
        ```
     3. Install Dart SDK:
        ```bash
        sudo apt update
        sudo apt install dart
        ```
     4. Verify the installation:
        ```bash
        dart --version
        ```

#### 4. **Installing Dart with Flutter (Cross-Platform)**

   - If you’re planning to develop Flutter applications, the Flutter SDK comes with Dart pre-installed.
     1. Download the Flutter SDK from the [Flutter website](https://flutter.dev/docs/get-started/install).
     2. Extract and configure Flutter, then check the Dart installation using:
        ```bash
        dart --version
        ```

### Setting Up the PATH

After installation, you may need to add Dart to your system’s PATH to access the `dart` command from the terminal.

- **Windows**:
   - Go to **Control Panel > System > Advanced system settings**.
   - Click **Environment Variables**, find the **Path** variable, and add the directory path of the Dart SDK (e.g., `C:\tools\dart-sdk\bin`).

- **macOS and Linux**:
   - Add the Dart SDK path to `.bashrc` or `.zshrc`:
     ```bash
     export PATH="$PATH:/path/to/dart-sdk/bin"
     ```
   - Replace `/path/to/dart-sdk` with the actual installation path.

### Verifying Installation

To confirm that Dart is correctly installed, run:
```bash
dart --version
```
You should see the Dart SDK version displayed in the terminal.
