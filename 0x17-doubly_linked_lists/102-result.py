#!/usr/bin/python3

largest_palindrome = 0

for x in range(100, 1000):
    for y in range(100, 1000):
        result = x * y
        str_result = str(result)
        if str_result == str_result [::-1] and result > largest_palindrome:
            largest_palindrome = result

with open("102-result", "w") as file:
    file.write(str(largest_palindrome))
