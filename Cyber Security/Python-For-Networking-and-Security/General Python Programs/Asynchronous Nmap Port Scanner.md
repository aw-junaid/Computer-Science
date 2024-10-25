### Asynchronous Nmap Port Scanner

This Python script uses the `nmap` library to perform asynchronous port scanning on a target host (`scanme.nmap.org`). It scans for ports 21, 22, 23, and 80 simultaneously and prints the results using a callback function.

### 1. Importing Required Module:

```python
import nmap
```

### 2. Asynchronous Port Scanning:

```python
portScannerAsync = nmap.PortScannerAsync()
```

### 3. Callback Function to Print Scan Results:

```python
def callback_result(host, scan_result):
    print(host, scan_result)
```

### 4. Initiating Asynchronous Scans:

```python
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 21', callback=callback_result)
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 22', callback=callback_result)
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 23', callback=callback_result)
portScannerAsync.scan(hosts='scanme.nmap.org', arguments='-p 80', callback=callback_result)
```

### 5. Waiting for Scan Completion:

```python
while portScannerAsync.still_scanning():
    print("Scanning >>>")
    portScannerAsync.wait(5)
```

### Notes:

- The script creates an instance of `nmap.PortScannerAsync()` to perform asynchronous scanning.
- It defines a callback function `callback_result` that prints the host and scan results.
- The script initiates four asynchronous scans for ports 21, 22, 23, and 80 using the `scan` method, providing the target host and scan arguments.
- It enters a loop to wait for the scans to complete. The `still_scanning` method is used to check if any scans are still in progress. The `wait` method is called to pause execution and allow time for scanning progress.

Ensure you have the necessary permissions before scanning any network or system.
