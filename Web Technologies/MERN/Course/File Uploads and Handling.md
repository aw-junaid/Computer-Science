# **File Uploads and Handling in Web Applications**  

Uploading and handling files is a common feature in web applications, whether for **profile pictures, documents, videos, or any media files**.  

---

## **1. File Upload in Frontend (React)**
### **Using FormData API with Fetch**
The `FormData` API allows sending files as `multipart/form-data`.

#### **React File Upload Example**
```jsx
import { useState } from "react";

const FileUpload = () => {
  const [file, setFile] = useState(null);

  const handleFileChange = (e) => {
    setFile(e.target.files[0]); // Store file in state
  };

  const handleUpload = async () => {
    if (!file) return alert("Please select a file");

    const formData = new FormData();
    formData.append("file", file);

    try {
      const response = await fetch("http://localhost:5000/upload", {
        method: "POST",
        body: formData,
      });

      const result = await response.json();
      alert(result.message);
    } catch (error) {
      console.error("Upload failed:", error);
    }
  };

  return (
    <div>
      <input type="file" onChange={handleFileChange} />
      <button onClick={handleUpload}>Upload</button>
    </div>
  );
};

export default FileUpload;
```

📌 **Key Takeaways:**  
- **`input type="file"`** allows users to select files.  
- **`FormData`** is used to send files in an HTTP request.  
- **`fetch` API** sends a `POST` request to the backend.  

---

## **2. File Upload in Backend (Node.js + Express)**
The backend processes and stores the uploaded files.

### **Step 1: Install Required Packages**
```sh
npm install express multer cors
```
- **express** → Web framework for Node.js  
- **multer** → Middleware for handling file uploads  
- **cors** → Enables cross-origin requests  

### **Step 2: Create an Express Server**
```javascript
const express = require("express");
const multer = require("multer");
const cors = require("cors");
const path = require("path");

const app = express();
app.use(cors()); // Enable CORS

// Configure storage
const storage = multer.diskStorage({
  destination: "./uploads/",
  filename: (req, file, cb) => {
    cb(null, Date.now() + path.extname(file.originalname)); // Unique filename
  },
});

const upload = multer({ storage });

// Upload endpoint
app.post("/upload", upload.single("file"), (req, res) => {
  if (!req.file) return res.status(400).json({ message: "No file uploaded" });
  res.json({ message: "File uploaded successfully", filename: req.file.filename });
});

// Serve uploaded files
app.use("/uploads", express.static("uploads"));

app.listen(5000, () => console.log("Server running on port 5000"));
```

📌 **Key Takeaways:**  
- `multer.diskStorage` specifies where files are stored.  
- `upload.single("file")` handles a single file upload.  
- Files are stored in the `uploads/` directory.  
- Uploaded files are served via `http://localhost:5000/uploads/filename`.  

---

## **3. Handling Multiple File Uploads**
Modify the backend to accept multiple files.

### **Frontend (React)**
```jsx
const handleFileChange = (e) => {
  setFiles(e.target.files);
};

const handleUpload = async () => {
  const formData = new FormData();
  for (let file of files) {
    formData.append("files", file);
  }

  const response = await fetch("http://localhost:5000/upload-multiple", {
    method: "POST",
    body: formData,
  });

  const result = await response.json();
  alert(result.message);
};
```

### **Backend (Express)**
```javascript
app.post("/upload-multiple", upload.array("files", 5), (req, res) => {
  if (!req.files || req.files.length === 0) {
    return res.status(400).json({ message: "No files uploaded" });
  }
  res.json({ message: "Files uploaded successfully", files: req.files });
});
```

📌 **Key Takeaways:**  
- Use `upload.array("files", maxFiles)` for multiple files.  
- The frontend loops through selected files and appends them to `FormData`.  

---

## **4. File Validation (Size & Type)**
To **prevent malicious uploads**, enforce file type and size restrictions.

### **Multer File Validation**
```javascript
const fileFilter = (req, file, cb) => {
  const allowedTypes = ["image/jpeg", "image/png", "application/pdf"];
  if (!allowedTypes.includes(file.mimetype)) {
    return cb(new Error("Invalid file type"), false);
  }
  cb(null, true);
};

const upload = multer({
  storage,
  fileFilter,
  limits: { fileSize: 5 * 1024 * 1024 }, // 5MB limit
});
```

📌 **Security Best Practices:**  
✅ **Restrict file types** to avoid harmful scripts.  
✅ **Limit file size** to prevent large uploads.  
✅ **Scan uploaded files** using antivirus tools like `ClamAV`.  

---

## **5. Uploading Files to Cloud Storage**
Instead of local storage, upload files to cloud storage like **Amazon S3, Google Cloud Storage, or Firebase**.

### **Uploading to AWS S3 (Example)**
```sh
npm install aws-sdk multer-s3
```

#### **Backend Code (AWS S3)**
```javascript
const AWS = require("aws-sdk");
const multerS3 = require("multer-s3");

AWS.config.update({
  accessKeyId: "YOUR_ACCESS_KEY",
  secretAccessKey: "YOUR_SECRET_KEY",
  region: "us-east-1",
});

const s3 = new AWS.S3();

const upload = multer({
  storage: multerS3({
    s3,
    bucket: "your-bucket-name",
    acl: "public-read",
    key: (req, file, cb) => {
      cb(null, Date.now() + "-" + file.originalname);
    },
  }),
});

app.post("/upload", upload.single("file"), (req, res) => {
  res.json({ message: "File uploaded", fileUrl: req.file.location });
});
```

📌 **Benefits of Cloud Storage:**  
✅ **Scalability** – No need to manage file servers.  
✅ **Global Availability** – Faster access from different locations.  
✅ **Security** – Built-in access controls.  

---

## **6. Secure File Downloads**
To prevent unauthorized downloads, generate **signed URLs**.

### **AWS S3 Presigned URL (Download)**
```javascript
const getSignedUrl = (fileKey) => {
  const params = { Bucket: "your-bucket-name", Key: fileKey, Expires: 60 };
  return s3.getSignedUrl("getObject", params);
};

app.get("/download/:fileKey", (req, res) => {
  const fileKey = req.params.fileKey;
  const url = getSignedUrl(fileKey);
  res.json({ downloadUrl: url });
});
```

📌 **Benefits of Signed URLs:**  
✅ Prevents unauthorized downloads.  
✅ URL expires after a set time.  
✅ Works well for temporary access.  

---

## **Conclusion**
- Use **Multer** for handling file uploads in Express.  
- Store files securely in **cloud storage (S3, Firebase, GCP)** for scalability.  
- Implement **validation** to restrict file types and sizes.  
- Use **signed URLs** for secure downloads.  
