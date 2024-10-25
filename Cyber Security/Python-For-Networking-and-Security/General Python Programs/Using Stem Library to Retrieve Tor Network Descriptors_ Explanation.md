### **Using Stem Library to Retrieve Tor Network Descriptors: Explanation**

This Python script demonstrates how to use the `stem` library to download and print information about Tor network descriptors, specifically the consensus document.

### **1. Importing the Required Module:**
```python
from stem.descriptor.remote import DescriptorDownloader
```

The script imports the `DescriptorDownloader` class from the `stem.descriptor.remote` module.

### **2. Creating Descriptor Downloader and Retrieving Consensus:**
```python
downloader = DescriptorDownloader()
descriptors = downloader.get_consensus().run()
```

An instance of `DescriptorDownloader` is created. The `get_consensus().run()` method is then called to retrieve the Tor network consensus. The `descriptors` variable holds the retrieved descriptors.

### **3. Printing Descriptor Information:**
```python
for descriptor in descriptors:
    print('Nickname:', descriptor.nickname)
    print('Fingerprint:', descriptor.fingerprint)
    print('Address:', descriptor.address)
    print('Bandwidth:', descriptor.bandwidth)
```

A loop iterates over the retrieved descriptors, and information such as nickname, fingerprint, address, and bandwidth is printed for each descriptor.

### **Explanation Summary:**
- The script uses the `stem` library to download and retrieve Tor network descriptors.
- The `DescriptorDownloader` class is utilized to fetch the consensus document, which contains information about Tor relays.
- Descriptor information such as nickname, fingerprint, address, and bandwidth is then printed for each relay in the consensus.

### **Note:**
Make sure to have the `stem` library installed (`pip install stem`) before running this script. Additionally, running this script requires a working internet connection to fetch the consensus from the Tor network.
