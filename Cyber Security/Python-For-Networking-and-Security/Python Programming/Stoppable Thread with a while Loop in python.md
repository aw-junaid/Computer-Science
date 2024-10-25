Creating a stoppable thread with a while loop in Python involves using a threading mechanism to start and stop the thread gracefully. Here's an example of how to create a stoppable thread that runs a while loop:

```python
import threading
import time

# Define a thread class that inherits from threading.Thread
class StoppableThread(threading.Thread):
    def __init__(self):
        super().__init__()
        self._stop_event = threading.Event()

    def run(self):
        while not self._stop_event.is_set():
            print("Thread is running...")
            time.sleep(1)

    def stop(self):
        self._stop_event.set()

# Create an instance of the StoppableThread class
thread = StoppableThread()

# Start the thread
thread.start()

# Wait for some time
time.sleep(5)

# Stop the thread
thread.stop()

# Wait for the thread to finish
thread.join()

print("Thread has been stopped")
```

In this example:

1. We define a `StoppableThread` class that inherits from `threading.Thread`. The `__init__` method initializes a private `_stop_event` attribute, which is an instance of `threading.Event`.

2. The `run` method contains the code to run in the thread. It runs a while loop that continues until the `_stop_event` is set.

3. The `stop` method sets the `_stop_event`, indicating that the thread should stop.

4. We create an instance of the `StoppableThread` class and start it using the `start()` method.

5. After some time (in this case, 5 seconds), we call the `stop()` method to signal the thread to stop.

6. We use the `join()` method to wait for the thread to finish.

7. Finally, we print a message indicating that the thread has been stopped.

Keep in mind that this example uses the `threading.Event` mechanism to signal the thread to stop. This allows the thread to finish its current iteration of the loop before stopping. Depending on your specific use case, you might need to handle more complex logic for graceful thread termination.
