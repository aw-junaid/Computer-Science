To convert a timestamp to a `datetime` object in Python, you can use the `datetime` module. A timestamp typically represents the number of seconds (or milliseconds) since a specific reference date, often known as the "epoch." Here's how you can convert a timestamp to a `datetime` object:

```python
from datetime import datetime

# Example timestamp (in seconds since the epoch)
timestamp = 1628683800

# Convert timestamp to a datetime object
datetime_object = datetime.fromtimestamp(timestamp)

print("Timestamp:", timestamp)
print("Datetime:", datetime_object)
```

In the example above, `datetime.fromtimestamp()` is used to convert the given timestamp to a `datetime` object. The resulting `datetime` object will represent the date and time corresponding to the provided timestamp.

Keep in mind that the `fromtimestamp()` function assumes that the input timestamp is in the local time zone. If the timestamp is in UTC or another time zone, you may need to adjust the result accordingly.

If your timestamp is in milliseconds rather than seconds, you can divide the timestamp by 1000 before passing it to `fromtimestamp()`, as follows:

```python
# Example timestamp in milliseconds
timestamp_ms = 1628683800000

# Convert timestamp to a datetime object
datetime_object_ms = datetime.fromtimestamp(timestamp_ms / 1000)

print("Timestamp (ms):", timestamp_ms)
print("Datetime (ms):", datetime_object_ms)
```

By using the `datetime` module, you can easily convert timestamps to `datetime` objects and work with date and time representations in your Python programs.
