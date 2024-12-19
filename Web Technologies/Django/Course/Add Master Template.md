In Django, a **Master Template** is a base template that provides a common structure (e.g., header, footer, navigation) for all pages of your website. The master template serves as a foundation that other templates can extend. By using template inheritance, you can define a shared layout and avoid code duplication across different pages.

### Steps to Add a Master Template in Django

1. **Create the Master Template (Base Template)**
2. **Extend the Master Template in Other Templates**
3. **Add Dynamic Content to Pages**

### 1. Create the Master Template (Base Template)

The master template defines the overall structure of your website, including elements that are shared across all pages, like the header, footer, and navigation. This template will also have **block tags** that child templates can override.

#### Example: `base.html`

Create a file called `base.html` in the `templates` folder of your Django app or project.

```html
<!-- templates/base.html -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>{% block title %}My Django Website{% endblock %}</title>
    <!-- Link to static CSS files (if needed) -->
    <link rel="stylesheet" href="{% static 'css/styles.css' %}">
</head>
<body>
    <!-- Header section -->
    <header>
        <h1>Welcome to My Django Website</h1>
        <nav>
            <ul>
                <li><a href="/">Home</a></li>
                <li><a href="/about/">About</a></li>
                <li><a href="/contact/">Contact</a></li>
            </ul>
        </nav>
    </header>

    <!-- Main content section -->
    <main>
        {% block content %}
        <!-- Child templates can insert their content here -->
        {% endblock %}
    </main>

    <!-- Footer section -->
    <footer>
        <p>&copy; 2024 My Django Website</p>
    </footer>
</body>
</html>
```

In this `base.html` template:
- **`{% block title %}`** allows child templates to change the title of the page.
- **`{% block content %}`** is a placeholder where child templates will insert their specific content.

### 2. Extend the Master Template in Other Templates

Once you have the master template, other templates can **extend** it and only override the parts of the page that change (e.g., the title and content).

#### Example: `index.html`

Create another template, such as `index.html`, in the `templates` folder of your Django app. This template will inherit the structure of the `base.html` template.

```html
<!-- templates/index.html -->
{% extends 'base.html' %}

{% block title %}Home - My Django Website{% endblock %}

{% block content %}
    <h2>Welcome to the Homepage</h2>
    <p>This is the main page of the website.</p>
{% endblock %}
```

Here:
- `{% extends 'base.html' %}` tells Django that this template should inherit from `base.html`.
- The `{% block title %}` overrides the `title` block defined in the base template.
- The `{% block content %}` overrides the `content` block to define the unique content for this page.

### 3. Add Dynamic Content to Pages

You can also pass dynamic content from the views to your templates. For example, in your `views.py`, you can pass data to the `index.html` template.

#### Example: View for the Index Page

```python
# views.py
from django.shortcuts import render

def index(request):
    context = {'message': 'Welcome to our homepage!'}
    return render(request, 'index.html', context)
```

In `index.html`, you can use the context data as follows:

```html
<!-- templates/index.html -->
{% extends 'base.html' %}

{% block title %}Home - My Django Website{% endblock %}

{% block content %}
    <h2>Welcome to the Homepage</h2>
    <p>{{ message }}</p>  <!-- Displaying dynamic content -->
{% endblock %}
```

Now, the `message` variable passed from the view will be displayed in the `content` block of the page.

### 4. URL Configuration

Make sure to map the view to a URL in your `urls.py` file.

```python
# urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),  # Mapping the index view to the homepage
]
```

### 5. Static Files (CSS, JavaScript, Images)

If you want to include static files like CSS, JavaScript, or images in your master template, make sure you load static files correctly using `{% load static %}`.

#### Example: Including Static Files in `base.html`

```html
<!-- base.html -->
{% load static %}  <!-- Load static files tag library -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>{% block title %}My Django Website{% endblock %}</title>
    <link rel="stylesheet" href="{% static 'css/styles.css' %}">  <!-- Static CSS -->
</head>
<body>
    <header>
        <h1>Welcome to My Django Website</h1>
    </header>
    <main>
        {% block content %}
        {% endblock %}
    </main>
    <footer>
        <p>&copy; 2024 My Django Website</p>
    </footer>
</body>
</html>
```

Make sure you have the `STATIC_URL` setting in `settings.py` configured:

```python
# settings.py
STATIC_URL = '/static/'
```

And place your static files (e.g., `styles.css`) in the appropriate `static` directory.

---

### Summary

To add a master template in Django:

1. **Create a base template** (`base.html`) with shared structure (header, footer, etc.) and placeholders for dynamic content (`{% block %}`).
2. **Extend the base template** in other templates (e.g., `index.html`) and override the content where needed using `{% block %}`.
3. **Pass dynamic content** from views to templates using context data.
4. **Include static files** (CSS, JS) in the base template using `{% static %}`.

By using this approach, you ensure that your website maintains a consistent layout across pages, and you can easily modify the layout without duplicating code.
