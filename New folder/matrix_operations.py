def input_matrix(rows, cols):
    matrix = []
    print("Enter matrix elements row-wise:")
    for i in range(rows):
        row = list(map(int, input(f"Row {i + 1}: ").split()))
        if len(row) != cols:
            raise ValueError("Invalid number of elements in row")
        matrix.append(row)
    return matrix


def print_matrix(matrix):
    for row in matrix:
        print(*row)


def add_matrices(a, b):
    rows, cols = len(a), len(a[0])
    return [[a[i][j] + b[i][j] for j in range(cols)] for i in range(rows)]


def subtract_matrices(a, b):
    rows, cols = len(a), len(a[0])
    return [[a[i][j] - b[i][j] for j in range(cols)] for i in range(rows)]


def multiply_matrices(a, b):
    rows_a, cols_a = len(a), len(a[0])
    rows_b, cols_b = len(b), len(b[0])
    if cols_a != rows_b:
        raise ValueError("Matrix multiplication not possible")

    result = [[0 for _ in range(cols_b)] for _ in range(rows_a)]
    for i in range(rows_a):
        for j in range(cols_b):
            for k in range(cols_a):
                result[i][j] += a[i][k] * b[k][j]
    return result


def transpose_matrix(a):
    return [list(row) for row in zip(*a)]


if __name__ == "__main__":
    while True:
        print("\n1. Add matrices")
        print("2. Subtract matrices")
        print("3. Multiply matrices")
        print("4. Transpose matrix")
        print("5. Exit")

        choice = input("Enter choice: ").strip()

        try:
            if choice in ["1", "2", "3"]:
                r1 = int(input("Enter rows of first matrix: "))
                c1 = int(input("Enter columns of first matrix: "))
                a = input_matrix(r1, c1)

                r2 = int(input("Enter rows of second matrix: "))
                c2 = int(input("Enter columns of second matrix: "))
                b = input_matrix(r2, c2)

                if choice == "1":
                    if r1 != r2 or c1 != c2:
                        print("Addition not possible")
                    else:
                        print("Result:")
                        print_matrix(add_matrices(a, b))
                elif choice == "2":
                    if r1 != r2 or c1 != c2:
                        print("Subtraction not possible")
                    else:
                        print("Result:")
                        print_matrix(subtract_matrices(a, b))
                else:
                    print("Result:")
                    print_matrix(multiply_matrices(a, b))

            elif choice == "4":
                r = int(input("Enter rows of matrix: "))
                c = int(input("Enter columns of matrix: "))
                a = input_matrix(r, c)
                print("Transpose:")
                print_matrix(transpose_matrix(a))

            elif choice == "5":
                print("Exiting...")
                break

            else:
                print("Invalid choice")

        except ValueError as e:
            print("Error:", e)
