def cumulative_product(numbers):
    output = []
    product = 1

    for value in numbers:
        product *= value
        output.append(product)

    return output


if __name__ == "__main__":
    data = list(map(int, input("Enter numbers separated by space: ").split()))
    print("Cumulative product:", cumulative_product(data))
