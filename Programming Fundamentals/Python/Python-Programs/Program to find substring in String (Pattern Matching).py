def find_substring(s, sub):
    # Get the length of the substring to search for
    sub_len = len(sub)

    # Loop through the string to search for the substring
    for i in range(len(s) - sub_len + 1):
        # If the substring matches the current section of the string, return True
        if s[i:i+sub_len] == sub:
            return True

    # If the substring is not found, return False
    return False

# Example usage
s = "The quick brown fox jumps over the lazy dog"
sub = "fox"
if find_substring(s, sub):
    print(f"'{sub}' is a substring of '{s}'")
else:
    print(f"'{sub}' is not a substring of '{s}'")
