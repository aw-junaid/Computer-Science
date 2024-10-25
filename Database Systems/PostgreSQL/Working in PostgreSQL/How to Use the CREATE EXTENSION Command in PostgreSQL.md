The `CREATE EXTENSION` command in PostgreSQL is used to add new functionality to the database by installing additional modules or extensions. These extensions can provide additional data types, functions, operators, and more. Here's a guide on how to use the `CREATE EXTENSION` command:

## 1. **Basic Usage**

To create and install an extension, use the following syntax:

```sql
CREATE EXTENSION extension_name;
```

For example, to install the `hstore` extension:

```sql
CREATE EXTENSION hstore;
```

## 2. **Specifying a Schema**

You can specify a schema where the extension will be installed:

```sql
CREATE EXTENSION extension_name SCHEMA schema_name;
```

For example, to install the `hstore` extension in the schema `public`:

```sql
CREATE EXTENSION hstore SCHEMA public;
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

## 5. **Checking Installed Versions**

You can check the installed version of an extension using:

```sql
SELECT * FROM pg_extension_versions WHERE extname = 'extension_name';
```

Replace `extension_name` with the actual name of the extension.

## 6. **Updating an Extension**

If a newer version of an extension is available, you can update it:

```sql
ALTER EXTENSION extension_name UPDATE TO 'new_version';
```

## 7. **Removing an Extension**

To remove an installed extension, use the following command:

```sql
DROP EXTENSION extension_name;
```

## 8. **Viewing Extension Details**

You can view detailed information about an extension using:

```sql
SELECT * FROM pg_extension WHERE extname = 'extension_name';
```

## 9. **Viewing Extension Functions**

You can see the functions provided by an extension using:

```sql
SELECT proname, prosrc FROM pg_proc WHERE pronamespace = 'extension_namespace';
```

Replace `extension_namespace` with the actual namespace of the extension.

## 10. **Handling Extension Dependencies**

Some extensions may have dependencies on other extensions. When you create an extension, PostgreSQL will automatically install any required dependencies.

By following these steps, you can effectively use the `CREATE EXTENSION` command in PostgreSQL to add new functionality to your database. Extensions provide a way to extend the capabilities of PostgreSQL and tailor it to your specific needs. Remember to consult the documentation of each extension for specific installation instructions and usage details.
