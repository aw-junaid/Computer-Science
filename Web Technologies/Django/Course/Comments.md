In Django, the **comments framework** is a built-in feature that allows you to add comment functionality to your application. It can be used for users to post comments on different models, like blog posts, articles, or products. The Django comments framework includes views, forms, models, and templates for handling comment submission, moderation, and display.

The comments framework is built into Django through the `django.contrib.comments` module, but as of Django 1.9+, it is no longer included by default. However, it can still be installed and used via external packages like **django-contrib-comments**.

Here’s an overview of how to set up and use comments in Django:

### 1. **Install `django-contrib-comments`**

To use Django's comments framework (which is no longer part of the core Django), you need to install the `django-contrib-comments` package.

```bash
pip install django-contrib-comments
```

### 2. **Add `django.contrib.comments` to `INSTALLED_APPS`**

After installing the package, add it to your `INSTALLED_APPS` in `settings.py`.

```python
INSTALLED_APPS = [
    # Other apps
    'django.contrib.comments',
]
```

### 3. **Set Up URLs**

Include the URLs for the comments app in your project’s `urls.py`. You can add this directly to your main `urls.py` file:

```python
from django.conf.urls import url, include

urlpatterns = [
    # Other URL patterns
    url(r'^comments/', include('django.contrib.comments.urls')),
]
```

This will route all comment-related URLs to the `django.contrib.comments` application.

### 4. **Create a Commentable Model**

In order to add comments to a model, your model needs to support the comment system. The Django comments framework uses `django.contrib.comments.models.Comment` and links the comments to any model through a `content_type` and `object_id`.

Here’s how you can make a model commentable:

```python
from django.db import models
from django.contrib.contenttypes.fields import GenericRelation
from django.contrib.comments.models import Comment

class Post(models.Model):
    title = models.CharField(max_length=100)
    body = models.TextField()

    comments = GenericRelation(Comment)  # Linking the comment system to this model

    def __str__(self):
        return self.title
```

- **`GenericRelation(Comment)`**: This creates a reverse relation to the `Comment` model, allowing you to access all comments related to a specific object.

### 5. **Rendering Comments in Templates**

To display the comments associated with a model instance in a template, you can use the `comments` template tag.

#### Example: Displaying Comments for a Post

In your template, render comments for a specific `Post` instance:

```django
{% load comments %}
{% for comment in post.comments.all %}
    <div>
        <p>{{ comment.user_name }} says:</p>
        <p>{{ comment.comment }}</p>
    </div>
{% endfor %}
```

- **`post.comments.all`**: This gets all comments related to the `post` instance.

### 6. **Adding a Comment Form**

Django provides a `CommentForm` that you can use to allow users to post comments. To integrate this into your templates, you need to create a form for users to submit their comments.

#### Example: Comment Form in a Template

```django
{% load comments %}
<form action="{% comment_post_url post %}" method="post">
    {% csrf_token %}
    <textarea name="comment" placeholder="Write your comment here"></textarea>
    <button type="submit">Submit</button>
</form>
```

- **`{% comment_post_url post %}`**: This tag generates the URL for posting comments on a specific object (`post`).
- **`{% csrf_token %}`**: Ensures the form is secure by including a CSRF token.

### 7. **Customizing Comment Model (Optional)**

You can also create a custom comment model if you need additional fields or logic beyond the default comment model. For this, you need to extend `django.contrib.comments.models.Comment` and provide your custom fields.

#### Example: Custom Comment Model

```python
from django.db import models
from django.contrib.comments.models import Comment

class CustomComment(Comment):
    rating = models.IntegerField()  # Adding a rating field to the comment

    def __str__(self):
        return f"Comment by {self.user_name} with rating {self.rating}"
```

To use this custom model, you would need to tell Django to use it in place of the default `Comment` model. You can achieve this by overriding the `COMMENTS_APP` setting in your `settings.py`.

```python
COMMENTS_APP = 'myapp.custom_comments'
```

### 8. **Moderating Comments**

Django’s comment system includes the ability to moderate comments. You can set comments to be either approved automatically or require manual approval.

#### Example: Manually Approving Comments

You can create a custom admin interface to moderate comments or set the default behavior.

In your custom model admin, you might do:

```python
from django.contrib import admin
from django.contrib.comments.models import Comment

class CommentAdmin(admin.ModelAdmin):
    list_display = ('user_name', 'comment', 'submit_date', 'is_public', 'is_removed')
    list_filter = ('is_public', 'is_removed')
    actions = ['approve_comments']

    def approve_comments(self, request, queryset):
        queryset.update(is_public=True)

admin.site.register(Comment, CommentAdmin)
```

- **`is_public`**: Whether the comment is approved and visible to others.
- **`is_removed`**: Whether the comment has been marked as removed (not deleted but hidden).

### 9. **Permissions and Security**

By default, the comments framework supports basic permissions to ensure only authenticated users can post comments. You can use Django's built-in permissions system or add your own logic to restrict comment posting based on user roles.

#### Example: Restricting Comments to Logged-in Users

In the comment form view, you can check if the user is authenticated:

```python
from django.contrib.auth.decorators import login_required
from django.shortcuts import render, get_object_or_404
from .models import Post

@login_required
def post_comment(request, post_id):
    post = get_object_or_404(Post, pk=post_id)
    
    if request.method == 'POST':
        comment = request.POST['comment']
        post.comments.create(user_name=request.user.username, comment=comment)
        return redirect('post_detail', post_id=post.id)
    
    return render(request, 'post_detail.html', {'post': post})
```

### 10. **Comment Notifications**

Django doesn’t provide built-in email notifications when new comments are posted, but you can implement this easily by connecting to Django’s signal system.

For example, you can use the `comment_was_posted` signal to send an email when a comment is posted:

```python
from django.db.models.signals import post_save
from django.dispatch import receiver
from django.core.mail import send_mail
from django.contrib.comments.models import Comment

@receiver(post_save, sender=Comment)
def send_comment_notification(sender, instance, created, **kwargs):
    if created:
        send_mail(
            'New Comment Posted',
            f'A new comment has been posted on your post: {instance.comment}',
            'admin@yourdomain.com',
            ['author@yourdomain.com'],
            fail_silently=False,
        )
```

- **`comment_was_posted`**: This signal can be used to perform actions when a comment is created.

### Conclusion

Django's comments framework provides a robust and flexible solution for adding comment functionality to your application. Although it is no longer included in Django by default, you can install and integrate the `django-contrib-comments` package to easily implement comments with minimal effort.

Key features include:
- Simple comment forms and views.
- Built-in support for comment moderation.
- Customizable models, templates, and admin interfaces.
- Permission control for who can post comments.
