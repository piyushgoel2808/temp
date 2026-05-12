class ReverseWords:
    def __init__(self, text):
        self.text = text

    def reverse_word_by_word(self):
        words = self.text.split()
        words.reverse()
        return " ".join(words)


if __name__ == "__main__":
    s = input("Enter a string: ")
    obj = ReverseWords(s)
    print("Reversed string word by word:", obj.reverse_word_by_word())
