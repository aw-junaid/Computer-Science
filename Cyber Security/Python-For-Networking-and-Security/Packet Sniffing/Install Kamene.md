To run the code you provided, follow these steps:

1. **Install Kamene:**
   Before running the code, make sure you have Kamene installed. You can install it using the following command:

   ```bash
   pip install kamene
   ```

2. **Save the Code:**
   Save the code you provided in a file with a `.py` extension, for example, `sniffer.py`.

3. **Run the Script:**
   Open a terminal or command prompt, navigate to the directory where you saved the script, and run it using the following command:

   ```bash
   python sniffer.py
   ```

   Make sure you have Python installed on your system, and the `python` command is available in your terminal or command prompt.

4. **Observe Output:**
   The script will start sniffing network traffic on the specified ports (110, 25, and 143). If it detects packets containing 'user' or 'pass' in the payload, it will print information about the server and the payload.

   Keep in mind that running network sniffing tools may have legal and ethical implications. Ensure you have the necessary permissions before capturing and analyzing network traffic.

Please note that the script might require administrative privileges to capture network packets, depending on your operating system and network configuration. On some systems, you might need to run the script as an administrator or with elevated privileges.
