# How to Revoke Privileges in PostgreSQL

Revoking privileges in PostgreSQL allows you to remove certain permissions that were previously granted to users or roles. Below is a guide on how to revoke privileges:

## 1. **Understanding Revoking Privileges**

Revoking privileges is the process of taking away specific rights or permissions from a user or role. This is important for maintaining security and access control in a database.

## 2. **Revoking Privileges**

To revoke privileges, you'll use the `REVOKE` command followed by the specific privilege and the object.

```sql
REVOKE privilege(s) ON object_name FROM user_or_role;
```

- `privilege(s)`: The privilege(s) to revoke (e.g., SELECT, INSERT, UPDATE, DELETE, etc.).
- `object_name`: The name of the object (e.g., table, sequence, function).
- `user_or_role`: The user or role from which the privileges are revoked.

## 3. **Example: Revoking SELECT Privilege**

```sql
REVOKE SELECT ON table_name FROM user_name;
```

This revokes the `SELECT` privilege on `table_name` from the user `user_name`.

## 4. **Revoking Multiple Privileges**

You can revoke multiple privileges at once by separating them with commas.

```sql
REVOKE privilege1, privilege2, ... ON object_name FROM user_or_role;
```

## 5. **Revoking Privileges on All Objects of a Type**

To revoke a privilege on all objects of a certain type (e.g., all tables), you can use the `ALL` keyword.

```sql
REVOKE ALL ON ALL TABLES IN SCHEMA schema_name FROM user_or_role;
```

This revokes all privileges on all tables in the specified schema.

## 6. **Viewing Privileges**

You can view the privileges granted on an object by using the `\dp` meta-command in psql.

```sql
\dp object_name
```

## 7. **Revoking Privileges on Sequences**

For sequences, you need to revoke USAGE and SELECT privileges separately.

```sql
REVOKE USAGE, SELECT ON SEQUENCE sequence_name FROM user_or_role;
```

## 8. **Revoking Privileges on Functions**

Privileges can also be revoked on functions.

```sql
REVOKE EXECUTE ON FUNCTION function_name(argument_types) FROM user_or_role;
```

## 9. **Using `CASCADE`**

If you want to also revoke the privilege from objects that depend on the current object, you can use the `CASCADE` option.

```sql
REVOKE privilege(s) ON object_name FROM user_or_role CASCADE;
```

## 10. **Granting Privileges Back**

Remember, if you revoke a privilege and later decide to grant it back, you can use the `GRANT` command again.

## 11. **Revoking `WITH GRANT OPTION`**

If a privilege was initially granted with the `WITH GRANT OPTION`, it can be revoked using the `GRANTED BY` clause.

```sql
REVOKE privilege ON object_name FROM user_or_role GRANTED BY grantor;
```

This revokes the privilege granted by a specific user.

By following these steps, you can effectively revoke privileges in PostgreSQL to control access to your database objects.
