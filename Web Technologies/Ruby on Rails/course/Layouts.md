### **Ruby on Rails - Layouts**

In Ruby on Rails, **layouts** are used to define the common structure of your pages, such as headers, footers, and sidebars. Layouts help maintain consistency in the look and feel of your application by wrapping the content of views within a common structure. For example, your application may have a navigation bar, footer, or logo that appears across all or most pages. Instead of repeating the HTML code for these elements in every view, you can define them in a layout.

---

### **1. What is a Layout?**

A **layout** is an HTML template that is used to wrap the content of views. It can contain common elements like the header, footer, and navigation links, which are shared across multiple pages.

In Rails, a layout is typically stored in the `app/views/layouts` directory, and each controller can specify which layout to use.

---

### **2. Default Layout**

By default, Rails uses the `application.html.erb` layout for all controllers. This layout is located in `app/views/layouts/application.html.erb` and serves as the main wrapper for your content.

#### Example of the default layout (`application.html.erb`):

```erb
<!DOCTYPE html>
<html>
  <head>
    <title>My Blog</title>
    <%= csrf_meta_tags %>
    <%= csp_meta_tag %>
    <%= stylesheet_link_tag 'application', media: 'all', 'data-turbolinks-track': 'reload' %>
    <%= javascript_pack_tag 'application', 'data-turbolinks-track': 'reload' %>
  </head>

  <body>
    <header>
      <h1>My Blog</h1>
      <nav>
        <%= link_to 'Home', root_path %> |
        <%= link_to 'Posts', posts_path %>
      </nav>
    </header>

    <div id="content">
      <%= yield %>  <!-- This is where the view content will be inserted -->
    </div>

    <footer>
      <p>&copy; 2024 My Blog</p>
    </footer>
  </body>
</html>
```

- **`<%= yield %>`**: This is the placeholder where the content from the specific view will be inserted. The view rendered by the controller will be placed inside this `yield` block.
- The layout defines the common structure, like the header and footer, which will be present across different pages.

When a user accesses any page, the view is rendered inside this layout. For example, when the `index` action in the `PostsController` is called, the content from `posts/index.html.erb` will be rendered within the `yield` block.

---

### **3. Overriding the Default Layout**

You can override the default layout on a per-controller basis. This is useful when you want different layouts for different sections of your application.

#### Example: Using a Different Layout for a Controller

To use a custom layout for a specific controller, you can specify it in the controller with the `layout` method.

```ruby
class PostsController < ApplicationController
  layout 'post_layout'  # Use 'app/views/layouts/post_layout.html.erb' for this controller
end
```

In this case, Rails will look for a layout file named `post_layout.html.erb` in the `app/views/layouts` directory. If that file doesn't exist, it will fall back to the default `application.html.erb` layout.

---

### **4. Using Layouts for Specific Actions**

You can also specify a layout for specific actions within a controller, instead of applying it to the whole controller.

#### Example: Applying Layout to Specific Actions

```ruby
class PostsController < ApplicationController
  layout 'special_layout', only: [:new, :edit]  # Use 'special_layout' for new and edit actions
end
```

In this example:
- The `new` and `edit` actions in the `PostsController` will use the `special_layout.html.erb` layout.
- All other actions will use the default layout (`application.html.erb`).

You can also specify `except:` to exclude certain actions from a layout:

```ruby
class PostsController < ApplicationController
  layout 'admin_layout', except: [:index, :show]  # Exclude 'index' and 'show' from using 'admin_layout'
end
```

---

### **5. Layouts with Conditional Logic**

In Rails, you can include conditional logic inside your layouts, such as checking if a user is logged in and rendering different content accordingly.

#### Example: Conditional Logic in Layout

```erb
<!DOCTYPE html>
<html>
  <head>
    <title>My Blog</title>
  </head>

  <body>
    <header>
      <h1>My Blog</h1>
      <nav>
        <%= link_to 'Home', root_path %> |
        <% if user_signed_in? %>
          <%= link_to 'Dashboard', dashboard_path %> |
          <%= link_to 'Logout', logout_path %>
        <% else %>
          <%= link_to 'Login', login_path %> |
          <%= link_to 'Sign Up', signup_path %>
        <% end %>
      </nav>
    </header>

    <div id="content">
      <%= yield %>
    </div>

    <footer>
      <p>&copy; 2024 My Blog</p>
    </footer>
  </body>
</html>
```

In this example:
- The navigation bar changes depending on whether the user is signed in or not. If `user_signed_in?` returns true, the user sees links to their dashboard and a logout link. Otherwise, they see links to log in or sign up.

This is useful for scenarios like showing different navigation options for authenticated and unauthenticated users.

---

### **6. Layouts for APIs**

While layouts are typically used for rendering HTML responses, you may also want to render JSON responses for APIs. In this case, layouts are usually unnecessary, but you can still render JSON without wrapping it in HTML.

#### Example: No Layout for API Responses

For an API controller, you may choose not to use a layout. You can specify this in your controller:

```ruby
class Api::PostsController < ApplicationController
  layout false  # Disable layouts for this controller

  def index
    @posts = Post.all
    render json: @posts
  end
end
```

This will render the JSON response without any layout (since JSON doesn't need HTML structure).

---

### **7. Rendering Layouts Dynamically**

In some cases, you may want to dynamically select a layout based on conditions, such as the type of user or the action being performed.

#### Example: Dynamically Selecting Layouts

```ruby
class PostsController < ApplicationController
  layout :choose_layout

  def choose_layout
    if user_signed_in? && current_user.admin?
      "admin_layout"
    else
      "application"
    end
  end
end
```

In this example:
- If the user is signed in and is an admin, the controller will render the `admin_layout` for their views.
- Otherwise, the default `application` layout will be used.

---

### **8. Layouts with View Caching**

Rails supports **view caching**, and this can be applied to layouts as well. When view caching is enabled, Rails caches the layout along with the view content, which improves performance by avoiding the need to re-render the layout on each request.

You can enable caching in your production environment by configuring the caching settings in `config/environments/production.rb`:
```ruby
config.action_view.cache_template_loading = true
```

When caching is enabled, Rails will reuse the cached layout rather than rendering it each time.

---

### **9. Summary**

- **Layouts** are used to define a common structure for the views in your application.
- The default layout is `application.html.erb`, which is used by all controllers unless overridden.
- You can specify different layouts for specific controllers and actions using the `layout` method.
- **Conditional logic** can be used in layouts to alter the displayed content depending on conditions (e.g., user login status).
- For **API responses**, you can disable layouts entirely or return JSON responses without any layout.
- You can use **dynamic layout selection** based on conditions like user roles.
- **View caching** can also be applied to layouts for improved performance in production.
