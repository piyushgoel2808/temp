def sum_even_fibonacci(limit=1000):
    a, b = 1, 2
    total = 0

    while a <= limit:
        if a % 2 == 0:
            total += a
        a, b = b, a + b

    return total


if __name__ == "__main__":
    print("Sum of even Fibonacci terms up to 1000:", sum_even_fibonacci(1000))
