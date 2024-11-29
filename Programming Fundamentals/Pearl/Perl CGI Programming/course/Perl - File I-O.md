### Perl - File I/O

Perl provides a robust set of file handling functions to create, read, write, and manage files. File I/O in Perl is straightforward, making it ideal for scripts that manipulate data or interact with file systems.

---

### 1. **Opening and Closing Files**

To open a file, use the `open` function, specifying the file mode and filehandle. Once you’re done with a file, always close it with the `close` function to release system resources.

#### Syntax of `open`:

```perl
open(FILEHANDLE, "MODE", "filename") or die "Cannot open file: $!";
```

Alternatively, the `open` function can be used with a three-argument format (recommended for better readability):

```perl
open(my $fh, "<", "filename") or die "Cannot open file: $!";
```

- `FILEHANDLE` or `$fh`: Name of the filehandle.
- `"MODE"`: File mode (`<` for read, `>` for write, `>>` for append).
- `"filename"`: Name of the file.

#### Example: Opening a File for Reading

```perl
open(my $fh, "<", "data.txt") or die "Cannot open file: $!";
# Process file content here
close($fh);
```

---

### 2. **File Modes**

| **Mode** | **Symbol** | **Description**                  |
|----------|------------|----------------------------------|
| Read     | `<`        | Opens the file for reading only. |
| Write    | `>`        | Creates a new file or overwrites an existing file for writing. |
| Append   | `>>`       | Opens the file for appending, starting at the end of the file. |
| Read/Write | `+<`     | Opens the file for both reading and writing. |
| Write/Read | `+>`     | Creates or overwrites the file for both reading and writing. |
| Append/Read | `+>>`   | Opens the file for both appending and reading. |

---

### 3. **Reading from a File**

Once a file is opened for reading, you can use various methods to read its contents.

#### Reading Line by Line

```perl
open(my $fh, "<", "data.txt") or die "Cannot open file: $!";

while (my $line = <$fh>) {
    print $line;  # Print each line from the file
}

close($fh);
```

#### Reading the Entire File at Once

To read an entire file into a scalar variable:

```perl
open(my $fh, "<", "data.txt") or die "Cannot open file: $!";
my $content = do { local $/; <$fh> };  # Read entire file into $content
close($fh);
```

---

### 4. **Writing to a File**

To write to a file, open it in write mode (`>`), which will create the file if it doesn’t exist or overwrite it if it does.

#### Example of Writing to a File

```perl
open(my $fh, ">", "output.txt") or die "Cannot open file: $!";

print $fh "Hello, World!\n";  # Write to the file

close($fh);
```

#### Appending to a File

To add content to the end of an existing file, open it in append mode (`>>`).

```perl
open(my $fh, ">>", "output.txt") or die "Cannot open file: $!";

print $fh "This is an appended line.\n";  # Append to the file

close($fh);
```

---

### 5. **File Test Operators**

Perl provides **file test operators** to check attributes like file existence, size, readability, and writability.

| **Operator** | **Description**                   |
|--------------|-----------------------------------|
| `-e`         | File exists                       |
| `-r`         | File is readable                  |
| `-w`         | File is writable                  |
| `-x`         | File is executable                |
| `-z`         | File is empty                     |
| `-s`         | File size in bytes                |
| `-f`         | File is a regular file            |
| `-d`         | File is a directory               |
| `-T`         | File is a text file               |
| `-B`         | File is a binary file             |

#### Example of Using File Test Operators

```perl
my $file = "data.txt";

if (-e $file) {
    print "File exists.\n";
    print "File size: ", -s $file, " bytes\n" if -s $file;
} else {
    print "File does not exist.\n";
}
```

---

### 6. **Working with Filehandles and File Paths**

Using filehandles allows for greater flexibility, especially when managing multiple files. You can also use relative and absolute paths to open files.

#### Example of Using File Paths

```perl
my $relative_path = "data/notes.txt";
my $absolute_path = "/home/user/documents/notes.txt";

open(my $fh, "<", $relative_path) or die "Cannot open file: $!";
# Process file content here
close($fh);
```

---

### 7. **File Locking**

Perl provides the `flock` function to lock files to prevent concurrent access issues. You typically use `flock` when multiple programs or users might try to access the same file simultaneously.

#### Locking Modes

| **Mode**      | **Symbol**               | **Description**                        |
|---------------|--------------------------|----------------------------------------|
| Shared Lock   | `LOCK_SH`                | Allows multiple readers but no writers |
| Exclusive Lock| `LOCK_EX`                | Allows only one writer                |
| Non-blocking  | `LOCK_NB`                | Attempts lock without blocking        |
| Unlock        | `LOCK_UN`                | Releases the lock                     |

#### Example of File Locking

```perl
use Fcntl qw(:flock);

open(my $fh, ">>", "data.txt") or die "Cannot open file: $!";
flock($fh, LOCK_EX) or die "Cannot lock file: $!";

print $fh "New line with exclusive lock.\n";

flock($fh, LOCK_UN);  # Unlock the file
close($fh);
```

In this example, `LOCK_EX` ensures that only one process can write to the file at a time.

---

### 8. **Reading and Writing Binary Files**

When working with binary files, use the `binmode` function to prevent Perl from interpreting characters (e.g., newline conversions).

#### Example of Reading a Binary File

```perl
open(my $fh, "<:raw", "image.jpg") or die "Cannot open file: $!";
binmode($fh);

my $data;
while (read($fh, my $buffer, 1024)) {
    $data .= $buffer;  # Read in chunks of 1024 bytes
}

close($fh);
```

#### Example of Writing a Binary File

```perl
open(my $fh, ">:raw", "output.bin") or die "Cannot open file: $!";
binmode($fh);

print $fh $data;  # Write binary data to file

close($fh);
```

---

### 9. **Reading and Writing CSV Files**

Perl has modules like `Text::CSV` that make working with CSV files easier.

```perl
use Text::CSV;

my $csv = Text::CSV->new();
open(my $fh, "<", "data.csv") or die "Cannot open file: $!";

while (my $row = $csv->getline($fh)) {
    print join(", ", @$row), "\n";
}

close($fh);
```

This code reads a CSV file line by line and prints each row.

---

### Summary of Perl File I/O

| **Function/Concept** | **Description**                                                 |
|----------------------|-----------------------------------------------------------------|
| **open**             | Opens a file with a specified mode (`<`, `>`, `>>`).            |
| **close**            | Closes an open filehandle.                                      |
| **read**             | Reads data from a file.                                         |
| **print**            | Writes data to a file.                                          |
| **flock**            | Locks a file for exclusive or shared access.                    |
| **binmode**          | Sets binary mode for reading or writing binary files.           |
| **File Test Operators** | Check file attributes (e.g., `-e`, `-s`, `-r`).              |
| **Text::CSV Module** | Provides functionality for handling CSV files in Perl.          |

Perl's file handling capabilities make it an efficient tool for scripting and automating data processing tasks. With support for various file modes, file locking, and the ability to handle binary files, Perl is well-suited for a wide range of file I/O tasks.
