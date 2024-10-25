### Code Explanation: Asynchronous HTTP/2 GET Request with `httpx`

Let's break down the provided Python code that uses the `httpx` library to make an asynchronous HTTP/2 GET request to "https://www.google.es" and prints information about the response.

### Importing the `httpx` Library and `asyncio` Module
```python
import httpx
import asyncio
```
- **Import Statements:**
  - Imports the `httpx` library for making HTTP requests.
  - Imports the `asyncio` module for handling asynchronous operations.

### Defining an Asynchronous Function
```python
async def resquest_http2():
```
- **Asynchronous Function:**
  - Defines an asynchronous function named `resquest_http2` using the `async def` syntax.

### Creating an `httpx` AsyncClient with HTTP/2 Support
```python
    async with httpx.AsyncClient(http2=True) as client:
```
- **Creating an `httpx` AsyncClient with HTTP/2:**
  - Uses `httpx.AsyncClient` to create an asynchronous HTTP client within an `async with` context.
  - The `http2=True` parameter enables support for the HTTP/2 protocol.

### Making an Asynchronous HTTP/2 GET Request
```python
        response = await client.get("https://www.google.es")
```
- **Asynchronous HTTP/2 GET Request:**
  - Makes an asynchronous HTTP/2 GET request to "https://www.google.es" using `await client.get()`.
  - Stores the response in the `response` variable.

### Printing the Response Object and HTTP Version
```python
        print(response)
        print(response.http_version)
```
- **Printing Response Information:**
  - Prints the entire `httpx.Response` object, which includes information about the HTTP response.
  - Prints the HTTP version used in the response (e.g., "HTTP/1.1" or "HTTP/2").

### Running the Asynchronous Function
```python
asyncio.run(resquest_http2())
```
- **Running the Asynchronous Function:**
  - Uses `asyncio.run` to run the asynchronous function `resquest_http2()`.

### Summary
The provided code demonstrates making an asynchronous HTTP/2 GET request to "https://www.google.es" using the `httpx` library. The use of `http2=True` in the `httpx.AsyncClient` configuration enables support for the HTTP/2 protocol. The code prints information about the HTTP response, including the response object and the HTTP version used. The entire asynchronous operation is executed using `asyncio.run()`.
