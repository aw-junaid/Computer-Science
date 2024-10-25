Stegano is a Python module that provides tools for steganography. It allows users to hide information in various types of files, such as images. Below is an example of using Stegano for hiding and extracting messages in images.

First, you need to install the Stegano library:

```bash
pip install stegano
```

Now, you can use the following code:

```python
from stegano import lsb
from PIL import Image

def hide_message(image_path, message, output_path):
    secret = lsb.hide(image_path, message)
    secret.save(output_path)

def extract_message(image_path):
    secret = lsb.reveal(image_path)
    return secret

if __name__ == "__main__":
    # Hide a message in an image
    hide_message('input_image.png', 'Hidden message', 'output_image.png')

    # Extract the message from the image
    extracted_message = extract_message('output_image.png')
    print("Extracted Message:", extracted_message)
```

Explanation:

1. **`hide_message` function:**
   - Takes the path of the input image (`image_path`), the message to be hidden (`message`), and the path for the output image (`output_path`).
   - Uses Stegano's `lsb.hide` function to hide the message in the image.
   - Saves the resulting image with the hidden message to the specified output path.

2. **`extract_message` function:**
   - Takes the path of the image with a hidden message (`image_path`).
   - Uses Stegano's `lsb.reveal` function to extract the hidden message from the image.
   - Returns the extracted message.

3. **Main Code:**
   - Hides the message "Hidden message" in the 'input_image.png' image and saves the result as 'output_image.png'.
   - Extracts the hidden message from 'output_image.png' and prints it.

Note: Stegano provides different hiding techniques besides LSB, and you can explore its documentation for more options and customization.
