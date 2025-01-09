### **Mocking and Stubbing in RSpec**

Mocking and stubbing are techniques used in testing to isolate the unit of code being tested. These techniques allow you to replace certain behaviors with predefined ones so that the tests focus on the specific code under test, without depending on external systems or complex logic. In RSpec, these techniques are commonly used with **test doubles**.

Let’s explore both **mocking** and **stubbing** in detail, using examples.

---

### **1. Stubbing in RSpec**

**Stubbing** is when you replace a method's implementation with a predefined value. It allows you to control what a method returns when it is called during the test.

#### **Basic Stubbing Example**

Let’s say you have a `User` class that depends on an external service to fetch a user's details.

```ruby
class User
  def initialize(api_service)
    @api_service = api_service
  end

  def fetch_details(user_id)
    @api_service.get_user_data(user_id)
  end
end
```

In this case, you want to test the `fetch_details` method but you don’t want to hit the actual API. You can **stub** the `get_user_data` method to return a mock response.

```ruby
# spec/user_spec.rb
require 'rspec'
require_relative '../user'

RSpec.describe User do
  describe '#fetch_details' do
    it 'fetches user details from the API service' do
      # Create a mock of the API service
      mock_api_service = double("APIService")

      # Stub the get_user_data method to return a fake response
      allow(mock_api_service).to receive(:get_user_data).with(1).and_return({ name: "John Doe", age: 30 })

      # Create a User object and inject the mock API service
      user = User.new(mock_api_service)

      # Call the method and check if it returns the stubbed value
      result = user.fetch_details(1)
      expect(result).to eq({ name: "John Doe", age: 30 })
    end
  end
end
```

#### **Explanation:**

- **`double("APIService")`**: Creates a mock object of the `APIService`. This object will mimic the behavior of an actual `APIService` without calling any real methods.
- **`allow(...).to receive(...).and_return(...)`**: This tells RSpec to allow the `get_user_data` method to be called on the `mock_api_service` and always return a predefined response.
- **`with(1)`**: Specifies that the `get_user_data` method should only return the mock response if it's called with the argument `1`.

---

### **2. Mocking in RSpec**

**Mocking** is when you create an expectation that a method will be called on an object during the test. You can also specify the number of times it should be called, or even what arguments it should be called with. The key difference between mocking and stubbing is that mocks are often used to verify interactions.

#### **Basic Mocking Example**

Let’s say we have a `User` class with a method `send_welcome_email` that sends an email when a new user is created.

```ruby
class User
  def initialize(email_service)
    @email_service = email_service
  end

  def create(user_data)
    # Create the user...
    send_welcome_email(user_data[:email])
  end

  def send_welcome_email(email)
    @email_service.send_email(email)
  end
end
```

You want to test if the `send_welcome_email` method gets called when a user is created.

```ruby
# spec/user_spec.rb
require 'rspec'
require_relative '../user'

RSpec.describe User do
  describe '#create' do
    it 'sends a welcome email when a user is created' do
      # Create a mock of the email service
      mock_email_service = double("EmailService")

      # Set an expectation: the send_email method should be called once with the user's email
      expect(mock_email_service).to receive(:send_email).with("john.doe@example.com").once

      # Create a User object and inject the mock email service
      user = User.new(mock_email_service)

      # Call the create method
      user.create(email: "john.doe@example.com")
    end
  end
end
```

#### **Explanation:**

- **`expect(mock_email_service).to receive(:send_email)`**: This sets an expectation that the `send_email` method will be called on the `mock_email_service`.
- **`with("john.doe@example.com")`**: Specifies that the `send_email` method should be called with the email `"john.doe@example.com"`.
- **`once`**: This sets an expectation that the method should be called exactly once during the test.

---

### **3. Differences Between Mocking and Stubbing**

- **Stubbing**:
  - Used to replace method behavior.
  - Focuses on controlling method outputs.
  - Does not verify if the method was called.

- **Mocking**:
  - Used to set expectations about method calls.
  - Verifies interactions with the object.
  - Can check how many times the method was called and with what arguments.

In practice:
- **Stub** methods when you need to control the output of a method, and you don't care about interactions (e.g., when testing business logic).
- **Mock** methods when you want to verify that a method is being called, and you want to ensure the right interactions (e.g., testing that a side effect, like sending an email, actually happens).

---

### **4. Combining Mocks and Stubs**

You can use both mocking and stubbing together in tests. For example, you can **stub** one method to return a value and **mock** another method to check if it was called.

```ruby
# spec/user_spec.rb
require 'rspec'
require_relative '../user'

RSpec.describe User do
  describe '#create' do
    it 'creates a user and sends a welcome email' do
      # Create a mock of the email service
      mock_email_service = double("EmailService")
      
      # Stub the send_email method to avoid actual sending of emails
      allow(mock_email_service).to receive(:send_email).with("john.doe@example.com")

      # Create a mock of the user repository (another dependency)
      mock_user_repo = double("UserRepository")
      
      # Stub the create_user method to avoid hitting the database
      allow(mock_user_repo).to receive(:create_user).and_return(true)

      # Create a User object and inject both mocked services
      user = User.new(mock_email_service, mock_user_repo)

      # Set an expectation for the send_email method
      expect(mock_email_service).to receive(:send_email).with("john.doe@example.com")

      # Call the create method
      user.create(email: "john.doe@example.com")
    end
  end
end
```

In this example, we:
- Stubbed the `send_email` method to avoid actually sending an email.
- Mocked the `create_user` method to simulate database interaction without touching the real database.
- Verified that the `send_email` method was called correctly.

---

### **5. Spying in RSpec**

**Spying** is a combination of mocking and stubbing. It allows you to both spy on method calls and also return specific values for the method.

```ruby
RSpec.describe User do
  describe '#create' do
    it 'calls send_welcome_email' do
      mock_email_service = double("EmailService")

      # Use spy to track the method call
      allow(mock_email_service).to receive(:send_email).with("john.doe@example.com")

      user = User.new(mock_email_service)
      user.create(email: "john.doe@example.com")

      expect(mock_email_service).to have_received(:send_email).with("john.doe@example.com")
    end
  end
end
```

In this example:
- We **spy** on the `send_email` method by using `allow` to track the call.
- We use `have_received` to verify that `send_email` was called with the correct argument.

---

### **6. Conclusion**

Mocking and stubbing are essential techniques for unit testing in Ruby. **Stubbing** helps you control what methods return, while **mocking** is used to verify method interactions. **Spying** combines both techniques to track method calls while stubbing behaviors.

By using these techniques, you can write isolated, fast, and reliable tests that ensure your code works as expected without depending on external services or complex behavior.
