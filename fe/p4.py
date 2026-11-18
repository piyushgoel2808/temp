"""
Practical Exercise P4: Sudoku Solver using Backtracking  [CO1/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

GRID = [
    [0, 0, 6, 5, 0, 8, 4, 0, 0],
    [5, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 8, 7, 0, 0, 0, 0, 3, 1],
    [0, 0, 3, 0, 1, 0, 0, 8, 0],
    [9, 0, 0, 8, 6, 3, 0, 0, 5],
    [0, 5, 0, 0, 9, 0, 6, 0, 0],
    [1, 3, 0, 0, 0, 0, 2, 5, 0],
    [0, 0, 0, 0, 0, 0, 0, 7, 4],
    [0, 0, 5, 2, 0, 6, 3, 0, 0],
]
 
 
def solve(grid):
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                for value in range(1, 10):
                    if valid(grid, row, col, value):
                        grid[row][col] = value
                        if solve(grid):
                            return True
                        grid[row][col] = 0
                return False
    return True
 
 
def valid(grid, row, col, value):
    if value in grid[row]:
        return False
    if any(grid[r][col] == value for r in range(9)):
        return False
    box_row, box_col = row - row % 3, col - col % 3
    return all(grid[r][c] != value for r in range(box_row, box_row + 3)
               for c in range(box_col, box_col + 3))
 
 
if solve(GRID):
    for row in GRID:
        print(*row)
else:
    print("No solution found")
