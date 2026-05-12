def linear_search(arr, key):
    for i, value in enumerate(arr):
        if value == key:
            return i
    return -1


def binary_search(arr, key):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        if arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1


if __name__ == "__main__":
    data = list(map(int, input("Enter integers separated by space: ").split()))
    key = int(input("Enter element to search: "))

    lpos = linear_search(data, key)
    print("Linear Search:", "Found at index " + str(lpos) if lpos != -1 else "Not found")

    sorted_data = sorted(data)
    bpos = binary_search(sorted_data, key)
    print("Sorted list for Binary Search:", sorted_data)
    print("Binary Search:", "Found at sorted index " + str(bpos) if bpos != -1 else "Not found")
