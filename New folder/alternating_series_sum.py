import math


def series_sum(x, n):
    total = 1.0

    # Terms: 1 - x^2/2! + x^4/4! - x^6/6! + ... up to n (even powers)
    for power in range(2, n + 1, 2):
        term = (x ** power) / math.factorial(power)
        if (power // 2) % 2 == 1:
            total -= term
        else:
            total += term

    return total


if __name__ == "__main__":
    x = float(input("Enter x: "))
    n = int(input("Enter n (even): "))
    if n < 0 or n % 2 != 0:
        print("Please enter a non-negative even n.")
    else:
        print("Sum of series:", series_sum(x, n))
