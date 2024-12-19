In Django, **page redirection** is commonly used to redirect a user from one URL to another. This can be done using several methods, and it's a useful feature for various purposes, such as redirecting users after a form submission, sending them to a login page, or simply redirecting them to another part of the site.

### Types of Redirections in Django

1. **`HttpResponseRedirect`** - Redirect to a different URL.
2. **`redirect()` function** - A shortcut to handle both named URL redirection and absolute URL redirection.
3. **`reverse()` function** - Used in conjunction with `redirect()` to dynamically generate URLs for views.

### 1. **Using `HttpResponseRedirect`**

`HttpResponseRedirect` is a class-based response that redirects the user to the provided URL. You typically use this when you want to redirect after some logic, such as after a form submission or a successful action.

#### Example:

```python
from django.http import HttpResponseRedirect
from django.urls import reverse

def my_view(request):
    # Logic here (e.g., after form submission)
    
    # Redirect to another view
    return HttpResponseRedirect('/new-url/')  # Replace '/new-url/' with the desired URL
```

You can also use `reverse()` to dynamically generate the URL for a named view:

```python
from django.http import HttpResponseRedirect
from django.urls import reverse

def my_view(request):
    # After some logic, redirect to a named URL pattern
    return HttpResponseRedirect(reverse('home'))  # 'home' is a named URL pattern
```

### 2. **Using the `redirect()` Shortcut**

The `redirect()` function is a more convenient way to handle redirects. It can redirect to:
- A URL (absolute or relative).
- A view name (Django will resolve it using `reverse()`).
- An object (e.g., a model instance) that implements `get_absolute_url()`.

#### Example 1: Redirect to a URL
```python
from django.shortcuts import redirect

def my_view(request):
    # Redirect to a specific URL
    return redirect('/new-url/')  # Redirect to an absolute URL
```

#### Example 2: Redirect to a Named View
```python
from django.shortcuts import redirect

def my_view(request):
    # Redirect to a view using its URL name
    return redirect('home')  # 'home' is a named URL pattern in urls.py
```

#### Example 3: Redirect with Arguments
If your URL pattern requires arguments, you can pass them to `redirect()` as follows:

```python
from django.shortcuts import redirect

def my_view(request):
    post_id = 1
    # Redirect to a view with a parameter
    return redirect('post_detail', id=post_id)  # 'post_detail' is a named URL pattern
```

#### Example 4: Redirect to a Model's `get_absolute_url`
If you have a model that implements the `get_absolute_url()` method, you can redirect to its detail page using this method.

```python
from django.shortcuts import redirect
from .models import Post

def my_view(request):
    post = Post.objects.get(id=1)
    return redirect(post)  # This will use the model's get_absolute_url method
```

### 3. **Using `reverse()` for Dynamic URL Generation**

You can use `reverse()` to dynamically generate a URL based on a view's name or pattern. This is useful when you need to build URLs in your views or templates programmatically.

#### Example:

```python
from django.urls import reverse
from django.http import HttpResponseRedirect

def my_view(request):
    # Generate a URL for a named view
    url = reverse('post_detail', args=[1])  # 'post_detail' is a named URL pattern
    return HttpResponseRedirect(url)
```

#### Example for Reverse with Query Parameters:

If you need to generate a URL with query parameters, you can use `reverse()` combined with `HttpResponseRedirect` or `redirect()`.

```python
from django.urls import reverse
from django.http import HttpResponseRedirect

def my_view(request):
    url = reverse('post_list') + '?page=2'  # Add query parameters
    return HttpResponseRedirect(url)
```

### 4. **Redirect After Form Submission**

A common use case for redirection is after a successful form submission, you might want to redirect the user to a "thank you" page or back to the homepage.

#### Example:

```python
from django.shortcuts import render, redirect
from .forms import MyForm

def submit_form(request):
    if request.method == 'POST':
        form = MyForm(request.POST)
        if form.is_valid():
            # Save form data or perform some action
            form.save()

            # Redirect to a success page
            return redirect('thank_you')  # 'thank_you' is a named URL pattern

    else:
        form = MyForm()

    return render(request, 'submit_form.html', {'form': form})
```

### 5. **Redirecting with a Query String**

If you need to redirect to a URL with query parameters, you can add them manually after using `reverse()` or `redirect()`.

#### Example:

```python
from django.shortcuts import redirect
from django.urls import reverse

def my_view(request):
    # Redirect to a URL with query parameters
    url = reverse('search') + '?q=django'
    return redirect(url)
```

### 6. **Custom Redirects (403, 404, etc.)**

You can also handle custom redirects based on conditions, like user authentication or permission checks.

#### Example:

```python
from django.shortcuts import redirect

def my_view(request):
    if not request.user.is_authenticated:
        # Redirect to the login page if not authenticated
        return redirect('login')
    # Continue with the normal view logic for authenticated users
```

### Summary of Redirection Methods:

1. **`HttpResponseRedirect(url)`**: Redirects to a specific URL.
2. **`redirect()`**: A shortcut for redirecting to a view name, URL, or model.
3. **`reverse()`**: Dynamically generate URLs based on the view name or pattern.
4. **Redirect After Form Submission**: Commonly used after a form is submitted successfully.
5. **Query String Redirects**: Append query parameters to URLs during redirection.

Redirection is an essential tool in Django for guiding users through the application, handling form submissions, login requirements, and navigation between different views.
