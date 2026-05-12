import math


class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius * self.radius

    def perimeter(self):
        return 2 * math.pi * self.radius


if __name__ == "__main__":
    r = float(input("Enter radius: "))
    if r < 0:
        print("Radius cannot be negative.")
    else:
        c = Circle(r)
        print("Area:", c.area())
        print("Perimeter:", c.perimeter())
