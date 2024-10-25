To calculate the time duration or difference between two `datetime` objects in Python, you can subtract one `datetime` object from another. This will give you a `timedelta` object representing the difference in days, seconds, and microseconds. Here's how you can calculate the time between two `datetime` objects:

```python
from datetime import datetime, timedelta

# Create two datetime objects
start_datetime = datetime(2023, 8, 11, 10, 0, 0)
end_datetime = datetime(2023, 8, 11, 15, 30, 0)

# Calculate the time difference
time_difference = end_datetime - start_datetime

# Access the components of the timedelta object
days = time_difference.days
seconds = time_difference.seconds
microseconds = time_difference.microseconds

# Calculate the total time duration in seconds
total_seconds = time_difference.total_seconds()

print("Time difference:", time_difference)
print("Days:", days)
print("Seconds:", seconds)
print("Microseconds:", microseconds)
print("Total seconds:", total_seconds)
```

In the example above, we first create two `datetime` objects, `start_datetime` and `end_datetime`. We then calculate the time difference by subtracting `start_datetime` from `end_datetime`, which results in a `timedelta` object `time_difference`.

You can access the individual components of the `timedelta` object using attributes like `.days`, `.seconds`, and `.microseconds`.

Additionally, we calculate the total time duration in seconds using the `total_seconds()` method of the `timedelta` object.

This approach allows you to accurately calculate the time duration between two `datetime` objects, including days, seconds, and microseconds.
