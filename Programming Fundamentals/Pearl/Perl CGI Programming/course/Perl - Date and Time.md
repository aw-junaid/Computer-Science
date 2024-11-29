### Perl - Date and Time

Handling dates and times in Perl can be done using built-in functions as well as external modules, such as `Time::Local`, `Time::Piece`, and `DateTime`. Here's a guide to working with date and time in Perl:

---

### 1. **Built-in Functions for Date and Time**

#### `time` - Current Unix Timestamp
The `time` function returns the current time in seconds since the Unix epoch (January 1, 1970).

```perl
my $timestamp = time();
print "Current time in seconds since the Unix epoch: $timestamp\n";
```

#### `localtime` - Local Time
The `localtime` function returns the current date and time, broken down into an array representing various components (seconds, minutes, hours, day, month, year, weekday, etc.). If called without arguments, it returns the local time for the current time (based on `time`).

```perl
my $t = localtime;
print "Local time: $t\n";  # prints in default format like: Wed Nov 13 10:52:13 2024
```

If you want to break it down into individual components, you can do something like:

```perl
my @t = localtime();
print "Year: $t[5] + 1900\n";  # Year (years since 1900)
print "Month: $t[4] + 1\n";    # Month (0-11)
print "Day: $t[3]\n";          # Day of the month
```

#### `gmtime` - GMT Time
The `gmtime` function returns the current date and time in GMT (Greenwich Mean Time) instead of the local time zone.

```perl
my $t_gmt = gmtime;
print "GMT time: $t_gmt\n";  # prints in default format like: Wed Nov 13 15:52:13 2024
```

#### Formatting Dates with `strftime` (Using `POSIX` Module)
To format a date in a more readable way, you can use the `strftime` function, which is available via the `POSIX` module.

```perl
use POSIX qw(strftime);

my $date = strftime "%Y-%m-%d %H:%M:%S", localtime;
print "Formatted date and time: $date\n";
```

Common formatting options:
- `%Y` - Year (4 digits)
- `%m` - Month (2 digits)
- `%d` - Day of the month (2 digits)
- `%H` - Hour (24-hour clock)
- `%M` - Minute
- `%S` - Second

---

### 2. **Time::Piece Module**

The `Time::Piece` module provides a more object-oriented approach to working with time and dates.

#### Creating a `Time::Piece` Object

```perl
use Time::Piece;

my $t = localtime;
print "Current time: $t\n";  # prints current time in default format

# You can also format the time like this:
print "Formatted time: ", $t->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

#### Adding or Subtracting Time

```perl
use Time::Piece;

my $t = localtime;
my $new_time = $t + (60 * 60 * 24);  # Adds one day (60*60*24 seconds)
print "One day later: ", $new_time->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

This creates a new `Time::Piece` object that represents one day after the current time.

---

### 3. **Time::Local Module**

The `Time::Local` module is used to convert date and time into a Unix timestamp and vice versa. This is useful when working with specific dates.

#### Converting a Date to a Unix Timestamp

```perl
use Time::Local;

my $timestamp = timelocal(0, 0, 12, 1, 11, 2024);  # December 1, 2024, 12:00:00 PM
print "Unix timestamp: $timestamp\n";
```

The `timelocal` function takes the following parameters: seconds, minutes, hours, day of the month, month (0-based, i.e., January = 0), and year (since 1900).

#### Converting a Unix Timestamp to a Date

```perl
use Time::Local;

my $timestamp = 1609459200;  # Corresponds to Jan 1, 2021, 00:00:00 UTC
my @t = gmtime($timestamp);  # Converts to GMT
print "Date: ", sprintf("%04d-%02d-%02d %02d:%02d:%02d", 
                        $t[5] + 1900, $t[4] + 1, $t[3], 
                        $t[2], $t[1], $t[0]), "\n";
```

---

### 4. **DateTime Module (External Library)**

For more complex date and time manipulations, the `DateTime` module is often preferred. It provides a more advanced interface for dealing with dates, times, and time zones.

#### Installation

To use `DateTime`, you first need to install it using CPAN:

```bash
cpan install DateTime
```

#### Creating a `DateTime` Object

```perl
use DateTime;

my $dt = DateTime->now;
print "Current date and time: ", $dt->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

#### Adding Time

```perl
use DateTime;

my $dt = DateTime->now;
my $new_dt = $dt->add(days => 1);  # Adds 1 day
print "One day later: ", $new_dt->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

#### Subtracting Time

```perl
use DateTime;

my $dt = DateTime->now;
my $new_dt = $dt->subtract(days => 1);  # Subtracts 1 day
print "One day before: ", $new_dt->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

#### Converting Time Zones

```perl
use DateTime;

my $dt = DateTime->now(time_zone => 'America/New_York');
print "New York time: ", $dt->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

---

### 5. **Summary of Date and Time Handling in Perl**

- **Basic Functions**: `time`, `localtime`, `gmtime` for basic time retrieval.
- **Formatting**: Use `strftime` (with `POSIX`) or `Time::Piece` methods to format time.
- **Date and Time Manipulation**: Use `Time::Piece` for simple additions or subtractions, or `DateTime` for more complex operations.
- **Unix Timestamps**: Use `Time::Local` to convert dates to Unix timestamps or vice versa.

---

### Example: Date and Time Operations

```perl
use Time::Piece;
use DateTime;

# Current date and time
my $time = localtime;
print "Current time: $time\n";

# Format the current time
print "Formatted time: ", $time->strftime("%Y-%m-%d %H:%M:%S"), "\n";

# Add one day to the current date
my $next_day = $time + (60 * 60 * 24);
print "One day later: ", $next_day->strftime("%Y-%m-%d %H:%M:%S"), "\n";

# Using DateTime module to manipulate time
my $dt = DateTime->now;
print "DateTime now: ", $dt->strftime("%Y-%m-%d %H:%M:%S"), "\n";

# Add 5 days
my $new_dt = $dt->add(days => 5);
print "DateTime after 5 days: ", $new_dt->strftime("%Y-%m-%d %H:%M:%S"), "\n";
```

This example covers both the `Time::Piece` and `DateTime` modules to demonstrate the variety of options available for working with dates and times in Perl.
