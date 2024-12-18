### **Ruby on Rails - Migrations**

**Migrations** in Ruby on Rails are a way to modify the database schema over time in a consistent and easy-to-manage manner. They allow you to create, modify, and delete database tables and columns in a way that can be tracked and versioned, making it easy to maintain and share changes to the database schema in a team environment.

Migrations are written in Ruby, and Rails provides a set of helper methods to define changes to the database. This way, you don't need to write raw SQL commands to update the schema; Rails will automatically generate the appropriate SQL based on your migration instructions.

---

### **1. What are Migrations?**

Migrations are used to:
- Create or drop database tables.
- Add, remove, or rename columns.
- Add or remove indexes.
- Change column types, null constraints, and more.

Migrations help in versioning your database schema, meaning you can apply or roll back changes in a controlled manner, making it easier to maintain consistency across different environments (development, test, production).

---

### **2. Migration Structure**

Each migration is a Ruby class that inherits from `ActiveRecord::Migration`. Inside this class, you define two key methods:
- **`change`**: Rails will automatically figure out how to apply and reverse the change.
- **`up`/`down`**: These methods are used when you need more control over how changes are applied and reversed (less common with modern Rails versions).

#### **Example Migration Class**

```ruby
class CreatePosts < ActiveRecord::Migration[6.0]  # version of migration
  def change
    create_table :posts do |t|
      t.string :title
      t.text :content
      t.boolean :published, default: false

      t.timestamps  # automatically adds created_at and updated_at columns
    end
  end
end
```

In this example:
- **`create_table :posts`** creates a new `posts` table.
- **`t.string`, `t.text`, `t.boolean`** define columns for the table.
- **`t.timestamps`** adds the `created_at` and `updated_at` timestamp columns.
  
### **3. Generating Migrations**

You can generate a migration file using the Rails command-line tool. The basic syntax is:

```bash
rails generate migration MigrationName
```

For example, if you want to create a `posts` table with a title and content, you would run:

```bash
rails generate migration CreatePosts title:string content:text
```

This generates a migration file like:

```ruby
class CreatePosts < ActiveRecord::Migration[6.0]
  def change
    create_table :posts do |t|
      t.string :title
      t.text :content

      t.timestamps
    end
  end
end
```

If you need to add or modify columns after creating a table, you can generate a migration for that:

```bash
rails generate migration AddPublishedToPosts published:boolean
```

This generates a migration that looks like:

```ruby
class AddPublishedToPosts < ActiveRecord::Migration[6.0]
  def change
    add_column :posts, :published, :boolean
  end
end
```

### **4. Running Migrations**

Once a migration is created, you apply the changes to your database by running:

```bash
rails db:migrate
```

This will apply any pending migrations to your database.

If you need to run migrations for a specific environment (e.g., production), you can specify it like this:

```bash
RAILS_ENV=production rails db:migrate
```

### **5. Rolling Back Migrations**

You can undo the last migration with:

```bash
rails db:rollback
```

If you want to rollback multiple migrations, you can specify the number of steps:

```bash
rails db:rollback STEP=3
```

This rolls back the last 3 migrations.

You can also use:

```bash
rails db:reset
```

This command will drop and recreate the database, then reapply all migrations and seed data.

### **6. Common Migration Methods**

Here are some common migration methods used to modify the database schema:

#### **6.1. Creating Tables**

```ruby
create_table :users do |t|
  t.string :username
  t.string :email
  t.boolean :active, default: true
  t.timestamps
end
```

This creates a `users` table with `username`, `email`, and `active` fields, plus `created_at` and `updated_at` timestamps.

#### **6.2. Adding Columns**

To add a new column to an existing table:

```ruby
add_column :posts, :author_id, :integer
```

This adds an `author_id` column of type `integer` to the `posts` table.

#### **6.3. Removing Columns**

To remove a column from a table:

```ruby
remove_column :posts, :author_id
```

This removes the `author_id` column from the `posts` table.

#### **6.4. Renaming Columns**

To rename an existing column:

```ruby
rename_column :posts, :title, :heading
```

This renames the `title` column to `heading` in the `posts` table.

#### **6.5. Changing Column Types**

To change the type of an existing column:

```ruby
change_column :posts, :published, :boolean, default: true
```

This changes the `published` column in the `posts` table to a `boolean` type and sets a default value of `true`.

#### **6.6. Adding Indexes**

Indexes are important for optimizing queries, particularly those involving `WHERE` clauses.

To add an index to a column:

```ruby
add_index :posts, :title
```

This adds an index on the `title` column in the `posts` table.

You can also add a unique index to enforce uniqueness:

```ruby
add_index :users, :email, unique: true
```

This ensures that email addresses in the `users` table are unique.

#### **6.7. Removing Indexes**

To remove an index:

```ruby
remove_index :posts, :title
```

This removes the index on the `title` column in the `posts` table.

#### **6.8. Creating Foreign Keys**

To create a foreign key relationship between two tables:

```ruby
add_reference :posts, :user, foreign_key: true
```

This adds a `user_id` column to the `posts` table and creates a foreign key constraint that ensures the `user_id` in `posts` matches a valid `id` in the `users` table.

### **7. Writing Complex Migrations**

While Rails migrations are simple for basic changes, sometimes you may need more complex database operations. For such cases, you can use the `execute` method to run raw SQL queries directly in your migrations.

For example, to add a column with a default value based on a custom SQL expression:

```ruby
class AddDiscountToProducts < ActiveRecord::Migration[6.0]
  def change
    add_column :products, :discount, :decimal
    execute "UPDATE products SET discount = 0.10"
  end
end
```

### **8. Managing Schema Versions**

Each time a migration is run, Rails keeps track of the applied migrations in a table called `schema_migrations`. This table contains the version number (timestamp) of each migration.

You can check which migrations have been applied by inspecting the `schema_migrations` table or running:

```bash
rails db:migrate:status
```

This will show a list of all migrations and their status (whether they have been applied or not).

### **9. The Schema File**

After running migrations, Rails generates a file called `db/schema.rb`. This file is a Ruby representation of the current database schema. It's used to keep the database schema in sync across environments and provides an easy way to see the structure of the database.

- You should not manually modify the `schema.rb` file. Instead, always create and run migrations.
- If you want to reset the schema, you can run `rails db:schema:load`.

### **Summary**

- **Migrations** allow you to modify the database schema in a structured way.
- Use the `rails generate migration` command to create migration files.
- Migrations are version-controlled and can be rolled back if necessary.
- Common operations include creating, altering, and removing tables and columns, adding indexes, and defining relationships between tables.
