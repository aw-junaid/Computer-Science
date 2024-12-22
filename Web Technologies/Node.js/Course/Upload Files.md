### **Node.js - Upload Files**

File uploading is a common feature in web applications. In Node.js, you can implement file uploads using middleware libraries like **Multer** or **Formidable**. These libraries handle multipart/form-data, which is essential for uploading files.

---

### **Steps to Upload Files in Node.js**

1. **Set up a Node.js project.**
2. **Install the required dependencies.**
3. **Configure middleware for handling file uploads.**
4. **Create the upload endpoint.**

---

### **Example Using Multer**

#### **1. Install Dependencies**

First, install the required packages:
```bash
npm install express multer
```

#### **2. Project Structure**

```
/file-upload-example
  |-- app.js
  |-- /uploads (auto-created to store uploaded files)
  |-- package.json
```

#### **3. Code Implementation**

**app.js**
```javascript
const express = require('express');
const multer = require('multer');
const path = require('path');

const app = express();
const PORT = 3000;

// Set storage engine
const storage = multer.diskStorage({
    destination: './uploads/',
    filename: (req, file, cb) => {
        cb(null, file.fieldname + '-' + Date.now() + path.extname(file.originalname));
    }
});

// Initialize upload
const upload = multer({
    storage: storage,
    limits: { fileSize: 5 * 1024 * 1024 }, // Limit file size to 5MB
    fileFilter: (req, file, cb) => {
        // Allowed file types
        const fileTypes = /jpeg|jpg|png|gif/;
        const extName = fileTypes.test(path.extname(file.originalname).toLowerCase());
        const mimeType = fileTypes.test(file.mimetype);

        if (extName && mimeType) {
            cb(null, true);
        } else {
            cb('Error: Images only!');
        }
    }
}).single('myFile'); // Accept single file with name 'myFile'

// Serve static HTML form
app.get('/', (req, res) => {
    res.sendFile(__dirname + '/index.html');
});

// Upload endpoint
app.post('/upload', (req, res) => {
    upload(req, res, (err) => {
        if (err) {
            res.status(400).send({ message: err });
        } else {
            if (!req.file) {
                res.status(400).send({ message: 'No file uploaded!' });
            } else {
                res.send({
                    message: 'File uploaded successfully!',
                    file: `uploads/${req.file.filename}`
                });
            }
        }
    });
});

// Start server
app.listen(PORT, () => console.log(`Server running on http://localhost:${PORT}`));
```

---

#### **4. HTML Form for File Upload**

**index.html**
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Upload</title>
</head>
<body>
    <h1>Upload File</h1>
    <form action="/upload" method="POST" enctype="multipart/form-data">
        <input type="file" name="myFile" required />
        <button type="submit">Upload</button>
    </form>
</body>
</html>
```

---

### **How It Works**

1. The HTML form sends a POST request to `/upload` with the file.
2. Multer processes the file and stores it in the `uploads/` directory.
3. The server responds with a success message and the file path.

---

### **Multer Configuration Options**

1. **`storage`:** Defines where and how files should be stored.
2. **`limits`:** Sets file size limits (e.g., `5MB` in the example above).
3. **`fileFilter`:** Filters files based on their MIME types or extensions.

---

### **Example Using Formidable**

Alternatively, you can use **Formidable** for file uploads.

#### **Install Formidable**
```bash
npm install formidable
```

#### **Code Example**
```javascript
const express = require('express');
const formidable = require('formidable');
const path = require('path');
const fs = require('fs');

const app = express();
const PORT = 3000;

// Upload endpoint
app.post('/upload', (req, res) => {
    const form = new formidable.IncomingForm();
    form.uploadDir = path.join(__dirname, '/uploads');
    form.keepExtensions = true;

    form.parse(req, (err, fields, files) => {
        if (err) {
            return res.status(400).send({ message: 'Error uploading file' });
        }
        res.send({
            message: 'File uploaded successfully!',
            file: files.file.path
        });
    });
});

// Start server
app.listen(PORT, () => console.log(`Server running on http://localhost:${PORT}`));
```

---

### **Best Practices for File Uploads**

1. **Security:**
   - Validate file types and sizes.
   - Store uploaded files in a secure directory outside the web root.
   - Sanitize filenames to prevent directory traversal attacks.

2. **Performance:**
   - Use cloud storage services like AWS S3 or Google Cloud Storage for scalability.
   - Limit the size of uploaded files.

3. **Error Handling:**
   - Provide meaningful error messages for invalid uploads.
   - Handle scenarios like missing files or server errors gracefully.

4. **Testing:**
   - Test uploads with various file types, sizes, and edge cases.

---

### **Conclusion**

Uploading files in Node.js is straightforward using middleware like **Multer** or **Formidable**. Multer is well-suited for handling multipart/form-data, while Formidable offers flexibility for file parsing. Both libraries are widely used in the Node.js ecosystem.
