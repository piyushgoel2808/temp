def special_numbers(start=1000, end=2000):
    result = []
    for num in range(start, end + 1):
        if num % 7 == 0 and num % 5 != 0:
            result.append(num)
    return result


if __name__ == "__main__":
    nums = special_numbers(1000, 2000)
    print("Numbers divisible by 7 but not multiple of 5:")
    print(*nums, sep=", ")
