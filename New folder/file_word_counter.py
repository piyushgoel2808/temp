def word_count(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        text = f.read()
    return len(text.split())


if __name__ == "__main__":
    file1 = input("Enter first file path: ").strip()
    file2 = input("Enter second file path: ").strip()

    words1 = word_count(file1)
    words2 = word_count(file2)

    print(f"Total words in {file1}: {words1}")
    print(f"Total words in {file2}: {words2}")

    if words1 == words2:
        print("Both files have same number of words.")
    else:
        print("Files have different number of words.")
