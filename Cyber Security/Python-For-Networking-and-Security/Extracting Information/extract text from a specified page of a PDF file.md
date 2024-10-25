The provided Python script uses the `PyPDF2` library to extract text from a specified page of a PDF file. Here's an explanation of the code:

```python
#!/usr/bin/env python3

import PyPDF2

# Open the PDF file for reading in binary mode
pdfFile = open("pdf/XMPSpecificationPart3.pdf", "rb")

# Create a PdfFileReader object
pdfReader = PyPDF2.PdfFileReader(pdfFile)

# Prompt the user to enter the page number
page_number = input("Enter page number:")

# Get the specified page object
pageObj = pdfReader.getPage(int(page_number) - 1)

# Extract text from the page
text_pdf = str(pageObj.extractText())

# Print the extracted text
print(text_pdf)
```

Explanation:

1. **Shebang Line:**
   - `#!/usr/bin/env python3`: Specifies the Python interpreter to use.

2. **Importing `PyPDF2` Module:**
   - `import PyPDF2`: Imports the PyPDF2 module for working with PDF files.

3. **Opening the PDF File:**
   - `pdfFile = open("pdf/XMPSpecificationPart3.pdf", "rb")`: Opens the specified PDF file ("pdf/XMPSpecificationPart3.pdf") in binary mode.

4. **Creating a `PdfFileReader` Object:**
   - `pdfReader = PyPDF2.PdfFileReader(pdfFile)`: Creates a `PdfFileReader` object to read the PDF file.

5. **User Input for Page Number:**
   - `page_number = input("Enter page number:")`: Prompts the user to enter the page number they want to extract text from.

6. **Getting the Specified Page Object:**
   - `pageObj = pdfReader.getPage(int(page_number) - 1)`: Gets the specified page object using the `getPage` method. Note that page numbers are zero-indexed in PyPDF2.

7. **Extracting Text from the Page:**
   - `text_pdf = str(pageObj.extractText())`: Extracts text from the specified page using the `extractText` method and converts it to a string.

8. **Printing Extracted Text:**
   - `print(text_pdf)`: Prints the extracted text to the console.

Note:
- The script prompts the user to input the page number, and it extracts and prints the text from the specified page of the PDF file.
- Keep in mind that the text extraction may not be perfect, especially for complex PDF files with images or unusual fonts.
- Ensure that you have the PyPDF2 library installed (`pip install PyPDF2`) before running the script.
