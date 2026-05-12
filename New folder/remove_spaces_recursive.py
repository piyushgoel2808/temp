def remove_spaces_recursive(text):
    if text == "":
        return ""
    if text[0] == " ":
        return remove_spaces_recursive(text[1:])
    return text[0] + remove_spaces_recursive(text[1:])


if __name__ == "__main__":
    s = input("Enter a string: ")
    print("String without spaces:", remove_spaces_recursive(s))
