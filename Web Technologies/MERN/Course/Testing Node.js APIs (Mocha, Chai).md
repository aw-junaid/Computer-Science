# **Testing Node.js APIs with Mocha & Chai** 🧪

Testing APIs is essential to ensure they perform as expected and handle various edge cases. **Mocha** is a popular test framework for Node.js, and **Chai** is an assertion library commonly used with Mocha to verify the behavior of your API endpoints.

In this guide, we'll walk through how to set up **Mocha** and **Chai** to test Node.js APIs, as well as how to write and run tests.

---

## **1. Setting Up Mocha and Chai**

### **Step 1: Install Mocha and Chai**

First, install Mocha and Chai as development dependencies:

```bash
npm install --save-dev mocha chai supertest
```

- **Mocha**: A test framework that provides the testing environment.
- **Chai**: An assertion library that makes it easier to write tests with functions like `expect()`, `should()`, and `assert()`.
- **Supertest**: A library to test HTTP requests, which makes it easier to test your API endpoints.

### **Step 2: Project Structure**

Your project structure might look like this:

```
/my-app
  /node_modules
  /test
    api.test.js
  /src
    /routes
      userRoutes.js
    /controllers
      userController.js
  server.js
  package.json
```

- The `test` folder will contain your test files.
- The `src` folder contains the actual application code (routes, controllers, etc.).
- `server.js` is your main app entry point.

---

## **2. Writing Tests for Node.js APIs**

Let’s go step-by-step through writing tests for a simple API endpoint using **Mocha**, **Chai**, and **Supertest**.

### **Step 1: Create Your API Endpoints**

First, create a simple API for managing users.

#### **userController.js** (Controller)
```javascript
const users = [{ id: 1, name: 'John Doe' }];

const getUsers = (req, res) => {
  res.json(users);
};

const getUserById = (req, res) => {
  const user = users.find(u => u.id === parseInt(req.params.id));
  if (!user) return res.status(404).send('User not found');
  res.json(user);
};

module.exports = { getUsers, getUserById };
```

#### **userRoutes.js** (Routes)
```javascript
const express = require('express');
const { getUsers, getUserById } = require('../controllers/userController');
const router = express.Router();

router.get('/users', getUsers);
router.get('/users/:id', getUserById);

module.exports = router;
```

#### **server.js** (Main Server)
```javascript
const express = require('express');
const userRoutes = require('./src/routes/userRoutes');
const app = express();

app.use('/api', userRoutes);

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`);
});
```

Now, we have two API endpoints:
1. `GET /api/users` – Returns a list of users.
2. `GET /api/users/:id` – Returns a user by ID.

---

### **Step 2: Create Tests for API Endpoints**

Now, let’s write tests for these endpoints using **Mocha**, **Chai**, and **Supertest**.

#### **api.test.js** (Test File)
```javascript
const request = require('supertest');
const chai = require('chai');
const app = require('../server'); // Import your Express app
const expect = chai.expect;

describe('User API', () => {

  describe('GET /api/users', () => {
    it('should return a list of users', async () => {
      const res = await request(app).get('/api/users');

      // Check status code
      expect(res.status).to.equal(200);

      // Check the response body
      expect(res.body).to.be.an('array');
      expect(res.body.length).to.be.greaterThan(0);

      // Check if the first user has an id and name
      expect(res.body[0]).to.have.property('id');
      expect(res.body[0]).to.have.property('name');
    });
  });

  describe('GET /api/users/:id', () => {
    it('should return a user by ID', async () => {
      const res = await request(app).get('/api/users/1');

      // Check status code
      expect(res.status).to.equal(200);

      // Check the response body
      expect(res.body).to.have.property('id', 1);
      expect(res.body).to.have.property('name', 'John Doe');
    });

    it('should return 404 if user not found', async () => {
      const res = await request(app).get('/api/users/999');

      // Check status code
      expect(res.status).to.equal(404);

      // Check the response body
      expect(res.text).to.equal('User not found');
    });
  });

});
```

- **`describe`**: Group related tests.
- **`it`**: Define individual test cases.
- **`expect`**: Use Chai’s assertion library to make assertions about the response.

#### **Test Breakdown:**
1. **GET /api/users**
   - Sends a `GET` request to the `/api/users` endpoint.
   - Asserts that the response status is 200.
   - Asserts that the response body is an array and contains at least one user object.
   - Checks that the user object contains both `id` and `name` properties.

2. **GET /api/users/:id**
   - Sends a `GET` request to `/api/users/1` and checks if the response contains the correct user.
   - Tests the case where the user does not exist by sending a `GET` request to `/api/users/999` and asserting a 404 status code.

---

### **Step 3: Running the Tests**

Make sure your server is not already running, as Mocha will run tests in a new instance.

#### **Run the tests with Mocha:**
```bash
npx mocha --timeout 5000 --exit
```

- **`--timeout 5000`**: Increases the test timeout to 5 seconds.
- **`--exit`**: Forces Mocha to exit after tests complete.

You should see output indicating whether the tests passed or failed.

---

## **3. Mocking Data for Tests**

In some cases, you may want to mock external data or databases, especially for testing in isolation.

### **Mocking with Sinon**

You can use **Sinon** to mock database calls, external APIs, or other asynchronous operations in your tests.

Example: Mocking a database call to return a mock user:

```bash
npm install --save-dev sinon
```

```javascript
const sinon = require('sinon');
const { expect } = require('chai');
const { getUserById } = require('../controllers/userController');
const User = require('../models/user'); // Suppose this is your model

describe('getUserById', () => {
  it('should return user with correct ID', async () => {
    const fakeUser = { id: 1, name: 'John Doe' };
    const findOneStub = sinon.stub(User, 'findOne').returns(Promise.resolve(fakeUser));

    const req = { params: { id: 1 } };
    const res = { json: sinon.spy() };

    await getUserById(req, res);

    expect(findOneStub.calledOnce).to.be.true;
    expect(res.json.calledWith(fakeUser)).to.be.true;

    findOneStub.restore(); // Restore original function
  });
});
```

---

## **4. Running Tests in a CI/CD Pipeline**

To run your tests automatically in a CI/CD pipeline (e.g., GitHub Actions, CircleCI, etc.), you can add a **test script** to your `package.json` file:

```json
"scripts": {
  "test": "mocha --timeout 5000 --exit"
}
```

Then, run the tests with:

```bash
npm test
```

This will execute the tests during your CI/CD build process.

---

## **5. Conclusion**

With **Mocha**, **Chai**, and **Supertest**, you can efficiently test your Node.js API endpoints to ensure they work as expected. Here's a recap:

- **Mocha**: A test framework that structures and runs your tests.
- **Chai**: An assertion library that allows you to make powerful assertions on your responses.
- **Supertest**: A library to simulate HTTP requests to your API and check the responses.

By writing unit and integration tests, you can catch bugs early, improve the stability of your application, and increase confidence in your codebase.
