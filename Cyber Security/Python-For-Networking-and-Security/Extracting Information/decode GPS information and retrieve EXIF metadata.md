This Python script uses the Pillow library to extract and print metadata, including GPS information, from image files in a specified directory. The script defines functions to decode GPS information and retrieve EXIF metadata, and then it prints the metadata for all image files in the "images" directory.

Let's break down the code:

```python
from PIL.ExifTags import TAGS, GPSTAGS
from PIL import Image
import os

def get_exif_metadata(image_path):
    exifData = {}
    image = Image.open(image_path)
    if hasattr(image, '_getexif'):
        exifinfo = image._getexif()
        if exifinfo is not None:
            for tag, value in exifinfo.items():
                decoded = TAGS.get(tag, tag)
                exifData[decoded] = value
    decode_gps_info(exifData)
    return exifData

def decode_gps_info(exif):
    gpsinfo = {}
    if 'GPSInfo' in exif:
        Nsec = exif['GPSInfo'][2][2]
        Nmin = exif['GPSInfo'][2][1]
        Ndeg = exif['GPSInfo'][2][0]
        Wsec = exif['GPSInfo'][4][2]
        Wmin = exif['GPSInfo'][4][1]
        Wdeg = exif['GPSInfo'][4][0]
        if exif['GPSInfo'][1] == 'N':
            Nmult = 1
        else:
            Nmult = -1
        if exif['GPSInfo'][1] == 'E':
            Wmult = 1
        else:
            Wmult = -1
        latitude = Nmult * (Ndeg + (Nmin + Nsec/60.0)/60.0)
        longitude = Wmult * (Wdeg + (Wmin + Wsec/60.0)/60.0)
        exif['GPSInfo'] = {"Latitude": latitude, "Longitude": longitude}

def printMetadata():
    for dirpath, dirnames, files in os.walk("images"):
        for name in files:
            print("[+] Metadata for file: %s " % (dirpath + os.path.sep + name))
            try:
                exifData = {}
                exif = get_exif_metadata(dirpath + os.path.sep + name)
                for metadata in exif:
                    print("Metadata: %s - Value: %s " % (metadata, exif[metadata]))
                print("\n")
            except:
                import sys, traceback
                traceback.print_exc(file=sys.stdout)

if __name__ == "__main__":
    printMetadata()
```

Explanation:

1. **`get_exif_metadata` Function:**
   - Opens an image file using Pillow (`Image.open`).
   - Retrieves the EXIF data using `image._getexif()`.
   - Decodes the EXIF data using `TAGS` and stores it in the `exifData` dictionary.
   - Calls the `decode_gps_info` function to handle GPS information.
   - Returns the `exifData` dictionary.

2. **`decode_gps_info` Function:**
   - Decodes GPS information from the EXIF data and calculates latitude and longitude.
   - Updates the `exif` dictionary with the calculated GPS coordinates.

3. **`printMetadata` Function:**
   - Walks through the "images" directory and prints metadata for each image file.
   - Calls `get_exif_metadata` to retrieve and print the EXIF data.
   - Uses exception handling to catch any errors during the process.

4. **`if __name__ == "__main__":` Block:**
   - Calls the `printMetadata` function when the script is executed.

5. **Printing Metadata:**
   - The script prints metadata for each image file in the "images" directory, including any GPS coordinates that were decoded.

Note: Ensure that you have Pillow installed (`pip install Pillow`) before running the script. The script assumes that the image files are located in the "images" directory.
