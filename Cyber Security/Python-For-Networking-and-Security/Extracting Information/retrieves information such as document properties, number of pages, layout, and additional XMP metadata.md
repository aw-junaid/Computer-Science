The provided Python script uses the `PyPDF2` library to extract and print metadata from PDF files. The script recursively walks through the "pdf" directory, identifies PDF files, and retrieves information such as document properties, number of pages, layout, and additional XMP metadata.

Here's an explanation of the code:

```python
#!/usr/bin/env python3

from PyPDF2 import PdfFileReader
import os

def get_metadata():
    for dirpath, dirnames, files in os.walk("pdf"):
        for data in files:
            ext = data.lower().rsplit('.', 1)[-1]
            if ext in ['pdf']:
                print("[--- Metadata : " + "%s ", (dirpath + os.path.sep + data))
                print("------------------------------------------------------------------------------------")
                
                # Open the PDF file for reading
                pdfReader = PdfFileReader(open(dirpath + os.path.sep + data, 'rb'))
                
                # Get document information
                info = pdfReader.getDocumentInfo()
                for metaItem in info:
                    print('[+] ' + metaItem.strip('/') + ': ' + info[metaItem])

                # Get the number of pages
                pages = pdfReader.getNumPages()
                print('[+] Pages:', pages)

                # Get layout information
                layout = pdfReader.getPageLayout()
                print('[+] Layout:', str(layout))

                # Get XMP metadata
                xmpinfo = pdfReader.getXmpMetadata()

                # Print specific XMP metadata if available
                if hasattr(xmpinfo, 'dc_contributor'): print('[+] Contributor:', xmpinfo.dc_contributor)
                if hasattr(xmpinfo, 'dc_identifier'): print('[+] Identifier:', xmpinfo.dc_identifier)
                if hasattr(xmpinfo, 'dc_date'): print('[+] Date:', xmpinfo.dc_date)
                if hasattr(xmpinfo, 'dc_source'): print('[+] Source:', xmpinfo.dc_source)
                if hasattr(xmpinfo, 'dc_subject'): print('[+] Subject:', xmpinfo.dc_subject)
                if hasattr(xmpinfo, 'xmp_modifyDate'): print('[+] ModifyDate:', xmpinfo.xmp_modifyDate)
                if hasattr(xmpinfo, 'xmp_metadataDate'): print('[+] MetadataDate:', xmpinfo.xmp_metadataDate)
                if hasattr(xmpinfo, 'xmpmm_documentId'): print('[+] DocumentId:', xmpinfo.xmpmm_documentId)
                if hasattr(xmpinfo, 'xmpmm_instanceId'): print('[+] InstanceId:', xmpinfo.xmpmm_instanceId)
                if hasattr(xmpinfo, 'pdf_keywords'): print('[+] PDF-Keywords:', xmpinfo.pdf_keywords)
                if hasattr(xmpinfo, 'pdf_pdfversion'): print('[+] PDF-Version:', xmpinfo.pdf_pdfversion)

                # Print file size
                fsize = os.stat((dirpath + os.path.sep + data))
                print('[+] Size:', fsize.st_size, 'bytes \n\n')

if __name__ == "__main__":
    get_metadata()
```

Explanation:

1. **Shebang Line:**
   - `#!/usr/bin/env python3`: Specifies the Python interpreter to use.

2. **Imports:**
   - `from PyPDF2 import PdfFileReader`: Import the `PdfFileReader` class from the PyPDF2 library.
   - `import os`: Import the `os` module for working with the file system.

3. **`get_metadata` Function:**
   - Walks through the "pdf" directory using `os.walk`.
   - Identifies PDF files based on their extension.
   - Opens each PDF file and uses `PdfFileReader` to extract document information, number of pages, layout, and XMP metadata.
   - Prints the extracted metadata.

4. **Printing Specific XMP Metadata:**
   - Checks for the presence of specific XMP metadata attributes using `hasattr` and prints them if available.

5. **File Size:**
   - Uses `os.stat` to get file size information and prints the size in bytes.

6. **`if __name__ == "__main__":` Block:**
   - Calls the `get_metadata` function when the script is executed.

This script is useful for extracting basic information about PDF files, such as document properties and XMP metadata. Make sure to have the PyPDF2 library installed (`pip install PyPDF2`).
