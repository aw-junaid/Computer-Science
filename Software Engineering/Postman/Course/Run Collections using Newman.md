### **Postman - Run Collections Using Newman**

Newman allows you to run **Postman collections** from the command line, making it an ideal tool for automating API tests and integrating them into CI/CD pipelines. You can execute the same Postman collections that you have in the Postman app, but using Newman to run them in different environments or as part of an automated workflow.

Here's a step-by-step guide on how to run Postman collections using Newman:

---

### **1. Install Newman**

Before you can run collections using Newman, you need to install it. Newman is a Node.js package, so you must have Node.js installed.

#### **Installation Steps:**
1. **Install Node.js and npm** (if not installed already):
   - Download and install from [Node.js website](https://nodejs.org/).
   - Verify installation by running:
     ```bash
     node -v
     npm -v
     ```

2. **Install Newman** globally using npm:
   ```bash
   npm install -g newman
   ```

3. **Verify Newman Installation**:
   After installation, check the version of Newman to ensure it was installed correctly:
   ```bash
   newman -v
   ```

---

### **2. Export Postman Collection and Environment**

To use Newman, you need to export your Postman collection and, if necessary, the environment file.

#### **Exporting a Collection:**
1. In the Postman app, click on the **three dots** next to your collection.
2. Select **Export**.
3. Choose the collection format (`v2.1` is recommended).
4. Save the `.json` file (e.g., `my-collection.json`).

#### **Exporting an Environment (Optional):**
If your collection uses variables that are specific to a certain environment (e.g., `dev`, `prod`), export your environment:
1. Go to the **Manage Environments** section in Postman.
2. Select the environment you want to export.
3. Click **Export** and save the `.json` file (e.g., `my-environment.json`).

---

### **3. Running Collections Using Newman**

Once Newman is installed and you have the exported Postman collection and environment files, you can run the collection from the command line.

#### **Basic Command to Run a Collection**:
```bash
newman run <path-to-collection-file>
```

Example:
```bash
newman run my-collection.json
```

This command will run the collection and display the results in your terminal.

---

### **4. Running with Environment Variables**

If your Postman collection uses environment variables, you can pass the environment file to Newman to ensure that the appropriate variables are used during the test run.

#### **Command to Run a Collection with Environment Variables**:
```bash
newman run <path-to-collection-file> -e <path-to-environment-file>
```

Example:
```bash
newman run my-collection.json -e my-environment.json
```

In this case, `my-environment.json` contains the environment variables that will be used for the test.

---

### **5. Data-Driven Testing with Newman**

Newman allows you to run tests with multiple sets of input data, making it possible to execute parameterized tests. You can use data files in CSV or JSON formats to run your collection multiple times with different data sets.

#### **Using CSV File for Data-Driven Testing**:
```bash
newman run <path-to-collection-file> -d <path-to-data-file.csv>
```

Example:
```bash
newman run my-collection.json -d data.csv
```

#### **Using JSON File for Data-Driven Testing**:
```bash
newman run <path-to-collection-file> -d <path-to-data-file.json>
```

Example:
```bash
newman run my-collection.json -d data.json
```

Each entry in the CSV or JSON file will be used to execute the requests in the collection, substituting the variables in the requests as needed.

---

### **6. Generating Reports in Newman**

Newman supports generating reports that you can use to view the results of your test execution. You can generate reports in various formats, such as HTML, JSON, or JUnit, using the `-r` flag.

#### **Generate HTML Report**:
```bash
newman run <path-to-collection-file> -r html
```

#### **Generate JSON Report**:
```bash
newman run <path-to-collection-file> -r json
```

#### **Generate Multiple Report Formats**:
You can generate multiple reports at once by specifying more than one format with the `-r` flag.
```bash
newman run <path-to-collection-file> -r html,json
```

#### **Save the Report to a File**:
You can save the report to a specific file using the `--reporter-html-export` or `--reporter-json-export` flag.
```bash
newman run my-collection.json -r html --reporter-html-export result.html
```

This will generate an HTML report and save it as `result.html`.

---

### **7. Running Specific Requests or Folders**

If your collection has multiple folders or requests and you want to run only a specific one, you can use the `--folder` option.

#### **Running a Specific Folder**:
```bash
newman run <path-to-collection-file> --folder <folder-name>
```

Example:
```bash
newman run my-collection.json --folder "Login Tests"
```

#### **Running a Specific Request**:
To run a specific request, you can also use the `--request` option, though this is less common and requires the request name to be specified.

---

### **8. Handling Authentication and Authorization**

If your collection requires authentication (e.g., using tokens or API keys), you can pass these details either through environment variables or directly in the request headers.

#### **Using Environment Variables for Auth Tokens**:
1. Set an authentication token or key as an environment variable:
   ```bash
   newman run my-collection.json -e my-environment.json
   ```

2. Use the environment variable in your requests (e.g., in the Authorization header):
   ```plaintext
   Authorization: Bearer {{auth_token}}
   ```

Alternatively, you can directly pass the authorization headers via Newman command-line arguments:
```bash
newman run my-collection.json --header "Authorization: Bearer <your-auth-token>"
```

---

### **9. Running Newman in CI/CD Pipelines**

Newman is frequently used in Continuous Integration (CI) systems like Jenkins, GitLab CI, or CircleCI to run API tests as part of automated build processes.

#### **Example: Running Newman in a Jenkins Pipeline**

In your Jenkins pipeline configuration (`Jenkinsfile`), you can add a stage that runs your Postman collection using Newman:
```groovy
pipeline {
    agent any
    stages {
        stage('Run API Tests') {
            steps {
                script {
                    sh 'newman run my-collection.json -e my-environment.json -r html --reporter-html-export result.html'
                }
            }
        }
    }
}
```

This will run the collection and generate an HTML report as part of your CI pipeline.

---

### **10. Advanced Options for Newman**

- **Timeouts**: You can set timeouts for requests using `--timeout` and `--timeout-request`.
  ```bash
  newman run my-collection.json --timeout 30000
  ```

- **Skip SSL Verification**: If you're testing an API with an invalid SSL certificate, you can disable SSL verification with `--insecure`.
  ```bash
  newman run my-collection.json --insecure
  ```

- **Custom Scripts**: You can include custom **Pre-request scripts** and **Tests** within the Postman collection, and these will be executed by Newman in the same way.

---

### **Conclusion**

Running collections using Newman is a powerful way to automate your API tests, especially for integration with CI/CD pipelines. Newman allows you to execute your Postman collections from the command line, manage environment variables, handle data-driven testing, and generate detailed reports. By integrating Newman into your development and deployment processes, you can ensure that your APIs are consistently tested and meet the necessary quality standards.

Key benefits:
- Run Postman collections from the command line
- Integrate API tests into CI/CD pipelines
- Generate reports for test execution
- Support for environment variables and data-driven testing
