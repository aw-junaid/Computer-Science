In Python, you can create and build XML documents using the built-in `xml.etree.ElementTree` module. This module provides a simple and convenient way to work with XML data. Here's how you can create and build XML documents step by step:

1. **Import the `ElementTree` Module:**

   Import the necessary module at the beginning of your script:

   ```python
   import xml.etree.ElementTree as ET
   ```

2. **Create Root Element:**

   Create the root element of your XML document using the `Element()` function:

   ```python
   root = ET.Element("data")
   ```

3. **Add Subelements:**

   Add subelements to the root element using the `SubElement()` function. You can also set attributes for the elements:

   ```python
   entry = ET.SubElement(root, "entry")
   entry.set("id", "1")

   title = ET.SubElement(entry, "title")
   title.text = "Example Title"

   body = ET.SubElement(entry, "body")
   body.text = "This is the content of the entry."
   ```

4. **Convert to String:**

   Convert the XML tree to a string using the `ET.tostring()` function. You can specify the encoding and method (default is "xml"):

   ```python
   xml_string = ET.tostring(root, encoding="utf-8", method="xml")
   ```

5. **Save to a File:**

   If you want to save the XML document to a file, use the `ET.ElementTree()` constructor and the `write()` method:

   ```python
   tree = ET.ElementTree(root)
   tree.write("output.xml", encoding="utf-8", xml_declaration=True)
   ```

Here's the complete example:

```python
import xml.etree.ElementTree as ET

root = ET.Element("data")

entry = ET.SubElement(root, "entry")
entry.set("id", "1")

title = ET.SubElement(entry, "title")
title.text = "Example Title"

body = ET.SubElement(entry, "body")
body.text = "This is the content of the entry."

xml_string = ET.tostring(root, encoding="utf-8", method="xml")
print(xml_string.decode("utf-8"))

tree = ET.ElementTree(root)
tree.write("output.xml", encoding="utf-8", xml_declaration=True)
```

This will create an XML document with the specified structure and save it as "output.xml" in the current directory.

Note that the `xml.etree.ElementTree` module provides a basic way to work with XML, but for more advanced XML processing and manipulation, you might consider using other libraries like `lxml` or `xmltodict`.
