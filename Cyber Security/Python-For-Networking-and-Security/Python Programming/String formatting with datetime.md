String formatting with `datetime` objects in Python allows you to represent dates and times in a specific format. You can use the `strftime` method (string format time) of the `datetime` module to achieve this. The `strftime` method takes a format string as an argument and returns a formatted string representation of the `datetime` object.

Here are some common format codes you can use with `strftime`:

- `%Y`: Year with century as a decimal number (e.g., `2023`)
- `%m`: Month as a zero-padded decimal number (e.g., `03` for March)
- `%d`: Day of the month as a zero-padded decimal number (e.g., `09`)
- `%H`: Hour (24-hour clock) as a zero-padded decimal number (e.g., `13` for 1 PM)
- `%M`: Minute as a zero-padded decimal number
- `%S`: Second as a zero-padded decimal number

Here's an example of formatting a `datetime` object using `strftime`:

```python
from datetime import datetime

# Create a datetime object
now = datetime.now()

# Format the datetime object
formatted_date = now.strftime("%Y-%m-%d %H:%M:%S")
print(formatted_date)  # Output: "2023-08-11 14:30:00"
```

You can customize the format string to achieve the desired format for your date and time representation. Additionally, the `datetime` module provides other formatting options, such as `strptime` for parsing strings into `datetime` objects.

For a complete list of format codes and more formatting options, you can refer to the official Python documentation on `strftime` and `strptime`:
- [strftime() and strptime() Format Codes](https://docs.python.org/3/library/datetime.html#strftime-strptime-behavior)
- [datetime - Basic date and time types](https://docs.python.org/3/library/datetime.html)
