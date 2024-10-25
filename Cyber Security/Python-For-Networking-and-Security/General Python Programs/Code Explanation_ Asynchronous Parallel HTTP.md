## Code Explanation: Asynchronous Parallel HTTP/2 Requests with `httpx` and `trio`

Let's break down the provided Python code that uses the `httpx` library to make asynchronous parallel HTTP/2 GET requests to Wikipedia URLs and stores the results in a dictionary.

### Importing the `httpx` and `trio` Libraries
```python
import httpx
import trio
```
- **Import Statements:**
  - Imports the `httpx` library for making HTTP requests.
  - Imports the `trio` library, an asynchronous I/O library, which is used for managing concurrent tasks.

### Initializing Results Dictionary
```python
results = {}
```
- **Initializing Results Dictionary:**
  - Initializes an empty dictionary named `results` to store the results of the asynchronous requests.

### Defining an Asynchronous Function for Fetching Results
```python
async def fetch_result(client, url, results):
    print(url)
    results[url] = await client.get(url)
```
- **Asynchronous Function for Fetching Results:**
  - Defines an asynchronous function named `fetch_result`.
  - Takes an `httpx.AsyncClient`, a URL, and the `results` dictionary as parameters.
  - Prints the URL.
  - Makes an asynchronous HTTP GET request using `await client.get(url)` and stores the response in the `results` dictionary.

### Defining the Main Asynchronous Function for Parallel Requests
```python
async def main_parallel_requests():
    async with httpx.AsyncClient(http2=True) as client:
        async with trio.open_nursery() as nursery:
            for i in range(2000, 2020):
                url = f"https://en.wikipedia.org/wiki/{i}"
                nursery.start_soon(fetch_result, client, url, results)
```
- **Main Asynchronous Function for Parallel Requests:**
  - Defines the main asynchronous function named `main_parallel_requests`.
  - Creates an `httpx.AsyncClient` with HTTP/2 support within an `async with` context.
  - Opens a `trio` nursery for managing concurrent tasks.
  - Iterates through a range of years (2000 to 2019) and starts a new task (coroutine) for each Wikipedia URL using `nursery.start_soon`.

### Running the Asynchronous Main Function with `trio.run`
```python
trio.run(main_parallel_requests)
```
- **Running the Asynchronous Main Function:**
  - Uses `trio.run` to execute the `main_parallel_requests` asynchronous function.

### Printing the Results Dictionary
```python
print(results)
```
- **Printing the Results Dictionary:**
  - Prints the populated `results` dictionary after the parallel requests have been completed.

### Summary
The provided code demonstrates making asynchronous parallel HTTP/2 GET requests to Wikipedia URLs for a range of years (2000 to 2019) using the `httpx` library and managing concurrent tasks with the `trio` library. The results of the requests are stored in the `results` dictionary, and the final dictionary is printed after the requests are completed. The asynchronous nature of the code allows for concurrent execution of multiple requests.
