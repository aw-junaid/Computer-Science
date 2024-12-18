### **Ruby on Rails - File Uploading**

File uploading is a common feature in web applications where users can upload images, documents, and other types of files. Ruby on Rails provides several ways to handle file uploads, with the most popular methods being through built-in support in the framework and using gems such as **CarrierWave**, **ActiveStorage**, and **Paperclip**.

In modern Rails applications, **ActiveStorage** is the default solution for file uploading and handling. It was introduced in Rails 5.2 and provides a clean, integrated way to attach files to models.

---

### **1. Setting Up ActiveStorage for File Uploads**

ActiveStorage is the recommended solution for handling file uploads in Rails. Here's how to get started:

#### Step 1: Install ActiveStorage

ActiveStorage comes with Rails, so you just need to run a couple of commands to set it up.

1. **Run the ActiveStorage installation command**:
    ```bash
    rails active_storage:install
    ```

    This generates a migration that creates two tables: `active_storage_blobs` (for storing metadata about the uploaded files) and `active_storage_attachments` (for associating files with models).

2. **Run the migration**:
    ```bash
    rails db:migrate
    ```

---

### **2. Attaching Files to Models with ActiveStorage**

After setting up ActiveStorage, you can easily attach files to any model.

#### Step 2: Adding Attachments to Models

In your model, use `has_one_attached` or `has_many_attached` to define file attachments.

- **`has_one_attached`** is used for single file uploads.
- **`has_many_attached`** is used for multiple file uploads.

#### Example: Uploading a Profile Picture

In the `User` model, you might want to upload a profile picture.

```ruby
class User < ApplicationRecord
  has_one_attached :profile_picture
end
```

#### Example: Uploading Multiple Files (e.g., Images for a Post)

In the `Post` model, you might want to upload multiple images.

```ruby
class Post < ApplicationRecord
  has_many_attached :images
end
```

---

### **3. Creating the Form for File Uploads**

Rails makes it easy to create forms that handle file uploads with ActiveStorage. To upload files, you need to use the `form_with` helper and ensure the form is set to handle multipart data (`multipart: true`).

#### Example: File Upload Form for a Profile Picture

In the `users/new.html.erb` view, you can create a form to upload a profile picture:

```erb
<%= form_with(model: @user, local: true) do |form| %>
  <%= form.label :profile_picture %>
  <%= form.file_field :profile_picture %>
  <%= form.submit "Save" %>
<% end %>
```

- **`file_field`** is used to create a file input.
- **`local: true`** ensures that the form is submitted via the normal HTTP request, which is necessary for file uploads.

#### Example: File Upload Form for Multiple Images in a Post

In the `posts/new.html.erb` view, you can allow users to upload multiple images for a post:

```erb
<%= form_with(model: @post, local: true) do |form| %>
  <%= form.label :images %>
  <%= form.file_field :images, multiple: true %>
  <%= form.submit "Create Post" %>
<% end %>
```

- **`multiple: true`** allows users to select multiple files.

---

### **4. Handling File Uploads in the Controller**

In your controller, you don’t need to do anything special to handle the file uploads. Rails takes care of saving the files automatically when the form is submitted.

#### Example: Handling a Profile Picture Upload

In the `UsersController`, handle the form submission as usual:

```ruby
class UsersController < ApplicationController
  def create
    @user = User.new(user_params)
    if @user.save
      redirect_to @user, notice: "User created successfully"
    else
      render :new
    end
  end

  private

  def user_params
    params.require(:user).permit(:name, :email, :profile_picture)
  end
end
```

For a post with multiple images, the process is similar:

```ruby
class PostsController < ApplicationController
  def create
    @post = Post.new(post_params)
    if @post.save
      redirect_to @post, notice: "Post created successfully"
    else
      render :new
    end
  end

  private

  def post_params
    params.require(:post).permit(:title, :content, images: [])
  end
end
```

- **`images: []`** is used to allow an array of uploaded files for the `images` attachment.

---

### **5. Displaying Uploaded Files**

You can display the uploaded files in your views using helpers provided by ActiveStorage.

#### Example: Displaying a Profile Picture

To display the uploaded profile picture in the user's profile page:

```erb
<% if @user.profile_picture.attached? %>
  <%= image_tag @user.profile_picture %>
<% else %>
  <p>No profile picture available</p>
<% end %>
```

- **`attached?`** checks if a file is uploaded.
- **`image_tag`** is used to display the image. ActiveStorage automatically handles the URL for the file.

#### Example: Displaying Multiple Images for a Post

To display multiple images for a post:

```erb
<% @post.images.each do |image| %>
  <%= image_tag image %>
<% end %>
```

- **`@post.images.each`** iterates over each uploaded image and displays it.

---

### **6. Downloading Files**

You can also allow users to download files using the `rails_blob_path` helper, which generates the correct URL for downloading an attached file.

#### Example: Downloading a File

```erb
<%= link_to "Download Profile Picture", rails_blob_path(@user.profile_picture, disposition: "attachment") %>
```

- **`disposition: "attachment"`** ensures that the file is served as a download instead of being displayed in the browser.

---

### **7. Storing Files with ActiveStorage**

By default, ActiveStorage stores files in the local file system (`public/storage` directory) during development. For production, you can configure it to store files in external services such as Amazon S3, Google Cloud Storage, or Microsoft Azure.

#### Example: Configuring ActiveStorage to Use Amazon S3 (for Production)

1. Add the `aws-sdk-s3` gem to your Gemfile:
    ```ruby
    gem 'aws-sdk-s3', require: false
    ```

2. Run `bundle install` to install the gem.

3. In `config/storage.yml`, configure the S3 service:

    ```yaml
    amazon:
      service: S3
      access_key_id: <%= ENV['AWS_ACCESS_KEY_ID'] %>
      secret_access_key: <%= ENV['AWS_SECRET_ACCESS_KEY'] %>
      region: 'us-east-1'
      bucket: '<%= ENV['AWS_BUCKET_NAME'] %>'
    ```

4. Set the storage service in `config/environments/production.rb`:

    ```ruby
    config.active_storage.service = :amazon
    ```

5. Set your AWS credentials and bucket name in the environment variables or in the credentials file.

---

### **8. File Validations**

You can validate file uploads in your models to ensure the files meet certain criteria (e.g., file type, size).

#### Example: Validating File Size and Type

```ruby
class User < ApplicationRecord
  has_one_attached :profile_picture

  validate :acceptable_image

  def acceptable_image
    return unless profile_picture.attached?
    unless profile_picture.byte_size <= 1.megabyte
      errors.add(:profile_picture, "is too big")
    end
    acceptable_types = ["image/jpeg", "image/png"]
    unless acceptable_types.include?(profile_picture.content_type)
      errors.add(:profile_picture, "must be a JPEG or PNG")
    end
  end
end
```

- **`byte_size`** checks the file size.
- **`content_type`** checks the file type.

---

### **9. Conclusion**

- **ActiveStorage** is the default and recommended way to handle file uploads in Rails applications, providing a simple and flexible interface for attaching files to models.
- You can handle file uploads for both single and multiple files, easily display them in views, and even configure storage backends like Amazon S3 for production.
- File validations, such as size and type checks, can be added in the model to ensure that only valid files are uploaded.
- For larger applications, or when specific features are needed (e.g., image resizing), gems like **CarrierWave** and **Paperclip** can also be used.
