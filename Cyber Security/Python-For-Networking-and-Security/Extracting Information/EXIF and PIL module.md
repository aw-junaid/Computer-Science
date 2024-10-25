

The Exchangeable image file format (EXIF) is a standard for storing metadata in image files, including details such as camera settings, date and time, and location information. The Python Imaging Library (PIL) is a library for opening, manipulating, and saving many different image file formats.

Note: As of the end of 2011, the original PIL project is no longer maintained. However, the Pillow library is a more up-to-date and actively maintained fork of PIL. Therefore, it is recommended to use Pillow instead of PIL.

### Pillow (PIL Fork):
Pillow is a powerful image processing library that extends the capabilities of the original PIL. It provides support for various image formats and operations. You can install Pillow using:

```bash
pip install Pillow
```

### Extracting EXIF Data using Pillow:
```python
from PIL import Image
from PIL.ExifTags import TAGS, GPSTAGS

def get_exif_data(image_path):
    try:
        with Image.open(image_path) as img:
            exif_data = img._getexif()
            if exif_data is not None:
                for tag, value in exif_data.items():
                    tag_name = TAGS.get(tag, tag)
                    print(f"{tag_name}: {value}")

                    # If GPSInfo is present, decode it
                    if tag_name == 'GPSInfo':
                        for t, v in value.items():
                            sub_tag_name = GPSTAGS.get(t, t)
                            print(f"  {sub_tag_name}: {v}")

    except (AttributeError, KeyError, IndexError):
        print("Error reading EXIF data.")

# Example usage
get_exif_data('example.jpg')
```

### Example:
```python
from PIL import Image
from PIL.ExifTags import TAGS

# Open an image file
image_path = 'example.jpg'
img = Image.open(image_path)

# Extract EXIF data
exif_data = img._getexif()

# Print EXIF information
if exif_data is not None:
    for tag, value in exif_data.items():
        tag_name = TAGS.get(tag, tag)
        print(f"{tag_name}: {value}")
else:
    print("No EXIF data found.")
```

In the above code:
- The `Image.open()` method from Pillow is used to open an image file.
- The `_getexif()` method is used to retrieve the EXIF data.
- The `TAGS` dictionary is used to map tag numbers to tag names.

Ensure that you have Pillow installed (`pip install Pillow`) before using it. This library provides a convenient way to work with images and extract metadata, including EXIF data.
