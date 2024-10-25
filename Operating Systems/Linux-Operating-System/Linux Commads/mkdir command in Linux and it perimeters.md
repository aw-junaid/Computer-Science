The `mkdir` command in Linux is used to create new directories (folders) in the file system. It allows you to create one or more directories with the specified names and optionally set the directory permissions.

The basic syntax of the `mkdir` command is:

```
mkdir [options] directory_name
```

Where:
- `directory_name` is the name of the directory you want to create.

Here's a table showing some common options of the `mkdir` command:

| Option       | Description                                                                                |
|--------------|--------------------------------------------------------------------------------------------|
| `-m, --mode=MODE` | Set the permissions (mode) of the created directory in octal notation (e.g., 755, 644).  |
| `-p, --parents` | Create parent directories as needed. If a parent directory doesn't exist, it is also created. |
| `--help`     | Display help information for the `mkdir` command.                                          |

Examples:

1. Create a new directory named `documents` in the current directory:
   ```
   mkdir documents
   ```

2. Create multiple directories named `folder1`, `folder2`, and `folder3` in the current directory:
   ```
   mkdir folder1 folder2 folder3
   ```

3. Create a directory named `photos` with specific permissions (e.g., 755):
   ```
   mkdir -m 755 photos
   ```

4. Create a directory named `project/docs` and its parent directories if they don't exist:
   ```
   mkdir -p project/docs
   ```
   This command creates the directory `project` and then creates the subdirectory `docs` inside it.

5. Create a directory named `public_html` and give it specific permissions (e.g., 750):
   ```
   mkdir -m 750 public_html
   ```

6. Create a directory named `images` and display the help information for the `mkdir` command:
   ```
   mkdir images
   mkdir --help
   ```

The `mkdir` command is a simple yet essential tool for creating directories in Linux. With the `-p` option, you can create directory hierarchies without worrying about the existence of parent directories. Additionally, the `-m` option allows you to set specific permissions for the newly created directories, ensuring they have the desired access rights.
