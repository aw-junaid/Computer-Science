### **Postman - Newman Overview**

**Newman** is a command-line tool that allows you to run and test Postman collections from the terminal. It is an essential part of Postman’s ecosystem for automating API testing, integrating with Continuous Integration (CI) systems, and executing collections outside of the Postman GUI.

With **Newman**, you can run your Postman collections in environments where Postman’s graphical interface is not available, making it highly useful for automating API tests and integrating them into CI/CD pipelines.

### **Key Features of Newman**

1. **Command-Line Interface (CLI)**: Newman is executed from the terminal, enabling automation and integration into workflows, CI/CD pipelines, and scripting environments.
2. **Collection Runner**: You can execute Postman collections that have been exported into `.json` format, just like you would in the Postman app.
3. **Environment and Global Variables**: Newman supports environments and global variables, so you can run your tests in different contexts (like dev, staging, production) and manage dynamic data during the test run.
4. **Reports**: Newman supports generating various types of reports, including HTML, JSON, and JUnit reports, that allow you to review the results of your test execution.
5. **Integration with CI/CD**: Newman can be integrated with CI tools like Jenkins, Travis CI, CircleCI, GitLab CI, and more, making it easy to run Postman collections automatically as part of the build/test process.
6. **Data-Driven Testing**: Newman allows you to run tests with multiple sets of data (CSV, JSON), enabling you to automate tests with different input parameters.

---

### **How to Install Newman**

Newman is a Node.js package, and you can install it globally via npm (Node Package Manager) from the command line.

1. **Install Node.js and npm** (if you don’t have them already):
   - Download and install from [Node.js website](https://nodejs.org/).
   - Verify installation using:
     ```bash
     node -v
     npm -v
     ```

2. **Install Newman** globally:
   ```bash
   npm install -g newman
   ```

3. **Verify the installation**:
   ```bash
   newman -v
   ```

---

### **Basic Usage of Newman**

Once Newman is installed, you can run a Postman collection with the following basic command:

```bash
newman run <path-to-collection-file>
```

Where `<path-to-collection-file>` is the path to the exported Postman collection file in `.json` format.

#### **Example**:
```bash
newman run my-collection.json
```

This command will execute the requests defined in `my-collection.json` and display the results in the terminal.

---

### **Running Postman Collections with Environments**

If your collection uses environment variables, you can specify the environment file during the Newman run using the `-e` flag:

```bash
newman run my-collection.json -e my-environment.json
```

Where `my-environment.json` is the environment file containing the variables used in the collection.

---

### **Running with Data Files (CSV or JSON)**

Newman also supports data-driven testing, where you can run a collection with different sets of input data. This is useful for parameterized testing.

1. **CSV File**:
   Newman allows you to pass a CSV file to use as data for running requests.
   ```bash
   newman run my-collection.json -d data.csv
   ```

2. **JSON File**:
   You can also use JSON data files with Newman.
   ```bash
   newman run my-collection.json -d data.json
   ```

Each row in the CSV or each object in the JSON will be used as a separate test iteration, with the data replaced in the request body or parameters.

---

### **Generating Reports in Newman**

Newman supports different types of reports that can help you analyze the test results. Some of the most common formats are:

1. **CLI Report**: The default output in the terminal.
2. **HTML Report**: You can generate a detailed HTML report using the `-r` flag.
   ```bash
   newman run my-collection.json -r html
   ```

3. **JUnit Report**: Useful for CI/CD integration, as it generates a report compatible with Jenkins, GitLab, and other CI tools.
   ```bash
   newman run my-collection.json -r junit
   ```

4. **Multiple Report Formats**:
   You can also generate multiple reports by specifying more than one reporter.
   ```bash
   newman run my-collection.json -r html,json
   ```

   This will generate both HTML and JSON reports.

---

### **Running Newman in CI/CD Pipelines**

One of the main use cases for Newman is to integrate it into CI/CD pipelines, automating your API tests as part of the build and deployment process.

#### **Example with Jenkins**:
1. Install Newman in your Jenkins environment, using npm or as part of the build script.
2. Add a build step that runs Newman:
   ```bash
   newman run my-collection.json -r html
   ```

   You can also configure Jenkins to archive the generated HTML or JUnit reports for easy viewing of results.

#### **Example with GitLab CI**:
In the `.gitlab-ci.yml` file, you can add a Newman job to run your tests:

```yaml
stages:
  - test

test_api:
  stage: test
  image: node:14
  script:
    - npm install -g newman
    - newman run my-collection.json -r html
```

This ensures that every time you push changes to GitLab, the Postman tests are automatically executed as part of the CI pipeline.

---

### **Advanced Features of Newman**

1. **Run Specific Requests in a Collection**:
   You can run a specific request from a collection by providing the `--folder` flag:
   ```bash
   newman run my-collection.json --folder "Login Tests"
   ```

2. **Global Variables**: You can define global variables in your Postman collection or environment and pass them to Newman:
   ```bash
   newman run my-collection.json -g global.json
   ```

3. **Skipping Tests**: You can skip a test by specifying `--skip-ssl` if your collection is using SSL certificates or encountering SSL verification issues.

4. **Custom Scripts and Hooks**: You can use **Pre-request scripts** and **Tests** in Postman, and these will work the same way when running collections in Newman. Additionally, Newman supports **hooks** for extending its functionality, such as logging or custom reporting.

5. **Handling Authentication**: You can pass authentication details such as API keys or tokens using environment or global variables, allowing you to test APIs that require authentication.

---

### **Conclusion**

Newman is a powerful tool for automating and running Postman collections from the command line. It enables continuous integration and testing of APIs by allowing developers to execute Postman collections in automated workflows. By integrating Newman into your CI/CD pipelines and utilizing its features, you can streamline your API testing process, ensure consistency, and improve efficiency.

Key benefits of using Newman:
- Automation of API tests
- Integration with CI/CD pipelines
- Support for data-driven testing
- Ability to generate reports in different formats
- Command-line flexibility for headless execution
