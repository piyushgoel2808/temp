import matplotlib.pyplot as plt


if __name__ == "__main__":
    x = [1, 2, 3, 4, 5]
    y = [2, 4, 1, 8, 7]

    plt.figure(figsize=(10, 8))

    plt.subplot(2, 2, 1)
    plt.plot(x, y, marker="o")
    plt.title("Line Plot")

    plt.subplot(2, 2, 2)
    plt.bar(x, y)
    plt.title("Bar Plot")

    plt.subplot(2, 2, 3)
    plt.scatter(x, y)
    plt.title("Scatter Plot")

    plt.subplot(2, 2, 4)
    plt.pie(y, labels=["A", "B", "C", "D", "E"], autopct="%1.1f%%")
    plt.title("Pie Chart")

    plt.tight_layout()
    plt.show()
