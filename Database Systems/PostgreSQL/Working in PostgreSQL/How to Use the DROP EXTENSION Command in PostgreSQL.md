The `DROP EXTENSION` command in PostgreSQL is used to remove an installed extension from a database. This command can be useful if you no longer need the functionality provided by the extension. Here's a guide on how to use the `DROP EXTENSION` command:

## 1. **Basic Usage**

To drop an extension, use the following syntax:

```sql
DROP EXTENSION extension_name;
```

For example, to remove the `hstore` extension:

```sql
DROP EXTENSION hstore;
```

## 2. **Specifying a Schema**

You can also specify a schema when dropping an extension:

```sql
DROP EXTENSION extension_name SCHEMA schema_name;
```

For example, to drop the `hstore` extension from the schema `public`:

```sql
DROP EXTENSION hstore SCHEMA public;
```

## 3. **Checking Installed Extensions**

You can check which extensions are installed in your database by querying the `pg_extension` system catalog:

```sql
SELECT * FROM pg_extension;
```

## 4. **Listing Available Extensions**

To see a list of available extensions, you can use:

```sql
SELECT * FROM pg_available_extensions;
```

## 5. **Removing an Extension Version**

If multiple versions of an extension are installed, you can specify which version to remove:

```sql
DROP EXTENSION extension_name VERSION 'version_number';
```

Replace `extension_name` with the actual name of the extension and `version_number` with the specific version you want to remove.

## 6. **Viewing Extension Details**

You can view detailed information about an extension using:

```sql
SELECT * FROM pg_extension WHERE extname = 'extension_name';
```

## 7. **Viewing Extension Functions**

You can see the functions provided by an extension using:

```sql
SELECT proname, prosrc FROM pg_proc WHERE pronamespace = 'extension_namespace';
```

Replace `extension_namespace` with the actual namespace of the extension.

## 8. **Handling Extension Dependencies**

If an extension has dependencies on other extensions, dropping the extension will also remove any dependent extensions.

## 9. **Removing Extension Data**

Some extensions may create additional objects (tables, functions, etc.) in the database. You may need to drop these objects separately after removing the extension.

By following these steps, you can effectively use the `DROP EXTENSION` command in PostgreSQL to remove installed extensions from your database. This can be useful if you no longer need the functionality provided by an extension. Remember to consult the documentation of each extension for specific removal instructions and potential dependencies.
