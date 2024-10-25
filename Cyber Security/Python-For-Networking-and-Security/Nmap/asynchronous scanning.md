### Overview

This Python script demonstrates asynchronous scanning using the `nmap` library. It performs asynchronous scans on the target host 'scanme.nmap.org' with different port numbers (-p 21, -p 22, -p 23, -p 80) and uses a callback function to handle the scan results. The script then continuously checks if the scanning is still in progress and waits for a specified time.

### Code Explanation

```python
import nmap

# Create an instance of PortScannerAsync
portScannerAsync = nmap.PortScannerAsync()

# Define a callback function to handle scan results
def callback_result(host, scan_result):
    print(host, scan_result)

# Perform asynchronous scans with different port numbers and use the callback function
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 21', callback=callback_result)
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 22', callback=callback_result)
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 23', callback=callback_result)
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 80', callback=callback_result)

# Check if scanning is still in progress and wait for a specified time
while portScannerAsync.still_scanning():
    print("Scanning >>>")
    portScannerAsync.wait(5)
```

- Creates an instance of `nmap.PortScannerAsync`.
- Defines a callback function (`callback_result`) that will be called with the scan results for each host.
- Performs asynchronous scans on the target host 'scanme.nmap.org' with different port numbers and uses the callback function to handle the results.
- Checks if scanning is still in progress using `portScannerAsync.still_scanning()`.
- Waits for 5 seconds using `portScannerAsync.wait(5)` before checking the scanning status again.

### Note

- Asynchronous scanning allows for concurrent scans, potentially improving efficiency.
- The callback function (`callback_result`) is called for each scanned host with its respective scan results.
- The script continuously checks and waits for the scanning to complete, providing an asynchronous behavior. Adjust the wait time based on your specific requirements.
- Ensure that the `nmap` library is installed before running the script.
