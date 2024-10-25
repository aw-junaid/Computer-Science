Operator precedence in Python determines the order in which operators are evaluated when an expression contains multiple operators. Here are some examples illustrating operator precedence:

```python
# Example 1
result = 5 + 3 * 2
# Multiplication is evaluated before addition: 3 * 2 = 6, then 5 + 6 = 11
print(result)  # Output: 11

# Example 2
result = (5 + 3) * 2
# Parentheses are evaluated first: 5 + 3 = 8, then 8 * 2 = 16
print(result)  # Output: 16

# Example 3
result = 10 / 2 + 3
# Division is evaluated before addition: 10 / 2 = 5.0, then 5.0 + 3 = 8.0
print(result)  # Output: 8.0

# Example 4
result = 10 // 3
# Integer division truncates the decimal part: 10 // 3 = 3
print(result)  # Output: 3

# Example 5
result = 2 ** 3 + 1
# Exponentiation is evaluated before addition: 2 ** 3 = 8, then 8 + 1 = 9
print(result)  # Output: 9

# Example 6
result = 1 + 2 > 3 and 4 + 5 > 8
# Comparison and logical AND operators have higher precedence than logical AND
# 1 + 2 > 3 is True, and 4 + 5 > 8 is True, so the expression evaluates to True
print(result)  # Output: True

# Example 7
result = 1 + 2 > 3 or 4 + 5 > 8
# Comparison and logical OR operators have higher precedence than logical OR
# 1 + 2 > 3 is True, so the entire expression evaluates to True
print(result)  # Output: True
```

These examples demonstrate how operator precedence affects the order of evaluation in Python expressions. Parentheses can be used to explicitly control the order of operations and override default precedence rules.
