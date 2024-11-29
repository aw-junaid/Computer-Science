### Perl - Directories

Perl provides functions to manage directories, allowing you to create, read, delete, and modify directories on the file system. Perl's directory handling functions are easy to use and make it simple to navigate and manipulate directories.

---

### 1. **Opening and Reading Directories**

To read the contents of a directory, first open the directory with `opendir`, then read its contents with `readdir`, and finally close it with `closedir`.

#### Syntax for `opendir`, `readdir`, and `closedir`

```perl
opendir(DIRHANDLE, "directory_path") or die "Cannot open directory: $!";
my @files = readdir(DIRHANDLE);
closedir(DIRHANDLE);
```

- **`opendir`** opens a directory and associates it with a directory handle.
- **`readdir`** reads the contents of the directory and returns a list of files and directories within.
- **`closedir`** closes the directory handle.

#### Example: Reading Directory Contents

```perl
opendir(my $dir, ".") or die "Cannot open directory: $!";
while (my $file = readdir($dir)) {
    print "$file\n";
}
closedir($dir);
```

This script lists all files and subdirectories in the current directory (`.`).

---

### 2. **Filtering Directory Contents**

Typically, you want to exclude special entries like `.` (current directory) and `..` (parent directory).

```perl
opendir(my $dir, ".") or die "Cannot open directory: $!";
my @files = grep { !/^\.\.?$/ } readdir($dir);
closedir($dir);

foreach my $file (@files) {
    print "$file\n";
}
```

This code lists all items in the current directory, excluding `.` and `..`.

---

### 3. **Creating Directories**

To create a new directory, use the `mkdir` function.

```perl
mkdir("new_dir") or die "Cannot create directory: $!";
```

You can also specify permissions (in octal notation) when creating a directory:

```perl
mkdir("new_dir", 0755) or die "Cannot create directory: $!";
```

In this example, `0755` sets the directory permissions to allow the owner to read, write, and execute, while others can only read and execute.

---

### 4. **Deleting Directories**

To delete an empty directory, use the `rmdir` function.

```perl
rmdir("new_dir") or die "Cannot remove directory: $!";
```

Note: `rmdir` only works on empty directories. If the directory is not empty, delete its contents first.

---

### 5. **Changing Directories**

To change the current working directory, use the `chdir` function.

```perl
chdir("/path/to/directory") or die "Cannot change directory: $!";
```

This changes the current working directory to the specified path.

---

### 6. **Getting the Current Working Directory**

To retrieve the current working directory, use `cwd` from the `Cwd` module.

```perl
use Cwd;
my $current_dir = cwd();
print "Current directory is: $current_dir\n";
```

Alternatively, `getcwd` (also from `Cwd`) serves the same purpose.

---

### 7. **Recursive Directory Operations**

Perl’s `File::Find` module allows you to perform operations on files and directories recursively, which is helpful for tasks like listing all files in a directory tree.

#### Example: Listing All Files Recursively

```perl
use File::Find;

sub process_file {
    print "$File::Find::name\n";  # Full path of each file
}

find(\&process_file, "path/to/directory");
```

This script lists all files and directories under `"path/to/directory"`.

---

### 8. **Copying and Removing Directory Trees**

Perl’s `File::Copy::Recursive` module makes it easy to copy or remove entire directory trees.

#### Copying a Directory Tree

```perl
use File::Copy::Recursive qw(dircopy);

dircopy("source_dir", "destination_dir") or die "Cannot copy directory: $!";
```

#### Removing a Directory Tree

```perl
use File::Path qw(remove_tree);

remove_tree("directory_to_delete") or die "Cannot remove directory tree: $!";
```

`remove_tree` removes a directory along with all its contents.

---

### 9. **Checking Directory Properties**

Perl's **file test operators** work with directories as well as files. For example:

```perl
my $dir = "some_directory";

if (-d $dir) {
    print "$dir is a directory.\n";
}

if (-r $dir) {
    print "$dir is readable.\n";
}

if (-w $dir) {
    print "$dir is writable.\n";
}
```

These operators allow you to verify if a directory exists (`-d`), is readable (`-r`), or writable (`-w`).

---

### Summary of Perl Directory Operations

| **Function**                  | **Description**                                          |
|-------------------------------|----------------------------------------------------------|
| `opendir`, `readdir`, `closedir` | Open, read, and close directories.                  |
| `mkdir`                       | Creates a new directory.                                |
| `rmdir`                       | Deletes an empty directory.                             |
| `chdir`                       | Changes the current working directory.                  |
| `cwd` / `getcwd`              | Gets the current working directory path.                |
| `File::Find`                  | Recursively performs operations on directories and files.|
| `File::Copy::Recursive`       | Provides functions to copy entire directories.          |
| `File::Path`                  | Allows recursive deletion of directory trees.           |
| File Test Operators           | Checks properties like existence, readability, writability.|

Perl's directory management capabilities make it a practical tool for automating file system tasks and building file-oriented scripts.
