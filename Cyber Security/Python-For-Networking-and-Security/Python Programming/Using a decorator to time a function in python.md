You can use a decorator to time the execution of a function in Python by measuring the elapsed time before and after the function call. Here's an example of how to create a decorator to time a function:

```python
import time

def timer_decorator(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        elapsed_time = end_time - start_time
        print(f"{func.__name__} took {elapsed_time:.6f} seconds to execute.")
        return result
    return wrapper

@timer_decorator
def slow_function(n):
    total = 0
    for i in range(n):
        total += i
    return total

result = slow_function(1000000)
```

In this example, the `timer_decorator` function is defined as a decorator that measures the time it takes for a function to execute. The `wrapper` function within the decorator records the start time, calls the original function, calculates the elapsed time, and then prints the result.

When you apply the `@timer_decorator` to the `slow_function`, the decorator will automatically time the execution of the function and display the elapsed time in seconds.

You can use this decorator to time any function you want by simply adding `@timer_decorator` above the function definition. This is a convenient way to measure the performance of different parts of your code.
