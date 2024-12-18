### **Ruby on Rails - Send Emails**

Sending emails is a common feature in web applications for tasks such as account activation, password resets, notifications, and more. In Ruby on Rails, email sending is facilitated using the **ActionMailer** module. Rails makes it simple to create and send emails with built-in support for various email formats, attachments, and templating.

---

### **1. Setting Up ActionMailer**

To send emails in Rails, you first need to configure your application's email settings in the environment configuration files. Rails supports a variety of email delivery methods, including sending emails through SMTP servers like Gmail, SendGrid, or custom SMTP servers.

#### Step 1: Configure Email Settings

You need to configure ActionMailer to use an email provider, such as Gmail, SMTP, or others. In `config/environments/development.rb` and `config/environments/production.rb`, you need to specify the mail delivery method and settings.

For example, if you're using Gmail for development, you might configure it like this:

**Development Configuration (config/environments/development.rb)**:
```ruby
config.action_mailer.delivery_method = :smtp
config.action_mailer.smtp_settings = {
  address: 'smtp.gmail.com',
  port: 587,
  domain: 'gmail.com',
  user_name: ENV['GMAIL_USERNAME'],  # Use environment variables for sensitive data
  password: ENV['GMAIL_PASSWORD'],
  authentication: 'plain',
  enable_starttls_auto: true
}
config.action_mailer.raise_delivery_errors = true
config.action_mailer.default_url_options = { host: 'localhost', port: 3000 }
```

**Production Configuration (config/environments/production.rb)**:
```ruby
config.action_mailer.delivery_method = :smtp
config.action_mailer.smtp_settings = {
  address: 'smtp.sendgrid.net',
  port: 587,
  user_name: ENV['SENDGRID_USERNAME'],
  password: ENV['SENDGRID_PASSWORD'],
  authentication: 'plain',
  enable_starttls_auto: true
}
config.action_mailer.raise_delivery_errors = true
config.action_mailer.default_url_options = { host: 'yourdomain.com' }
```

- **`delivery_method`** specifies the method to use for sending emails (`:smtp`, `:sendmail`, etc.).
- **`smtp_settings`** contains the necessary configuration for the chosen SMTP service.
- **`default_url_options`** specifies the base URL for links generated in emails (important for email templates).

---

### **2. Creating a Mailer**

A mailer in Rails is a class that defines the emails your application can send. You can generate a mailer using the Rails generator.

#### Step 2: Generate a Mailer

Run the following command to generate a new mailer:

```bash
rails generate mailer UserMailer
```

This will generate the following files:
- **app/mailers/user_mailer.rb** (the mailer class)
- **app/views/user_mailer/** (folder for email templates)
- **test/mailers/user_mailer_test.rb** (test file)

---

### **3. Defining Mailer Methods**

In the generated `UserMailer` class, define methods for each email you want to send. These methods are responsible for setting up the content, subject, and recipient(s) of the email.

#### Example: Sending a Welcome Email

In `app/mailers/user_mailer.rb`, you can define a method like this:

```ruby
class UserMailer < ApplicationMailer
  default from: 'no-reply@yourdomain.com'

  def welcome_email(user)
    @user = user
    @url  = 'http://yourdomain.com/login'
    mail(to: @user.email, subject: 'Welcome to Our Platform!')
  end
end
```

- **`@user`**: The instance variable that is passed to the view, containing the user details.
- **`@url`**: The URL for the user to log in or verify their account.
- **`mail(to: ...)`**: The `mail` method is used to define the recipient and subject of the email.

---

### **4. Creating Email Templates**

Rails uses views to define the content of your emails. The views are stored in `app/views/user_mailer/` (matching the mailer class name).

#### Example: Email Template (HTML Version)

Create a file `app/views/user_mailer/welcome_email.html.erb` to define the HTML content of the email.

```erb
<h1>Welcome to Our Platform, <%= @user.name %>!</h1>
<p>Thank you for signing up. To get started, please visit the following link:</p>
<p><%= link_to 'Login', @url %></p>
```

This is the HTML version of the email. You can also create a **plain text version** of the email by creating a `welcome_email.text.erb` file in the same directory.

#### Example: Email Template (Text Version)

Create a file `app/views/user_mailer/welcome_email.text.erb` to define the plain text version of the email:

```erb
Welcome to Our Platform, <%= @user.name %>!

Thank you for signing up. To get started, please visit the following link:
<%= @url %>
```

Rails will automatically send the appropriate version of the email based on the email client's capabilities. If the client supports HTML, the HTML version will be sent. Otherwise, the text version will be used.

---

### **5. Sending Emails**

To send an email, simply call the mailer method in your controller or background job.

#### Example: Sending a Welcome Email After User Registration

In your `UsersController`, after creating a new user, you can send the email like this:

```ruby
class UsersController < ApplicationController
  def create
    @user = User.new(user_params)
    if @user.save
      UserMailer.welcome_email(@user).deliver_later  # Send email asynchronously
      redirect_to @user, notice: 'User created successfully'
    else
      render :new
    end
  end
end
```

- **`deliver_later`**: This sends the email asynchronously (using Active Job). If you want to send it immediately, you can use `deliver_now` instead.
- **`deliver_later`** is more efficient, especially when dealing with high traffic, because it puts the email sending process into a background job.

---

### **6. Previewing Emails**

Rails allows you to preview your emails in the browser before actually sending them, which can be very helpful for testing and debugging.

To enable email previews:

1. Add a preview class. Create a new file `test/mailers/previews/user_mailer_preview.rb`:

```ruby
class UserMailerPreview < ActionMailer::Preview
  def welcome_email
    user = User.first  # Use any user for previewing
    UserMailer.welcome_email(user)
  end
end
```

2. Visit the following URL to preview the email:
   ```
   http://localhost:3000/rails/mailers/user_mailer/welcome_email
   ```

- This will display the HTML and plain text versions of the email using the data you provided in the preview class.

---

### **7. Sending Emails in Background (Optional)**

Sending emails in the background is crucial for preventing delays in your application, especially when sending many emails at once.

#### Step 3: Set Up Active Job

Rails uses **Active Job** to handle background jobs. To send emails asynchronously, you can configure a background job processing tool like **Sidekiq**, **Resque**, or **DelayedJob**.

1. Add the job processing gem to your `Gemfile`. For example, for Sidekiq:

```ruby
gem 'sidekiq'
```

2. Install the gem:

```bash
bundle install
```

3. Set up Sidekiq in `config/application.rb`:

```ruby
config.active_job.queue_adapter = :sidekiq
```

4. Now, emails will be sent in the background using `deliver_later`.

---

### **8. Handling Email Errors**

It’s important to handle errors when sending emails. If there is an issue with sending an email, Rails will raise an error that can be caught and logged.

#### Example: Error Handling

In the controller, you can use a `begin-rescue` block to catch any email delivery errors:

```ruby
begin
  UserMailer.welcome_email(@user).deliver_later
rescue StandardError => e
  Rails.logger.error "Failed to send email: #{e.message}"
  flash[:alert] = "There was an issue sending the email. Please try again later."
end
```

---

### **9. Conclusion**

- **ActionMailer** is the built-in way to send emails in Ruby on Rails, and it provides a simple interface for defining mailers and email templates.
- Email configuration can be done through the environment configuration files (`development.rb`, `production.rb`).
- You can define mailer methods to set up the email content, subject, and recipients.
- **HTML and plain text versions** of emails can be created using views.
- Emails can be sent **synchronously** using `deliver_now` or **asynchronously** with `deliver_later`.
- **Background job processing** (e.g., with Sidekiq) is recommended for sending emails in the background to avoid delays.
- **Email previews** make it easy to test and debug email templates.
