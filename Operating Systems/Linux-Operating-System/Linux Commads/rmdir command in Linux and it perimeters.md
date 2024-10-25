The `rmdir` command in Linux is used to remove (delete) empty directories from the file system. Unlike the `rm` command, which can remove files and non-empty directories, the `rmdir` command is designed specifically to remove directories that do not contain any files or subdirectories.

The basic syntax of the `rmdir` command is:

```
rmdir [options] directory1 directory2 ... directoryN
```

Where:
- `directory1 directory2 ... directoryN` represents one or more empty directories that you want to remove.

Here's a table showing some common options of the `rmdir` command:

| Option        | Description                                                                                     |
|---------------|-------------------------------------------------------------------------------------------------|
| `--ignore-fail-on-non-empty` | Ignore directories that are not empty and do not display an error.                             |
| `--parents`   | Remove parent directories as well if they become empty after removing the specified directory. |

Examples:

1. Remove an empty directory:
   ```
   rmdir empty_directory
   ```
   This command removes the empty directory named `empty_directory`.

2. Remove multiple empty directories:
   ```
   rmdir dir1 dir2 dir3
   ```
   This command removes three empty directories: `dir1`, `dir2`, and `dir3`.

3. Remove parent directories if they become empty:
   ```
   rmdir --parents empty_dir/subdir
   ```
   This command removes `subdir` from the `empty_dir` directory and then checks if `empty_dir` becomes empty as well. If `empty_dir` is empty after removing `subdir`, it will also be removed.

4. Ignore non-empty directories:
   ```
   rmdir --ignore-fail-on-non-empty non_empty_dir
   ```
   This command attempts to remove the directory `non_empty_dir`, but if it is not empty, it does not display an error and continues.

5. Remove multiple empty directories at once:
   ```
   rmdir dir1 dir2 dir3
   ```
   This command removes three empty directories: `dir1`, `dir2`, and `dir3`.

Please note that the `rmdir` command can only remove directories that are completely empty. If a directory contains files or subdirectories, you will need to use the `rm` command with the `-r` option to recursively remove the directory and its contents. Always be cautious when using the `rmdir` command to avoid accidentally removing non-empty directories.
