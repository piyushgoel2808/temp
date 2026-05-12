def reverse_list(items):
    reversed_items = []
    for i in range(len(items) - 1, -1, -1):
        reversed_items.append(items[i])
    return reversed_items


if __name__ == "__main__":
    data = input("Enter elements separated by space: ").split()
    print("Reversed list:", reverse_list(data))
