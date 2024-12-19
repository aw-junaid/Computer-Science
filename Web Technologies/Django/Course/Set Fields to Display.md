In Django Admin, you can control which fields are displayed and how they appear in the admin interface. This allows you to create a more user-friendly and focused admin interface, displaying only the most relevant information for a particular model.

To set which fields to display in the Django Admin, you can use the `ModelAdmin` class. Specifically, you can use the following options:

### 1. **`list_display`**: Fields to Display in the List View
The `list_display` option controls the fields that will appear in the list view (the table showing multiple records) of your model in the admin interface.

#### Example: Displaying Specific Fields in the List View

```python
# admin.py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')  # Fields to show in list view

admin.site.register(Post, PostAdmin)
```

In this example, the `Post` model will have its `title`, `published_date`, and `status` fields displayed in the list view of the Django Admin.

### 2. **`list_filter`**: Add Filters to the List View
You can also add filters to allow users to narrow down the displayed records based on specific fields.

#### Example: Adding Filters

```python
# admin.py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')
    list_filter = ('status', 'published_date')  # Filter by status and published_date

admin.site.register(Post, PostAdmin)
```

This will add filters in the right sidebar of the list view, allowing users to filter posts by `status` and `published_date`.

### 3. **`search_fields`**: Enable Search for Fields
The `search_fields` option enables a search bar at the top of the list view, allowing users to search for records based on specific fields.

#### Example: Enabling Search

```python
# admin.py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')
    search_fields = ('title', 'content')  # Allow searching by title and content

admin.site.register(Post, PostAdmin)
```

This will allow users to search for posts by the `title` and `content` fields.

### 4. **`fieldsets`**: Organize Fields in the Form View
The `fieldsets` option controls how fields are grouped and displayed on the model’s form (the page where you create or edit a single record).

#### Example: Grouping Fields in the Form View

```python
# admin.py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')
    fieldsets = (
        (None, {
            'fields': ('title', 'content')
        }),
        ('Advanced options', {
            'classes': ('collapse',),  # This will make this section collapsible
            'fields': ('status', 'published_date')
        }),
    )

admin.site.register(Post, PostAdmin)
```

In this example, the form view will have two sections:
1. **None**: Displays `title` and `content`.
2. **Advanced options**: Displays `status` and `published_date`, which will be collapsible.

### 5. **`exclude`**: Exclude Fields from the Form View
If you want to exclude specific fields from the model's form, you can use the `exclude` option.

#### Example: Excluding Fields from the Form View

```python
# admin.py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')
    exclude = ('published_date',)  # Exclude the 'published_date' field from the form

admin.site.register(Post, PostAdmin)
```

In this example, the `published_date` field will not appear in the form view when editing or creating a `Post`.

### 6. **`readonly_fields`**: Make Fields Read-Only in the Form View
You can make specific fields read-only, so that users can see the values but not modify them.

#### Example: Making Fields Read-Only

```python
# admin.py
from django.contrib import admin
from .models import Post

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')
    readonly_fields = ('published_date',)  # Make 'published_date' read-only

admin.site.register(Post, PostAdmin)
```

In this example, the `published_date` field will be visible in the form, but it will be read-only (i.e., users cannot change its value).

### 7. **`inlines`**: Display Related Models Inline
If you have related models (such as `ForeignKey` or `ManyToMany` relationships), you can display them inline within the parent model's form.

#### Example: Inline Related Model

```python
# models.py
class Comment(models.Model):
    post = models.ForeignKey(Post, on_delete=models.CASCADE)
    content = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)

# admin.py
from django.contrib import admin
from .models import Post, Comment

class CommentInline(admin.TabularInline):  # You can also use StackedInline
    model = Comment
    extra = 1  # Number of empty forms to display

class PostAdmin(admin.ModelAdmin):
    list_display = ('title', 'published_date', 'status')
    inlines = [CommentInline]  # Show comments inline in the Post form

admin.site.register(Post, PostAdmin)
```

In this example, when editing or creating a `Post`, you will see the related `Comment` entries displayed inline in the same form.

---

### Summary of Options for Setting Fields in Django Admin:
1. **`list_display`**: Specifies which fields are shown in the list view.
2. **`list_filter`**: Adds filters to the list view.
3. **`search_fields`**: Allows searching by specific fields.
4. **`fieldsets`**: Groups fields in the form view.
5. **`exclude`**: Excludes specific fields from the form view.
6. **`readonly_fields`**: Makes specific fields read-only in the form view.
7. **`inlines`**: Displays related models inline in the form view.

By customizing these options, you can create a user-friendly, tailored admin interface for your models in Django.
