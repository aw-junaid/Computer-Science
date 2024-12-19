Django’s **Template System** is a powerful tool for separating the presentation logic (HTML, CSS) from the business logic (Python code) of your application. Templates allow you to create dynamic HTML pages that can display data from your views and can be easily customized for different outputs.

The Django Template System is designed to be simple, flexible, and highly extensible. It allows you to embed dynamic data into HTML documents using placeholders and logic.

### Key Concepts of Django Template System:

1. **Template Tags**
2. **Template Filters**
3. **Template Variables**
4. **Inheritance**
5. **Static Files**

Let’s dive deeper into each of these.

---

### 1. **Template Tags**

Template tags are used to control the logic inside templates. They are enclosed in `{% %}`.

#### Example: Displaying Content with Tags

```html
{% if user.is_authenticated %}
    <p>Welcome back, {{ user.username }}!</p>
{% else %}
    <p>Please log in.</p>
{% endif %}
```

Some common template tags include:
- **`{% if %}`** and **`{% endif %}`**: Used for conditional logic.
- **`{% for %}`** and **`{% endfor %}`**: Used to loop through data.
- **`{% include %}`**: Used to include other templates.
- **`{% block %}`** and **`{% endblock %}`**: Used for template inheritance (explained later).

#### Example: Looping through a list

```html
<ul>
    {% for post in posts %}
        <li>{{ post.title }}</li>
    {% endfor %}
</ul>
```

### 2. **Template Filters**

Template filters are used to modify the display of variables in templates. They are applied using the pipe (`|`) symbol.

#### Example: Using Filters

```html
<p>The current date is: {{ current_date|date:"Y-m-d" }}</p>
```

Some useful filters:
- **`date`**: Formats a date or datetime object.
- **`lower`**: Converts a string to lowercase.
- **`length`**: Returns the length of a list or string.
- **`default`**: Provides a default value if the variable is empty or undefined.

#### Example: Using Default Filter

```html
<p>{{ user.username|default:"Guest" }}</p>
```

If `user.username` is empty, it will display "Guest".

---

### 3. **Template Variables**

Template variables are placeholders that allow you to inject dynamic content into your templates. They are enclosed in double curly braces (`{{ }}`).

#### Example: Using Variables in Templates

```html
<h1>{{ page_title }}</h1>
<p>{{ content }}</p>
```

Here, `page_title` and `content` are variables passed from the view to the template.

In your view:

```python
from django.shortcuts import render

def index(request):
    context = {'page_title': 'Home Page', 'content': 'Welcome to our website!'}
    return render(request, 'index.html', context)
```

The template will then render:
```html
<h1>Home Page</h1>
<p>Welcome to our website!</p>
```

---

### 4. **Template Inheritance**

Template inheritance allows you to create a base template with common elements (like a header, footer, and navigation), and then extend it in other templates to avoid repetition.

#### Example: Base Template

Create a `base.html` file with common elements:

```html
<!-- base.html -->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>{% block title %}My Website{% endblock %}</title>
</head>
<body>
    <header>
        <h1>My Website</h1>
        <nav>
            <a href="/">Home</a> | <a href="/about/">About</a>
        </nav>
    </header>
    <main>
        {% block content %}
        {% endblock %}
    </main>
    <footer>
        <p>Copyright © 2024</p>
    </footer>
</body>
</html>
```

#### Example: Extending the Base Template

In other templates, you can extend `base.html` and override blocks like `title` and `content`:

```html
<!-- index.html -->
{% extends 'base.html' %}

{% block title %}Home Page{% endblock %}

{% block content %}
    <h2>Welcome to the homepage!</h2>
    <p>This is some dynamic content.</p>
{% endblock %}
```

This will render the content of `index.html` inside the `base.html` structure, with `title` and `content` being replaced.

---

### 5. **Static Files**

Django’s template system also allows you to link static files like CSS, JavaScript, and images. These are not served dynamically like templates but are served as-is.

#### Example: Using Static Files in Templates

1. First, make sure you have set up a `static` directory in your app or project and added it to your settings.

In your `settings.py`:
```python
STATIC_URL = '/static/'
```

2. Use the `{% static %}` tag in your templates to link to static files:

```html
<!-- index.html -->
{% load static %}  <!-- Load the static files tag library -->

<link rel="stylesheet" href="{% static 'css/style.css' %}">
<img src="{% static 'images/logo.png' %}" alt="Logo">
```

The `{% load static %}` tag must be included at the top of the template to enable the static file handling.

---

### 6. **Custom Template Tags and Filters**

You can also define your own custom template tags and filters. This allows you to add more complex functionality to your templates.

#### Example: Custom Template Filter

1. Create a custom filter in a `templatetags` directory inside your app.

```python
# myapp/templatetags/custom_filters.py
from django import template

register = template.Library()

@register.filter
def reverse_string(value):
    return value[::-1]
```

2. In your template, use the custom filter:

```html
{% load custom_filters %}

<p>{{ "hello"|reverse_string }}</p>  <!-- Output: "olleh" -->
```

---

### Summary of Django Template System:

1. **Template Variables**: Used to insert dynamic content into templates (e.g., `{{ variable }}`).
2. **Template Tags**: Provide logic for controlling templates (e.g., `{% if %}`, `{% for %}`, `{% block %}`).
3. **Template Filters**: Modify the display of variables (e.g., `{{ variable|filter }}`).
4. **Template Inheritance**: Allows you to reuse common layout structures across multiple templates using `{% extends %}` and `{% block %}`.
5. **Static Files**: Link static content (CSS, JavaScript, images) to templates using `{% static %}`.
6. **Custom Template Tags/Filters**: Create your own tags and filters to extend the template system.

By using Django’s template system, you can easily separate your HTML structure from the logic and data, making your web application easier to maintain and scale.
