Extracting geo-location and metadata from documents, images, and browsers involves different techniques and tools depending on the type of file and the information you are seeking. Here's a general overview for each category:

### 1. **Documents:**
#### Extracting Metadata:
For documents such as PDFs, Microsoft Word, or Excel files, you can use libraries or tools that provide access to document metadata.

- **Python Libraries:**
  - `PyPDF2` for PDF files.
  - `python-docx` for Microsoft Word files.
  - `openpyxl` for Microsoft Excel files.

#### Example (Using PyPDF2 for PDFs):
```python
import PyPDF2

def extract_pdf_metadata(pdf_file_path):
    with open(pdf_file_path, 'rb') as pdf_file:
        pdf_reader = PyPDF2.PdfFileReader(pdf_file)
        document_info = pdf_reader.getDocumentInfo()
        print(f"Title: {document_info.title}")
        print(f"Author: {document_info.author}")
        # Extract other metadata fields as needed

# Usage
extract_pdf_metadata('example.pdf')
```

### 2. **Images:**
#### Extracting Metadata:
For images, metadata often includes information like GPS coordinates (geo-location), camera settings, and timestamps.

- **Python Libraries:**
  - `Pillow` (PIL Fork) is a powerful image processing library.
  - `exifread` for reading EXIF data from images.

#### Example (Using Pillow for Images):
```python
from PIL import Image

def extract_image_metadata(image_file_path):
    with Image.open(image_file_path) as img:
        exif_data = img._getexif()
        if exif_data:
            print(f"GPS Info: {exif_data.get(34853)}")  # GPS Info tag
            # Extract other metadata fields as needed

# Usage
extract_image_metadata('example.jpg')
```

### 3. **Browsers:**
#### Extracting Browser History:
For browsers, extracting history may involve interacting with browser APIs or accessing browser data directly.

- **Python Libraries:**
  - `sqlite3` for working with SQLite databases where browsers store history.

#### Example (Extracting Chrome History from SQLite Database):
```python
import sqlite3
import os

def extract_chrome_history():
    chrome_history_path = os.path.expanduser('~/.config/google-chrome/Default/History')
    connection = sqlite3.connect(chrome_history_path)
    cursor = connection.cursor()
    cursor.execute("SELECT title, url, last_visit_time FROM urls ORDER BY last_visit_time DESC LIMIT 10;")
    history_entries = cursor.fetchall()
    for entry in history_entries:
        print(f"Title: {entry[0]}, URL: {entry[1]}, Last Visit Time: {entry[2]}")

# Usage
extract_chrome_history()
```

**Note:**
- Extracting geo-location from documents and images may require specific tools or libraries depending on the file format and how the information is stored.
- Be aware of privacy and legal considerations when extracting and using geo-location data.

Always consider the legality and ethical implications of accessing and using certain types of data, especially personal or sensitive information. Ensure that your actions comply with relevant laws and regulations.
