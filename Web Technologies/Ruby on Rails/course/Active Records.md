### **Ruby on Rails - ActiveRecord**

**ActiveRecord** is the Object-Relational Mapping (ORM) layer in Rails that connects Ruby classes to relational database tables. It simplifies database operations by allowing you to interact with database records as Ruby objects, rather than writing raw SQL queries. ActiveRecord automatically handles much of the SQL and provides convenient methods for querying and manipulating records in the database.

---

### **Key Concepts of ActiveRecord**

1. **Models and Tables**: In Rails, each model corresponds to a table in the database. For example, a `Post` model will typically map to a `posts` table.
2. **CRUD Operations**: ActiveRecord provides a set of methods for performing CRUD operations (Create, Read, Update, Delete) on database records.
3. **Validations**: ActiveRecord models can have built-in validations to ensure that data is valid before it’s saved to the database.
4. **Associations**: ActiveRecord supports several types of associations (one-to-many, many-to-many, etc.) to model relationships between tables.
5. **Migrations**: ActiveRecord migrations are used to manage changes to the database schema.

### **1. Basic ActiveRecord Operations**

#### **1.1. Creating Records**

To create a new record and save it to the database, you can use the `create` or `new` method.

- **`create`**: Instantiates a new object and saves it to the database in one step.

```ruby
post = Post.create(title: "My first post", content: "This is the content of the post")
```

- **`new` and `save`**: Instantiates a new object and requires you to explicitly call `save` to persist it.

```ruby
post = Post.new(title: "My second post", content: "More content")
post.save
```

#### **1.2. Reading Records**

To retrieve records from the database, you can use methods like `find`, `all`, `where`, and `first`.

- **`find`**: Retrieves a record by its primary key (usually the `id`).

```ruby
post = Post.find(1) # Finds the post with id=1
```

- **`all`**: Retrieves all records from the table.

```ruby
posts = Post.all # Retrieves all posts
```

- **`where`**: Retrieves records that match specific conditions.

```ruby
posts = Post.where(published: true) # Finds all posts where 'published' is true
```

- **`first`** and **`last`**: Retrieves the first or last record.

```ruby
post = Post.first # Retrieves the first post
post = Post.last  # Retrieves the last post
```

#### **1.3. Updating Records**

To update a record, you can modify its attributes and call `save` to persist the changes.

```ruby
post = Post.find(1)
post.update(title: "Updated Title") # Updates the title and saves the record
```

Alternatively, you can use:

```ruby
post = Post.find(1)
post.title = "Another updated title"
post.save
```

#### **1.4. Deleting Records**

To delete a record from the database, you can use the `destroy` or `delete` method.

- **`destroy`**: Deletes the record and triggers ActiveRecord callbacks.

```ruby
post = Post.find(1)
post.destroy
```

- **`delete`**: Deletes the record directly from the database without callbacks.

```ruby
post = Post.find(1)
post.delete
```

### **2. Validations**

ActiveRecord allows you to define validations in your model to ensure that only valid data is saved to the database. Some common validations are:

#### **2.1. Presence Validation**

To ensure a field is not empty:

```ruby
class Post < ApplicationRecord
  validates :title, presence: true
end
```

#### **2.2. Length Validation**

To ensure a field’s length meets certain criteria:

```ruby
class Post < ApplicationRecord
  validates :title, length: { minimum: 5 }
end
```

#### **2.3. Uniqueness Validation**

To ensure a field is unique:

```ruby
class User < ApplicationRecord
  validates :email, uniqueness: true
end
```

#### **2.4. Numericality Validation**

To ensure a field contains only numbers:

```ruby
class Product < ApplicationRecord
  validates :price, numericality: true
end
```

You can validate multiple attributes at once, as well as use custom validation methods.

### **3. Associations**

ActiveRecord provides powerful features for defining associations between models, allowing you to represent relationships like one-to-many, many-to-many, and one-to-one.

#### **3.1. One-to-Many Relationship**

A **one-to-many** relationship means that one record in a table can be associated with many records in another table. For example, a **Post** can have many **Comments**.

- **`has_many`**: Specifies the “one” side of the relationship.
- **`belongs_to`**: Specifies the “many” side of the relationship.

```ruby
# In post.rb (Post model)
class Post < ApplicationRecord
  has_many :comments
end

# In comment.rb (Comment model)
class Comment < ApplicationRecord
  belongs_to :post
end
```

Now, a `Post` object can have many associated `Comment` objects:

```ruby
post = Post.find(1)
comments = post.comments # Fetches all comments associated with the post
```

#### **3.2. One-to-One Relationship**

A **one-to-one** relationship means one record in a table is associated with one record in another table. For example, a **User** has one **Profile**.

```ruby
# In user.rb (User model)
class User < ApplicationRecord
  has_one :profile
end

# In profile.rb (Profile model)
class Profile < ApplicationRecord
  belongs_to :user
end
```

#### **3.3. Many-to-Many Relationship**

A **many-to-many** relationship means multiple records in one table are associated with multiple records in another table. For example, a **Student** can enroll in many **Courses**, and a **Course** can have many **Students**.

This requires a join table.

```ruby
# In student.rb (Student model)
class Student < ApplicationRecord
  has_and_belongs_to_many :courses
end

# In course.rb (Course model)
class Course < ApplicationRecord
  has_and_belongs_to_many :students
end
```

You will also need a join table, usually named alphabetically in plural (`students_courses` in this case), that contains foreign keys for both tables.

#### **3.4. Through Association**

If you need to access the associated records through another model (e.g., when you have a join model), use `has_many :through`.

```ruby
# In student.rb (Student model)
class Student < ApplicationRecord
  has_many :enrollments
  has_many :courses, through: :enrollments
end

# In course.rb (Course model)
class Course < ApplicationRecord
  has_many :enrollments
  has_many :students, through: :enrollments
end

# In enrollment.rb (Join model)
class Enrollment < ApplicationRecord
  belongs_to :student
  belongs_to :course
end
```

### **4. Scopes**

Scopes are a way to define reusable queries. They can be defined in your models and then chained together to filter records.

```ruby
class Post < ApplicationRecord
  scope :published, -> { where(published: true) }
  scope :recent, -> { order(created_at: :desc) }
end

# Usage:
Post.published.recent # Finds published posts, ordered by most recent
```

### **5. Migrations**

Migrations are used to change the structure of the database schema over time. You can create migrations to add or modify tables, columns, and indexes.

#### **5.1. Creating Migrations**

You can generate a migration using the following command:

```bash
rails generate migration AddPublishedToPosts published:boolean
```

This will generate a migration file that you can modify to define changes to your database schema.

#### **5.2. Running Migrations**

Run the following command to apply the migrations:

```bash
rails db:migrate
```

#### **5.3. Rollback Migrations**

If you need to revert a migration:

```bash
rails db:rollback
```

### **6. ActiveRecord Callbacks**

ActiveRecord provides several callback methods that allow you to run code at different stages of the lifecycle of a record (before or after creation, update, etc.).

For example, you might want to generate a slug before saving a post:

```ruby
class Post < ApplicationRecord
  before_create :generate_slug

  private

  def generate_slug
    self.slug = title.parameterize
  end
end
```

---

### **Summary**

ActiveRecord makes database interaction in Ruby on Rails simple and efficient by providing an intuitive syntax for performing CRUD operations, validations, associations, and migrations. It abstracts away raw SQL queries and provides a rich set of features that help developers focus on building applications instead of managing database queries.
