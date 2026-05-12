def line_count(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        return sum(1 for _ in f)


if __name__ == "__main__":
    file1 = input("Enter first file path: ").strip()
    file2 = input("Enter second file path: ").strip()

    lines1 = line_count(file1)
    lines2 = line_count(file2)

    print(f"Total lines in {file1}: {lines1}")
    print(f"Total lines in {file2}: {lines2}")

    if lines1 == lines2:
        print("Both files have same number of lines.")
    else:
        print("Files have different number of lines.")
