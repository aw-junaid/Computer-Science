### PHP - Facebook Login Integration

Integrating Facebook Login into a PHP application allows users to log in using their Facebook account, which can simplify authentication and improve user experience. This integration can be done using the **Facebook SDK for PHP**.

Here's a step-by-step guide to integrating **Facebook Login** into a PHP application.

### 1. Set Up a Facebook App

To use Facebook Login, you need to create a Facebook App. Follow these steps:

1. Go to the [Facebook Developers](https://developers.facebook.com/) website.
2. Create a new App by going to **My Apps** > **Create App**.
3. Choose **For Everything Else** under the App type.
4. Set up the **App Name** and **Email** for the app.
5. After the app is created, go to **Facebook Login** and set up the product.
6. Set the **Redirect URI**: This is the URL that Facebook will redirect users to after they authenticate. For example: `http://yourdomain.com/fb-callback.php`.

### 2. Install Facebook SDK for PHP

The **Facebook SDK for PHP** provides tools to interact with the Facebook API. You can install it using **Composer**.

If you don't have Composer installed, first [install Composer](https://getcomposer.org/).

#### Install via Composer:

```bash
composer require facebook/graph-sdk
```

Alternatively, you can download the SDK from the [GitHub repository](https://github.com/facebookarchive/php-graph-sdk).

### 3. Create a Facebook Login Button

You need a **login button** to let users initiate the login process.

#### `login.php` (Login Button)

```php
<?php
require_once 'vendor/autoload.php';  // Load Facebook SDK

// Initialize Facebook SDK
$fb = new \Facebook\Facebook([
  'app_id' => 'YOUR_APP_ID', // Replace with your App ID
  'app_secret' => 'YOUR_APP_SECRET', // Replace with your App Secret
  'default_graph_version' => 'v12.0',
]);

// Define the redirect URL after login
$redirectUrl = 'http://yourdomain.com/fb-callback.php'; // Change to your callback URL

// Generate the login URL
$helper = $fb->getRedirectLoginHelper();
$permissions = ['email']; // Request email permission
$loginUrl = $helper->getLoginUrl($redirectUrl, $permissions);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Facebook Login</title>
</head>
<body>
    <h2>Login with Facebook</h2>
    <a href="<?php echo htmlspecialchars($loginUrl); ?>">Login with Facebook</a>
</body>
</html>
```

### 4. Create the Facebook Callback Script

After the user logs in with Facebook, they will be redirected to a callback URL (the `redirectUrl` you specified earlier). In this script, you will handle the login response.

#### `fb-callback.php`

```php
<?php
require_once 'vendor/autoload.php';  // Load Facebook SDK

// Initialize Facebook SDK
$fb = new \Facebook\Facebook([
  'app_id' => 'YOUR_APP_ID', // Replace with your App ID
  'app_secret' => 'YOUR_APP_SECRET', // Replace with your App Secret
  'default_graph_version' => 'v12.0',
]);

// Define the redirect URL after login
$helper = $fb->getRedirectLoginHelper();

try {
    // Get the access token from the login response
    $accessToken = $helper->getAccessToken();

    if (!isset($accessToken)) {
        // Handle error if no access token
        echo "Error: Unable to get access token.";
        exit;
    }

    // Set the access token to the session
    $_SESSION['fb_access_token'] = (string) $accessToken;

    // Get the user's profile information
    $response = $fb->get('/me?fields=id,name,email', $accessToken);
    $user = $response->getGraphUser();

    echo 'Logged in as: ' . $user['name'] . '<br>';
    echo 'Email: ' . $user['email'] . '<br>';

    // Redirect to a protected page after successful login
    header('Location: welcome.php');
    exit;

} catch(Facebook\Exceptions\FacebookResponseException $e) {
    // Handle Facebook API error
    echo 'Error: ' . $e->getMessage();
    exit;
} catch(Facebook\Exceptions\FacebookSDKException $e) {
    // Handle SDK error
    echo 'Error: ' . $e->getMessage();
    exit;
}
?>
```

### 5. Display the User’s Information on a Protected Page

Once the user is logged in, you can show their information on a protected page.

#### `welcome.php`

```php
<?php
session_start();

require_once 'vendor/autoload.php';  // Load Facebook SDK

// Initialize Facebook SDK
$fb = new \Facebook\Facebook([
  'app_id' => 'YOUR_APP_ID', // Replace with your App ID
  'app_secret' => 'YOUR_APP_SECRET', // Replace with your App Secret
  'default_graph_version' => 'v12.0',
]);

if (isset($_SESSION['fb_access_token'])) {
    $accessToken = $_SESSION['fb_access_token'];

    try {
        // Get the user's profile information
        $response = $fb->get('/me?fields=id,name,email', $accessToken);
        $user = $response->getGraphUser();

        echo 'Welcome, ' . $user['name'] . '<br>';
        echo 'Your email: ' . $user['email'] . '<br>';

    } catch(Facebook\Exceptions\FacebookResponseException $e) {
        // Handle Facebook API error
        echo 'Error: ' . $e->getMessage();
        exit;
    } catch(Facebook\Exceptions\FacebookSDKException $e) {
        // Handle SDK error
        echo 'Error: ' . $e->getMessage();
        exit;
    }
} else {
    echo 'You are not logged in.';
}
?>
```

### 6. Logout User

To log the user out, simply clear the session and redirect them.

#### `logout.php`

```php
<?php
session_start();
unset($_SESSION['fb_access_token']);  // Remove the access token from session

// Redirect to login page
header('Location: login.php');
exit;
?>
```

### 7. Handling Facebook Login with Session

Make sure you start the session at the top of each PHP file that handles login or access token storage.

```php
session_start();
```

### 8. Important Notes:

- **Facebook App ID and Secret**: Replace `YOUR_APP_ID` and `YOUR_APP_SECRET` with the actual values from the Facebook Developer console.
- **Permissions**: The example requests the `email` permission to retrieve the user's email. You can request other permissions depending on your needs (e.g., `public_profile`, `user_friends`, etc.).
- **Redirect URI**: The redirect URI must match exactly the one you set in the Facebook Developer console.
- **Secure the session**: In production, ensure your session handling is secure (e.g., using HTTPS).

### Conclusion:

This basic example shows how to integrate Facebook login into a PHP application. It includes registering an app, installing the SDK, creating a login button, handling the callback, and displaying user details. You can extend this by saving user information in a database, creating sessions, and customizing the login experience.
