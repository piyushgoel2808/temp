given_tuple = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

mid = len(given_tuple) // 2
first_half = given_tuple[:mid]
last_half = given_tuple[mid:]

print("First half:", *first_half)
print("Last half:", *last_half)
