To add **CSS files** in Django, follow these steps to include and use them in your templates. CSS files are used to style the pages and elements in your web application.

### Steps to Add CSS Files in Django

#### 1. **Set Up Static Files (if not done already)**

First, make sure your Django project is set up to handle static files. Static files include CSS, JavaScript, images, etc. You should define the necessary settings in the `settings.py` file.

**In `settings.py`**:

```python
# settings.py

# URL to serve static files (used in templates)
STATIC_URL = '/static/'

# Static directories where Django will search for static files
STATICFILES_DIRS = [
    BASE_DIR / 'static',  # Add your global static folder (where you keep CSS files)
]

# Directory to collect static files during production
STATIC_ROOT = BASE_DIR / 'staticfiles'
```

#### 2. **Create a Static Directory**

Create a `static` folder within your Django app (or in the project directory) to store your CSS files. The directory structure typically looks like this:

```bash
my_project/
│
├── my_app/
│   └── static/
│       └── my_app/
│           └── css/
│               └── styles.css  # Your CSS file
│
├── manage.py
└── settings.py
```

In this structure:
- `my_app/static/my_app/css/styles.css` is the location where you will store your CSS file.
- You can have multiple folders inside `static/`, like `css/`, `js/`, and `images/`, for better organization.

#### 3. **Use `{% static %}` Tag in Templates**

In Django templates, you need to load static files (like CSS) using the `{% static %}` template tag. Before using static files, you need to load the static files library.

1. **Load static tag**: At the top of your HTML template, load the `static` library.
2. **Include the CSS**: Use `{% static 'path/to/file' %}` to link the CSS file.

##### Example:

Here’s an example of how to add the CSS file to your template.

```html
<!-- template.html -->
{% load static %}

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Django App</title>
    
    <!-- Link to your CSS file -->
    <link rel="stylesheet" href="{% static 'my_app/css/styles.css' %}">
</head>
<body>
    <h1>Welcome to My Django App</h1>
    <p>This is a sample page styled with a CSS file.</p>
</body>
</html>
```

In this example:
- `{% static 'my_app/css/styles.css' %}` generates the correct URL for the `styles.css` file located in `my_app/static/my_app/css/`.

#### 4. **Using CSS for Styling**

Once you've linked the CSS file in your template, you can add the necessary CSS rules to style your HTML elements.

##### Example `styles.css`:

```css
/* styles.css */
body {
    font-family: Arial, sans-serif;
    background-color: #f0f0f0;
}

h1 {
    color: #333;
    text-align: center;
}

p {
    font-size: 16px;
    color: #666;
}
```

#### 5. **Serve Static Files in Development**

During development, Django automatically serves static files from your app’s `static` folder. However, make sure you have the `django.contrib.staticfiles` app included in your `INSTALLED_APPS`:

```python
# settings.py
INSTALLED_APPS = [
    'django.contrib.staticfiles',
    # Other apps...
]
```

You don't need to do anything special for Django to serve static files during development. Just run the Django development server:

```bash
python manage.py runserver
```

Now you can visit your page in the browser, and the styles defined in `styles.css` will be applied.

#### 6. **Collect Static Files for Production**

In production, you need to collect all static files into a single directory, which is done using the `collectstatic` command.

First, ensure you’ve configured the `STATIC_ROOT` in `settings.py` (as mentioned earlier). Then, run the following command to collect all static files into the `STATIC_ROOT` directory:

```bash
python manage.py collectstatic
```

This command will gather all static files from your app's `static` folders and place them in the `STATIC_ROOT` directory (e.g., `staticfiles/`).

In production, you should configure your web server (e.g., Nginx or Apache) to serve static files from this directory (`staticfiles/`).

### Summary of Steps:

1. **Define Static Files Settings**: Ensure `STATIC_URL`, `STATICFILES_DIRS`, and `STATIC_ROOT` are properly set in `settings.py`.
2. **Create a Static Directory**: Create a `static/` directory in your app and organize files like `css/`, `js/`, and `images/`.
3. **Use `{% static %}` in Templates**: Load and reference your CSS file using the `{% static 'path/to/css/file' %}` tag.
4. **Use CSS for Styling**: Add CSS rules in your `.css` files to style the elements in your HTML.
5. **Serve Static Files in Development**: Django will serve the static files automatically during development.
6. **Collect Static Files for Production**: Run `python manage.py collectstatic` to gather static files for production.
