# **Deploying Full-Stack Applications 🚀**

Deploying a full-stack application involves deploying both the **frontend (React)** and **backend (Node.js/Express)** to a production environment. In this guide, you'll learn how to deploy a full-stack app using **Heroku** (for both backend and frontend) and **Netlify** (for React frontend). You will also see how to handle environment variables and production settings.

---

## **1. Preparing for Deployment**

### **Step 1: Build Your React App for Production**
Before deploying, create an optimized production build of your React app using the following command:
```sh
npm run build
```
This creates a `build/` folder containing static files that can be served.

### **Step 2: Set Up the Backend for Production**
In your backend, ensure that:
- **Environment variables** are used for sensitive data (API keys, database credentials, etc.).
- The app listens on **`process.env.PORT`** to support Heroku’s dynamic port assignment.

Example of server listening on the dynamic port:
```javascript
const port = process.env.PORT || 5000;
app.listen(port, () => {
  console.log(`Server running on port ${port}`);
});
```

---

## **2. Deploying Backend (Node.js/Express) on Heroku**

### **Step 1: Install Heroku CLI**
Install the **Heroku CLI** if you haven't already:
```sh
npm install -g heroku
```

### **Step 2: Initialize Git and Create a Heroku App**
If your app isn't already in a Git repository, initialize one:
```sh
git init
git add .
git commit -m "Initial commit"
```
Create a new app on Heroku:
```sh
heroku create your-app-name
```

### **Step 3: Add a Procfile**
In the root directory of your backend, create a file named `Procfile` (no extension) and add the following line:
```
web: node server.js
```
This tells Heroku how to run your app.

### **Step 4: Deploy to Heroku**
Deploy the app to Heroku using the following commands:
```sh
git push heroku master
```
Heroku will build and deploy your app. Once deployed, you can access your app at `https://your-app-name.herokuapp.com`.

---

## **3. Deploying Frontend (React) on Netlify**

### **Step 1: Push Your React App to GitHub**
Ensure your React app is connected to a **GitHub repository**. If not, initialize a Git repository:
```sh
git init
git add .
git commit -m "Initial commit"
git remote add origin <your-github-repo-url>
git push -u origin master
```

### **Step 2: Create a Netlify Account**
Go to [Netlify](https://www.netlify.com/) and create an account or log in.

### **Step 3: Connect Your Repository to Netlify**
Once logged in:
1. Click **New Site from Git**.
2. Choose **GitHub** and authorize Netlify to access your repositories.
3. Select the repository containing your React app.

### **Step 4: Set Build Settings**
In the build settings, make sure the build command is `npm run build` and the publish directory is `build/`.

Click **Deploy Site**, and Netlify will build and deploy your React app. Once deployed, you will receive a live URL for your frontend.

---

## **4. Configure Backend API URL in React**

For production, update your React app to make requests to the correct backend URL.

### **Step 1: Set API URL Based on Environment**
Use **environment variables** to differentiate between development and production.

- **Create `.env` files** in both your React and Node.js apps.

**In React (`.env` for development):**
```env
REACT_APP_API_URL=http://localhost:5000
```

**In React (production environment):**
In production (Netlify), set the API URL to your backend's Heroku URL:
```env
REACT_APP_API_URL=https://your-backend-app.herokuapp.com
```

**In Node.js/Express (`.env`):**
Set environment variables for production:
```env
PORT=5000
DB_URI=your-database-url
SECRET_KEY=your-secret-key
```

### **Step 2: Use the Environment Variables in Your React App**
```javascript
const apiUrl = process.env.REACT_APP_API_URL;

axios.get(`${apiUrl}/api/data`)
  .then(response => console.log(response.data))
  .catch(error => console.error(error));
```
This ensures that your frontend uses the correct URL depending on the environment.

---

## **5. Managing Databases**

### **Using Heroku Postgres**
If your app needs a **database**, you can set up a **Heroku Postgres** database:

1. Add the Postgres addon to your Heroku app:
   ```sh
   heroku addons:create heroku-postgresql:hobby-dev
   ```

2. Get the database URL:
   ```sh
   heroku config:get DATABASE_URL
   ```

3. Use this URL in your **Node.js/Express app** to connect to the database.

### **Using MongoDB (MongoDB Atlas)**
If you're using MongoDB, you can host your database on **MongoDB Atlas**. Set the connection string as an environment variable in your Heroku app.

---

## **6. Continuous Deployment (Optional)**

For easier updates, set up **Continuous Deployment** with GitHub.

- **For Heroku**: Simply link your GitHub repository, and every time you push changes to the master branch, Heroku will automatically redeploy your app.
- **For Netlify**: Similarly, Netlify redeploys every time you push to your GitHub repository.

---

## **7. Monitoring and Logs**

### **Heroku Logs**
To view your app logs on Heroku:
```sh
heroku logs --tail
```

This is helpful for troubleshooting your app in production.

### **Netlify Analytics**
Netlify offers analytics for your React app to monitor performance and errors.

---

## **8. Conclusion**

🚀 **You’ve deployed your full-stack app!**
1. The **Node.js/Express backend** is hosted on **Heroku**.
2. The **React frontend** is hosted on **Netlify**.
3. Environment variables ensure your app works in both development and production.

**Scaling up?** You can also use services like **AWS**, **Google Cloud**, or **DigitalOcean** for more complex needs.
