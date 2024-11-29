### Perl - Formats

In Perl, **formats** are a mechanism for formatting output in a fixed and structured way. They allow you to control how data is printed to the screen or written to files. Formats are particularly useful for generating reports or for formatting data with specific alignment, widths, and precision.

---

### 1. **What Are Perl Formats?**

A **format** in Perl is a special type of template that describes how data should be printed. It consists of a **format name** and a **format definition**. Once defined, you can apply the format by calling the `write` function.

---

### 2. **Defining a Format**

To define a format in Perl, you use the `format` keyword, followed by the name of the format and the format string, which can include special formatting codes.

#### Basic Format Definition:

```perl
format MYFORMAT =
Name: @<<<<<<<<<<<<<<<<<  Age: @<<
          $name                $age
.
```

Here:
- `MYFORMAT` is the format name.
- `@<<<<<<<<<<<<<<<<<` specifies a left-justified string with a maximum width.
- `@<<` specifies an integer with two digits.

The format definition ends with a period (`.`) on a line by itself.

---

### 3. **Using a Format**

To use a format, you simply assign the variables to the format placeholders, and then call the `write` function.

```perl
my $name = "Alice";
my $age  = 30;

format MYFORMAT =
Name: @<<<<<<<<<<<<<<<<<  Age: @<<
          $name                $age
.

write;  # This will print the formatted output
```

When you call `write`, Perl automatically applies the format and prints the formatted output to the screen.

---

### 4. **Format Modifiers**

Formats in Perl have special placeholders and modifiers to control the formatting of data:

- `@` – Specifies the field width. It controls how wide the field is.
- `<<` – Specifies how the content will be aligned. By default, it’s left-aligned.
- `>` – Right-align the content.
- `^` – Center-align the content.

#### Example with Modifiers:

```perl
format MYFORMAT =
Name: @<<<<<<<<<<<<<<<<<< Age: @>>>
        $name             $age
.

my $name = "Alice";
my $age  = 30;
write;  # Left-align name, right-align age
```

This will print:
```
Name: Alice             Age:  30
```

---

### 5. **Using `@` for Lists and Columns**

You can use the `@` symbol in formats to print multiple values in a list or column format. You can control the width of each column.

#### Example with a List:

```perl
format MYLIST =
Item No. @<<<<<  Description: @<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
         $item_no           $description
.

my @items = (
    [1, "Pen"],
    [2, "Notebook"],
    [3, "Eraser"]
);

foreach my $item (@items) {
    ($item_no, $description) = @$item;
    write;  # Apply format for each item
}
```

This will print each item in a list format, where `@<<<<<` aligns the item number and `@<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<` aligns the description.

---

### 6. **Using `FORMAT` to Create Reports**

You can create reports by combining different variables into the format string. This allows for consistent presentation of data.

#### Example Report:

```perl
format REPORT =
Product  @<<<<<<<<<<<<  Quantity  @<<  Price  @>>>
          $product          $quantity       $price
.

my $product  = "Laptop";
my $quantity = 5;
my $price    = 799.99;

write;  # Generates a nicely formatted report
```

This will print:
```
Product  Laptop          Quantity  5  Price  799.99
```

---

### 7. **Using Format for Multiline Output**

You can use the format mechanism to create multiline output. For example, the format can wrap text or create structured reports.

#### Example of a Multiline Format:

```perl
format LONGREPORT =
Order ID: @<<<<<
    $order_id

Product: @<<<<<<<<<<<<<<
    $product_name

Quantity: @<<
    $quantity

Price: @>>>
    $price
.

my $order_id      = 12345;
my $product_name  = "Smartphone";
my $quantity      = 3;
my $price         = 699.99;

write;
```

This will print:
```
Order ID: 12345
    Smartphone

Product: Smartphone
    3

Quantity: 3
    699.99
```

---

### 8. **Using Format with `SELECT` and `WRITE`**

By default, the `write` function sends the formatted output to the current output filehandle (`STDOUT`). However, you can redirect the output to another file or output stream using `select`.

```perl
open my $fh, '>', 'report.txt' or die "Cannot open file: $!";
select($fh);  # Redirect output to 'report.txt'

my $product  = "Laptop";
my $quantity = 5;
my $price    = 799.99;

write;  # Output will be written to 'report.txt'
select(STDOUT);  # Restore output to the terminal
```

This will write the formatted output to the file `report.txt` instead of the terminal.

---

### 9. **Special Format Variables**

- `$~` – Holds the name of the format used for output.
- `$^` – Holds the current filehandle used for writing the formatted output.
- `$=` – Controls the page size (for report pagination).

#### Example:

```perl
$~ = "MYFORMAT";  # Use MYFORMAT for the output
$^ = STDOUT;      # Print to STDOUT
$= = 20;           # Set page size to 20 lines

write;
```

This example uses `$~` to assign the format `MYFORMAT` to the output, `$^` to specify the output stream, and `$=` to set the page size.

---

### 10. **Page Breaks in Reports**

Perl’s format mechanism also allows you to control page breaks for generating reports with multiple pages. You can define a page break when the output reaches a specific number of lines (set using `$=`).

```perl
$~ = "MYFORMAT";  # Use MYFORMAT format
$^ = STDOUT;      # Print to STDOUT
$= = 10;           # Set page size to 10 lines per page

for (my $i = 1; $i <= 30; $i++) {
    my $item = "Item $i";
    write;
}
```

This will print 10 items per page, and a page break will occur every 10 lines.

---

### Summary of Key Format Concepts

| **Concept**                | **Explanation**                                           |
|----------------------------|-----------------------------------------------------------|
| **Format Definition**       | Use `format FORMAT_NAME = ...` to define a format.        |
| **Placeholders**            | Use `@` for field width and alignment, `<<` for left, `>>` for right, `^` for center. |
| **Using Write**             | Call `write` to apply the format to the current variables. |
| **Multiline Output**        | Formats can be used to print multiline output.            |
| **Page Breaks**             | Use `$=` to set page size and control pagination.         |
| **Output Redirection**      | Use `select` to redirect output to files.                 |
| **Special Format Variables** | `$~`, `$^`, and `$=` control format output behavior.     |

Perl’s **format** feature is a useful tool for generating reports and producing formatted output, especially when working with structured data and when you need precise control over spacing, alignment, and output appearance.
