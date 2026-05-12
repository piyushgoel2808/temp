def generate_natural_numbers(n):
    return list(range(1, n + 1))


if __name__ == "__main__":
    n = int(input("Enter N: "))
    if n <= 0:
        print("Please enter a positive integer.")
    else:
        print("First", n, "natural numbers:")
        print(*generate_natural_numbers(n))
