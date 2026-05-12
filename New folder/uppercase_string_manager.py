class StringManager:
    def __init__(self):
        self.text = ""

    def get_String(self):
        self.text = input("Enter a string: ")

    def print_String(self):
        print("Upper case string:", self.text.upper())


if __name__ == "__main__":
    obj = StringManager()
    obj.get_String()
    obj.print_String()
