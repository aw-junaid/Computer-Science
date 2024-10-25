```python
#!/usr/bin/env python

from PIL import Image

def set_LSB(value, bit):
    if bit == '0':
        value = value & 254
    else:
        value = value | 1
    return value

def get_LSB(value):
    if value & 1 == 0:
        return '0'
    else:
        return '1'

def get_pixel_pairs(iterable):
    a = iter(iterable)
    return zip(a, a)


def extract_message(image):
 
    c_image = Image.open(image)
    pixel_list = list(c_image.getdata())
    message = ""

    for pix1, pix2 in get_pixel_pairs(pixel_list):
        message_byte = "0b"
        for p in pix1:
            message_byte += get_LSB(p)

        for p in pix2:
            message_byte += get_LSB(p)
            
        if message_byte == "0b00000000":
            break

        message += chr(int(message_byte,2))

    return message
    
def hide_message(image, message, outfile):

    message += chr(0)
    c_image = Image.open(image)
    c_image = c_image.convert('RGBA')
    out = Image.new(c_image.mode, c_image.size)
    width, height = c_image.size
    pixList = list(c_image.getdata())
    newArray = []
    
    for i in range(len(message)):
        charInt = ord(message[i])
        cb = str(bin(charInt))[2:].zfill(8)
        pix1 = pixList[i*2]
        pix2 = pixList[(i*2)+1]
        newpix1 = []
        newpix2 = []

        for j in range(0,4):
            newpix1.append(set_LSB(pix1[j], cb[j]))
            newpix2.append(set_LSB(pix2[j], cb[j+4]))

        newArray.append(tuple(newpix1))
        newArray.append(tuple(newpix2))

    newArray.extend(pixList[len(message)*2:])
    
    out.putdata(newArray)
    out.save(outfile)
    return outfile   

	
if __name__ == "__main__":
    print("Testing hide message in python_secrets.png with LSB ...")
    print(hide_message('python.png', 'Hidden message', 'python_secrets.png'))
    print("Hide test passed, testing message extraction ...")
    print(extract_message('python_secrets.png'))
```

This Python script is designed to hide and extract a message using the Least Significant Bit (LSB) steganography technique. LSB steganography involves replacing the least significant bit of pixel values in an image with the bits of a hidden message.

Here's an explanation of the functions and the main code:

1. **`set_LSB(value, bit)` function:**
   - This function takes a pixel value (`value`) and a bit (`bit`) as parameters.
   - It modifies the least significant bit of the pixel value based on the provided bit (0 or 1) and returns the updated value.

2. **`get_LSB(value)` function:**
   - This function takes a pixel value (`value`) as a parameter.
   - It extracts the least significant bit from the pixel value and returns it as a string ('0' or '1').

3. **`get_pixel_pairs(iterable)` function:**
   - This function takes an iterable and returns an iterator that generates pairs of elements from the iterable.
   - It's used to iterate over pairs of pixels in the image.

4. **`extract_message(image)` function:**
   - This function extracts a hidden message from an image that was previously created using LSB steganography.
   - It opens the image, retrieves the pixel data, and iterates over pairs of pixels.
   - For each pair, it extracts the LSBs from each pixel's color channel to reconstruct the hidden message.
   - The message is terminated when '00000000' (null terminator) is encountered.

5. **`hide_message(image, message, outfile)` function:**
   - This function hides a message in an image using LSB steganography and saves the result to an output file.
   - It opens the original image, converts it to RGBA mode, and creates a new image for the output.
   - It converts each character of the message to its binary representation and replaces the LSBs of pairs of pixels with the message bits.
   - The resulting image is saved to the specified output file.

6. **Main Code:**
   - The script tests the `hide_message` function by hiding the message "Hidden message" in the 'python.png' image and saving the result as 'python_secrets.png'.
   - It then tests the `extract_message` function by attempting to extract the hidden message from 'python_secrets.png'.

