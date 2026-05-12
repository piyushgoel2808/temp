def count_characters(text):
    counts = {}
    for ch in text:
        counts[ch] = counts.get(ch, 0) + 1
    return counts


if __name__ == "__main__":
    s = input("Enter a string: ")
    print("Character frequency dictionary:")
    print(count_characters(s))
