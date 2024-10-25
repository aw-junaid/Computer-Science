The `uniq` command in Linux is used to remove or display consecutive duplicate lines from a sorted file. It is a simple but powerful tool for identifying and processing unique lines in text data.

The basic syntax of the `uniq` command is as follows:

```
uniq [options] [input_file [output_file]]
```

Here's a table explaining the main parameters and options of the `uniq` command:

| Parameter/Option  | Description                                                                 |
|-------------------|-----------------------------------------------------------------------------|
| input_file        | Specifies the name of the input file. If not provided, `uniq` reads from standard input. |
| output_file       | Specifies the name of the output file to write the results. If not provided, the results are displayed on the standard output. |
| -c, --count       | Prefix lines with the number of occurrences.                                |
| -d, --repeated    | Only output duplicate lines, skipping unique lines.                         |
| -i, --ignore-case | Ignore differences in case when comparing lines.                            |
| -u, --unique      | Only output unique lines, skipping duplicate lines.                         |
| --help            | Display help and exit.                                                      |
| --version         | Output version information and exit.                                       |

Now, let's see some examples of how to use the `uniq` command:

1. Remove consecutive duplicate lines from a sorted file:

```bash
cat sorted_file.txt | uniq
```

This will display only the unique lines from the `sorted_file.txt`.

2. Display only the duplicate lines (skip unique lines):

```bash
cat sorted_file.txt | uniq -d
```

This will display only the duplicate lines from the `sorted_file.txt`.

3. Prefix lines with the number of occurrences:

```bash
cat sorted_file.txt | uniq -c
```

This will display the number of occurrences of each unique line in the `sorted_file.txt`.

4. Ignore differences in case when comparing lines:

```bash
cat sorted_file.txt | uniq -i
```

This will treat lines with the same characters but different cases as duplicates and remove them.

5. Only output unique lines (skip duplicate lines):

```bash
cat unsorted_file.txt | sort | uniq -u
```

This will sort the `unsorted_file.txt` file, then display only the unique lines from the sorted file.

6. Save the unique lines to an output file:

```bash
sort unsorted_file.txt | uniq > unique_lines.txt
```

This will sort the `unsorted_file.txt` file, remove duplicate lines, and save the unique lines in `unique_lines.txt`.

The `uniq` command is particularly useful when working with sorted text files and can help streamline data processing and analysis tasks. Note that `uniq` works most effectively with sorted input, so it is often used in conjunction with other commands like `sort`.
