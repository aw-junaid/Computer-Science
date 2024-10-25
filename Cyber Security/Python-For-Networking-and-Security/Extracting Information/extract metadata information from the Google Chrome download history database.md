This Python script is designed to extract metadata information from the Google Chrome download history database. The script connects to the specified SQLite database (which stores Chrome download history) and retrieves details such as the target path, referrer, start time, end time, and received bytes for each download entry. Below is an explanation of the code:

```python
#!usr/bin/env python3

import sqlite3
import datetime
import optparse

def fixDate(timestamp):
    # Chrome stores timestamps in the number of microseconds since Jan 1, 1601.
    # To convert, we create a datetime object for Jan 1, 1601...
    epoch_start = datetime.datetime(1601, 1, 1)
    # Create an object for the number of microseconds in the timestamp
    delta = datetime.timedelta(microseconds=int(timestamp))
    # And return the sum of the two.
    return epoch_start + delta

def getMetadataHistoryFile(locationHistoryFile):
    # Connect to the SQLite database
    sql_connect = sqlite3.connect(locationHistoryFile)
    
    # Execute a query to retrieve download metadata
    for row in sql_connect.execute('SELECT target_path, referrer, start_time, end_time, received_bytes FROM downloads;'):
        print("Download:", row[0].encode('utf-8'))
        print("\tFrom:", str(row[1]))
        print("\tStarted:", str(fixDate(row[2])))
        print("\tFinished:", str(fixDate(row[3])))
        print("\tSize:", str(row[4]))

def main():
    # Parse command-line options
    parser = optparse.OptionParser('--location <target location>')
    parser.add_option('--location', dest='location', type='string', help='specify target location')
    (options, args) = parser.parse_args()
    location = options.location
    
    # Call the function to retrieve metadata from the specified location history file
    getMetadataHistoryFile(location)

if __name__ == '__main__':
    main()
```

Explanation:

1. **`fixDate` Function:**
   - Converts Chrome timestamps (in microseconds since Jan 1, 1601) to a human-readable datetime format.
   - Takes a timestamp as input and returns a datetime object.

2. **`getMetadataHistoryFile` Function:**
   - Connects to the SQLite database specified by the `locationHistoryFile` parameter.
   - Executes a query to retrieve download metadata from the `downloads` table.
   - Prints information such as target path, referrer, start time, end time, and received bytes for each download entry.

3. **`main` Function:**
   - Uses the `optparse` module to parse command-line options.
   - Calls the `getMetadataHistoryFile` function with the specified target location.

4. **Command-Line Usage:**
   - The script expects the user to provide the target location as a command-line argument using the `--location` option.

5. **`if __name__ == '__main__':` Block:**
   - Calls the `main` function when the script is executed directly.

Note: Ensure you have the necessary permissions to access and analyze the specified Chrome download history database. Additionally, adapt the script to the specific paths and structure of your Chrome data on your system.
