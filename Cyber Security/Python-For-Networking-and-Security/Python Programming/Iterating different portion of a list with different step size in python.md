To iterate over different portions of a list with different step sizes in Python, you can use nested loops or a combination of slicing and loop controls. Here are a few examples:

**Using Nested Loops:**

```python
my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

for start in range(0, len(my_list), 3):
    for i in range(start, min(start + 3, len(my_list))):
        print(my_list[i], end=" ")
    print()
```

**Using Slicing and Loop Control:**

```python
my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

start = 0
while start < len(my_list):
    end = min(start + 3, len(my_list))
    for num in my_list[start:end]:
        print(num, end=" ")
    print()
    start = end
```

In both examples, we divide the list into portions of size 3 and iterate over each portion with a different step size. The first example uses nested loops, and the second example uses slicing and a `while` loop.

Please note that these examples assume that the list size is evenly divisible by the desired portion size. If the list size is not evenly divisible, you might need to adjust the logic accordingly to handle the remaining elements.
