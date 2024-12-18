### **Ruby on Rails - Examples**

Here are a few simple examples that demonstrate key features and functionality in Ruby on Rails applications. These examples cover creating models, controllers, views, migrations, and basic Rails commands.

---

### **1. Creating a Basic Blog Application**

Let’s walk through the creation of a basic blog application with posts that users can view, create, edit, and delete.

#### **Step 1: Create a New Rails Application**

Start by creating a new Rails application:

```bash
rails new blog_app
cd blog_app
```

#### **Step 2: Generate a Post Model**

We will create a `Post` model that will represent blog posts. Each post will have a title and content.

```bash
rails generate model Post title:string content:text
```

This will generate a migration file and a model file in `app/models/post.rb`.

#### **Step 3: Run the Migration**

Now, run the migration to create the `posts` table in the database:

```bash
rails db:migrate
```

#### **Step 4: Generate a Controller for Posts**

Next, generate a controller to handle requests related to posts:

```bash
rails generate controller Posts
```

This will generate a `posts_controller.rb` file in `app/controllers/` and corresponding view files in `app/views/posts/`.

#### **Step 5: Define Controller Actions**

Edit the `app/controllers/posts_controller.rb` file to define the actions for your posts.

```ruby
class PostsController < ApplicationController
  def index
    @posts = Post.all
  end

  def show
    @post = Post.find(params[:id])
  end

  def new
    @post = Post.new
  end

  def create
    @post = Post.new(post_params)
    if @post.save
      redirect_to @post
    else
      render 'new'
    end
  end

  def edit
    @post = Post.find(params[:id])
  end

  def update
    @post = Post.find(params[:id])
    if @post.update(post_params)
      redirect_to @post
    else
      render 'edit'
    end
  end

  def destroy
    @post = Post.find(params[:id])
    @post.destroy
    redirect_to posts_path
  end

  private

  def post_params
    params.require(:post).permit(:title, :content)
  end
end
```

#### **Step 6: Define Routes**

Open the `config/routes.rb` file and define the routes for your blog application.

```ruby
Rails.application.routes.draw do
  resources :posts
  root 'posts#index'
end
```

This will generate the standard RESTful routes for posts (`index`, `show`, `new`, `create`, `edit`, `update`, `destroy`).

#### **Step 7: Create Views**

Now, create the views for each action in `app/views/posts/` directory.

1. **Index View (`index.html.erb`)**: Displays a list of all posts.

```erb
<h1>All Posts</h1>

<% @posts.each do |post| %>
  <h2><%= link_to post.title, post %></h2>
  <p><%= post.content.truncate(100) %></p>
  <%= link_to 'Edit', edit_post_path(post) %> |
  <%= link_to 'Destroy', post, method: :delete, data: { confirm: 'Are you sure?' } %>
<% end %>

<%= link_to 'New Post', new_post_path %>
```

2. **Show View (`show.html.erb`)**: Displays an individual post.

```erb
<h1><%= @post.title %></h1>
<p><%= @post.content %></p>

<%= link_to 'Edit', edit_post_path(@post) %> |
<%= link_to 'Back to Posts', posts_path %>
```

3. **New View (`new.html.erb`)**: Form for creating a new post.

```erb
<h1>New Post</h1>

<%= form_with(model: @post, local: true) do |form| %>
  <% if @post.errors.any? %>
    <div>
      <h2><%= pluralize(@post.errors.count, "error") %> prohibited this post from being saved:</h2>
      <ul>
        <% @post.errors.full_messages.each do |message| %>
          <li><%= message %></li>
        <% end %>
      </ul>
    </div>
  <% end %>

  <div>
    <%= form.label :title %>
    <%= form.text_field :title %>
  </div>

  <div>
    <%= form.label :content %>
    <%= form.text_area :content %>
  </div>

  <div>
    <%= form.submit %>
  </div>
<% end %>

<%= link_to 'Back to Posts', posts_path %>
```

4. **Edit View (`edit.html.erb`)**: Form for editing an existing post.

```erb
<h1>Edit Post</h1>

<%= form_with(model: @post, local: true) do |form| %>
  <% if @post.errors.any? %>
    <div>
      <h2><%= pluralize(@post.errors.count, "error") %> prohibited this post from being saved:</h2>
      <ul>
        <% @post.errors.full_messages.each do |message| %>
          <li><%= message %></li>
        <% end %>
      </ul>
    </div>
  <% end %>

  <div>
    <%= form.label :title %>
    <%= form.text_field :title %>
  </div>

  <div>
    <%= form.label :content %>
    <%= form.text_area :content %>
  </div>

  <div>
    <%= form.submit %>
  </div>
<% end %>

<%= link_to 'Back to Posts', posts_path %>
```

#### **Step 8: Start the Server**

Now, run the Rails server:

```bash
rails server
```

You can visit `http://localhost:3000` in your browser and start interacting with your blog application. You will be able to create, view, edit, and delete posts.

---

### **2. Adding Authentication with Devise**

To add user authentication to your application, you can use the **Devise** gem.

#### **Step 1: Add Devise Gem to Gemfile**

In your `Gemfile`, add the following:

```ruby
gem 'devise'
```

Run `bundle install` to install the gem.

#### **Step 2: Install Devise**

Run the Devise installation generator:

```bash
rails generate devise:install
```

#### **Step 3: Create a User Model**

Generate the `User` model with Devise:

```bash
rails generate devise User
```

Run the migration:

```bash
rails db:migrate
```

#### **Step 4: Protect Controller Actions**

In your `PostsController`, protect the `new`, `create`, `edit`, and `update` actions to require authentication:

```ruby
class PostsController < ApplicationController
  before_action :authenticate_user!, only: [:new, :create, :edit, :update]

  # rest of your code
end
```

#### **Step 5: Add User Registration and Login Links**

In your `application.html.erb`, add links for user registration and login:

```erb
<% if user_signed_in? %>
  Logged in as <%= current_user.email %> | <%= link_to 'Logout', destroy_user_session_path, method: :delete %>
<% else %>
  <%= link_to 'Sign Up', new_user_registration_path %> |
  <%= link_to 'Login', new_user_session_path %>
<% end %>
```

Now your application supports user registration, login, and session management using Devise.

---

### **3. Example of Testing in Rails**

Testing is a vital part of Rails applications. Here's an example of a simple test for the `Post` model.

#### **Step 1: Generate a Test for Post Model**

Rails automatically creates test files for your models. You can create a test for the `Post` model by adding validation tests.

In `test/models/post_test.rb`, add the following:

```ruby
require 'test_helper'

class PostTest < ActiveSupport::TestCase
  test "should not save post without title" do
    post = Post.new(content: "Some content")
    assert_not post.save, "Saved the post without a title"
  end

  test "should save post with title and content" do
    post = Post.new(title: "Test Title", content: "Test content")
    assert post.save, "Failed to save the post with title and content"
  end
end
```

Run the tests with:

```bash
rails test
```

This will run all tests, including the ones for the `Post` model, to ensure your validations and logic work as expected.

---

### **Summary**

These examples demonstrate how to create a basic Rails application with CRUD functionality, integrate user authentication with **Devise**, and perform basic testing with **Rails' built-in testing framework**. Rails provides a lot of convenience and powerful tools for developers to build full-featured web applications quickly and efficiently.
