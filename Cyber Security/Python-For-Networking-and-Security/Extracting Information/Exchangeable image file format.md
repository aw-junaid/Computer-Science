This code snippet uses the Python Imaging Library (PIL), or its fork Pillow, to open an image file, retrieve its EXIF (Exchangeable image file format) data, and print the information in a human-readable format. Here's an explanation of the code:

```python
from PIL import Image
from PIL.ExifTags import TAGS

# Open an image file
image_path = 'images/image.jpg'
img = Image.open(image_path)

# Retrieve and print EXIF data
for (tag, value) in img._getexif().items():
    print('%s = %s' % (TAGS.get(tag), value))
```

Explanation:

1. **Importing PIL Modules:**
   - `from PIL import Image`: Import the `Image` class from the PIL (or Pillow) library.
   - `from PIL.ExifTags import TAGS`: Import the `TAGS` dictionary, which maps EXIF tag numbers to human-readable names.

2. **Opening an Image:**
   - `img = Image.open(image_path)`: Open the image file located at the specified path (`'images/image.jpg'`) using the `Image.open()` method. This creates an `Image` object (`img`).

3. **Retrieving and Printing EXIF Data:**
   - `img._getexif()`: Retrieve the EXIF data from the image. The `_getexif()` method returns a dictionary where keys are EXIF tag numbers, and values are the corresponding tag values.
   - The code then iterates over each key-value pair in the EXIF data and prints the information using the `TAGS` dictionary to convert tag numbers to human-readable names.

4. **Printing Format:**
   - `print('%s = %s' % (TAGS.get(tag), value))`: Print each EXIF tag and its corresponding value in a formatted way. `%s` is a placeholder for a string, and `%s` and `%s` are replaced by the tag name and value, respectively.

**Note:**
- EXIF data may not be present in all image files, so the code includes error handling to avoid issues if the image has no EXIF data.
- Ensure that you have Pillow installed (`pip install Pillow`) before running the code.
- The `TAGS` dictionary is crucial for converting EXIF tag numbers to human-readable names, providing more understandable output.

This script is useful for inspecting the metadata stored in images, which can include details about the camera settings, date and time, and other information captured at the time the photo was taken.
