### **Ruby on Rails - Routes**

In Ruby on Rails, **routes** define how URLs are mapped to controller actions. Routes are an essential part of the Rails MVC (Model-View-Controller) architecture because they determine how user requests are directed to the appropriate controller and action.

Rails uses a flexible routing system to map HTTP requests to controller actions and is defined in the `config/routes.rb` file.

---

### **1. What are Routes?**

A **route** is a set of rules that specifies:
- The HTTP method (GET, POST, PUT, DELETE, etc.).
- The URL pattern.
- The controller and action that should handle the request.

For example:
- When a user visits `/posts`, it could trigger the `index` action of the `PostsController`.
- When a user submits a form to create a new post, the route might map to the `create` action of the `PostsController`.

---

### **2. Defining Routes**

In Rails, routes are defined in the `config/routes.rb` file. Here's the basic structure:

```ruby
Rails.application.routes.draw do
  # Define routes here
end
```

Inside this block, you specify how URLs should be matched and which controller and action should handle each request.

### **3. Basic Routing**

Here’s how you define routes for basic controller actions:

```ruby
Rails.application.routes.draw do
  get 'posts/index'
  get 'posts/show'
  post 'posts/create'
end
```

This maps HTTP methods to controller actions:
- `GET /posts/index` -> `PostsController#index`
- `GET /posts/show` -> `PostsController#show`
- `POST /posts/create` -> `PostsController#create`

---

### **4. RESTful Routing**

Rails promotes **RESTful design** for web applications, where routes follow a standard pattern for CRUD operations. The `resources` method provides a convenient way to set up standard routes for a resource (like a `Post` or `Comment`).

```ruby
Rails.application.routes.draw do
  resources :posts
end
```

This generates all the standard routes for the `posts` resource:

- **GET /posts** => `PostsController#index` (list all posts)
- **GET /posts/:id** => `PostsController#show` (show a single post)
- **GET /posts/new** => `PostsController#new` (display form for new post)
- **POST /posts** => `PostsController#create` (create a new post)
- **GET /posts/:id/edit** => `PostsController#edit` (display form for editing a post)
- **PATCH/PUT /posts/:id** => `PostsController#update` (update a post)
- **DELETE /posts/:id** => `PostsController#destroy` (delete a post)

By using `resources`, Rails automatically sets up these routes with the correct HTTP methods and path patterns.

### **5. Named Routes**

Rails allows you to define **named routes**, which provide a convenient way to refer to specific routes in your code (especially when generating URLs or links).

For example, using `resources :posts` gives you several named routes:
- `posts_path` → `/posts` (the index path)
- `new_post_path` → `/posts/new` (the new post form)
- `post_path(post)` → `/posts/:id` (show a post)
- `edit_post_path(post)` → `/posts/:id/edit` (edit a post)

You can also define your own named routes:

```ruby
get 'about', to: 'pages#about', as: 'about'
```

Now, you can use the `about_path` helper in your views and controllers to generate the URL `/about`.

---

### **6. Route HTTP Methods**

Rails routes map to HTTP methods such as **GET**, **POST**, **PUT**, **PATCH**, and **DELETE**. Each HTTP method corresponds to a specific type of request.

- **GET**: Used to retrieve data (e.g., show a list or a single resource).
- **POST**: Used to create new data (e.g., submitting a form).
- **PUT/PATCH**: Used to update existing data (e.g., editing a resource).
- **DELETE**: Used to delete data (e.g., removing a resource).

#### Example:

```ruby
get '/posts', to: 'posts#index'   # Retrieve a list of posts
post '/posts', to: 'posts#create' # Create a new post
put '/posts/:id', to: 'posts#update'  # Update an existing post
delete '/posts/:id', to: 'posts#destroy'  # Delete a post
```

Rails automatically uses the appropriate HTTP method for each action when using `resources`.

---

### **7. Nested Routes**

You can create **nested routes** to represent relationships between resources. For example, if `Post` has many `Comments`, you can nest the `comments` resource inside the `posts` resource:

```ruby
Rails.application.routes.draw do
  resources :posts do
    resources :comments
  end
end
```

This generates routes like:
- **GET /posts/:post_id/comments** => `CommentsController#index` (list comments for a specific post)
- **POST /posts/:post_id/comments** => `CommentsController#create` (create a comment for a specific post)
- **GET /posts/:post_id/comments/:id** => `CommentsController#show` (show a specific comment)
- **GET /posts/:post_id/comments/:id/edit** => `CommentsController#edit` (edit a comment)
- **PATCH/PUT /posts/:post_id/comments/:id** => `CommentsController#update` (update a comment)
- **DELETE /posts/:post_id/comments/:id** => `CommentsController#destroy` (delete a comment)

### **8. Constraints**

Rails allows you to define **constraints** on routes, such as requiring a parameter to be an integer or a specific format (e.g., to match an ID).

```ruby
get 'posts/:id', to: 'posts#show', constraints: { id: /\d+/ }
```

This route ensures that the `id` parameter is a number.

You can also use constraints with regular expressions to match specific patterns, such as requiring an email format or a UUID.

---

### **9. Custom Routes**

While `resources` handles most of the routing needs for a standard resource, you may want to define **custom routes** for specific actions that don’t fit the RESTful pattern.

For example:

```ruby
Rails.application.routes.draw do
  get 'home', to: 'pages#home', as: 'home'
  post 'signup', to: 'users#signup', as: 'signup'
  get 'dashboard', to: 'users#dashboard'
end
```

Here, we define custom routes for non-RESTful actions.

---

### **10. Route Concerns**

If you need to apply the same set of routes to multiple resources, you can use **route concerns**. This is helpful when you have several resources that share similar routes.

```ruby
Rails.application.routes.draw do
  concern :commentable do
    resources :comments, only: [:create, :destroy]
  end

  resources :posts, concerns: :commentable
  resources :articles, concerns: :commentable
end
```

This applies the same set of `comments` routes to both `posts` and `articles`.

---

### **11. Root Route**

You can specify the **root route** of your application, which is the default route when no specific path is provided in the URL.

```ruby
Rails.application.routes.draw do
  root 'home#index' # Home page route
end
```

In this case, visiting the base URL (e.g., `http://localhost:3000`) will trigger the `index` action of the `HomeController`.

---

### **12. Route Helpers**

Rails automatically generates **URL helpers** for all the routes you define. These helpers are used to generate URLs dynamically in your views and controllers.

For example, if you have the following route:

```ruby
get 'posts/:id', to: 'posts#show', as: 'post'
```

You can use the helper method `post_path` to generate a URL for a specific post:

```ruby
post_path(post) # => "/posts/:id" where :id is the post's ID
```

---

### **13. Redirects and Constraints**

Rails allows you to redirect certain routes to another route, or even other URLs. You can also apply constraints to handle conditions such as checking user authentication.

#### Example of redirecting:

```ruby
get '/old-posts', to: redirect('/posts')
```

This redirects any requests to `/old-posts` to the `/posts` route.

---

### **14. Resources vs. Resources with Member and Collection Routes**

Sometimes you may need to define custom routes that work with individual records (member routes) or the entire collection (collection routes).

- **Member Routes**: Acts on individual records.
  
  ```ruby
  resources :posts do
    member do
      get 'archive'
    end
  end
  ```
  This will create a route like `GET /posts/:id/archive`.

- **Collection Routes**: Acts on the entire collection.
  
  ```ruby
  resources :posts do
    collection do
      get 'recent'
    end
  end
  ```
  This will create a route like `GET /posts/recent`.

---

### **Summary**

- **Routes** map HTTP requests to controller actions.
- **RESTful routes** are created using the `resources` method for CRUD actions.
- **Named routes** allow you to refer to routes with helper methods in views and controllers.
- **Custom routes** can be defined for specific actions.
- **Constraints** and **filters** can be applied to routes to handle special conditions (e.g., matching only integers or applying authorization).
- Use **route helpers** to generate URLs dynamically.
