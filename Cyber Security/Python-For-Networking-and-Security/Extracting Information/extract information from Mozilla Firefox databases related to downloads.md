The provided Python script is designed to extract information from Mozilla Firefox databases related to downloads, cookies, and browsing history. It connects to the SQLite databases used by Firefox to store this information and retrieves relevant data. Here's a breakdown of the script:

```python
#!/usr/bin/env python3

import sqlite3
import os

def getDownloads(downloadDB):
    try:
        # Connect to the downloads database
        connection = sqlite3.connect(downloadDB)
        cursor = connection.cursor()
        
        # Execute a query to retrieve download information
        cursor.execute('SELECT name, source, datetime(endTime/1000000,\'unixepoch\') FROM moz_downloads;')
        
        # Print the downloaded files information
        print('\n[*] --- Files Downloaded --- ')
        for row in cursor:
            print('[+] File: ' + str(row[0]) + ' from source: ' + str(row[1]) + ' at: ' + str(row[2]))
    except Exception as exception:
        print('\n[*] Error reading moz_downloads database ', exception)

def getCookies(cookiesDB):
    try:
        # Connect to the cookies database
        connection = sqlite3.connect(cookiesDB)
        cursor = connection.cursor()
        
        # Execute a query to retrieve cookie information
        cursor.execute('SELECT host, name, value FROM moz_cookies')

        # Print the cookie information
        print('\n[*] -- Found Cookies --')
        for row in cursor:
            print('[+] Host: ' + str(row[0]) + ', Cookie: ' + str(row[1]) + ', Value: ' + str(row[2]))
    except Exception as exception:
        print('\n[*] Error reading moz_cookies database ', exception)

def getHistory(placesDB):
    try:
        # Connect to the browsing history database
        connection = sqlite3.connect(placesDB)
        cursor = connection.cursor()
        
        # Execute a query to retrieve browsing history information
        cursor.execute("select url, datetime(visit_date/1000000, 'unixepoch') from moz_places, moz_historyvisits where visit_count > 0 and moz_places.id== moz_historyvisits.place_id;")
        
        # Print the browsing history information
        print('\n[*] -- Found History --')
        for row in cursor:
            print('[+] ' + str(row[1]) + ' - Visited: ' + str(row[0]))
    except Exception as exception:
        print('\n[*] Error reading moz_places, moz_historyvisits databases ', exception)

def main():
    # Check if the required SQLite databases exist and extract information
    if os.path.isfile('downloads.sqlite'):
        getDownloads('downloads.sqlite')
    else:
        print('[!] downloads.sqlite not found ')
    
    if os.path.isfile('cookies.sqlite'):
        getCookies('cookies.sqlite')
    else:
        print('[!] cookies.sqlite not found ')
    
    if os.path.isfile('places.sqlite'):
        getHistory('places.sqlite')
    else:
        print('[!] places.sqlite not found: ')

if __name__ == '__main__':
    main()
```

Explanation:

1. **`getDownloads` Function:**
   - Connects to the SQLite database storing download information (`moz_downloads`).
   - Executes a query to retrieve download details, including file name, source, and download time.
   - Prints the downloaded files' information.

2. **`getCookies` Function:**
   - Connects to the SQLite database storing cookie information (`moz_cookies`).
   - Executes a query to retrieve cookie details, including host, name, and value.
   - Prints the cookie information.

3. **`getHistory` Function:**
   - Connects to the SQLite databases storing browsing history information (`moz_places` and `moz_historyvisits`).
   - Executes a query to retrieve browsing history details, including URL and visit time.
   - Prints the browsing history information.

4. **`main` Function:**
   - Checks if the required SQLite databases exist (`downloads.sqlite`, `cookies.sqlite`, and `places.sqlite`).
   - Calls the corresponding functions to extract and print information from each database.

5. **`if __name__ == '__main__':` Block:**
   - Calls the `main` function when the script is executed directly.

Note: This script assumes that the Firefox databases (`downloads.sqlite`, `cookies.sqlite`, and `places.sqlite`) are present in the same directory as the script. Adjust file paths as needed. Also, be aware of privacy and legal considerations when handling user data.
