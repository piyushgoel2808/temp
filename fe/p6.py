"""
Practical Exercise P6: 8-Puzzle Problem using A* Algorithm  [CO1/BTL6]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import heapq
 
# Initial and goal states
initial = (
    (2, 8, 3),
    (1, 6, 4),
    (7, 0, 5)   # 0 represents the blank
)
 
goal = (
    (1, 2, 3),
    (8, 0, 4),
    (7, 6, 5)
)
 
 
# Heuristic: number of misplaced tiles
def heuristic(state):
    count = 0
 
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != goal[i][j]:
                count += 1
 
    return count
 
 
# Find position of blank
def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j
 
 
# Generate possible moves
def get_neighbors(state):
    row, col = find_blank(state)
 
    # Up, Down, Left, Right
    moves = [
        (-1, 0, "UP"),
        (1, 0, "DOWN"),
        (0, -1, "LEFT"),
        (0, 1, "RIGHT")
    ]
 
    neighbors = []
 
    for dr, dc, move in moves:
        new_row = row + dr
        new_col = col + dc
 
        if 0 <= new_row < 3 and 0 <= new_col < 3:
 
            new_state = [list(r) for r in state]
 
            # Swap blank with tile
            new_state[row][col], new_state[new_row][new_col] = \
                new_state[new_row][new_col], new_state[row][col]
 
            new_state = tuple(tuple(r) for r in new_state)
 
            neighbors.append((new_state, move))
 
    return neighbors
 
 
# Print puzzle
def print_state(state):
    for row in state:
        print(" ".join("_" if x == 0 else str(x) for x in row))
    print()
 
 
# A* Algorithm
def a_star(initial, goal):
 
    # Priority queue: (f, g, state, path)
    pq = []
 
    h = heuristic(initial)
 
    heapq.heappush(pq, (h, 0, initial, []))
 
    visited = set()
 
    while pq:
 
        f, g, state, path = heapq.heappop(pq)
 
        if state in visited:
            continue
 
        visited.add(state)
 
        # Goal reached
        if state == goal:
            return path, g
 
        # Generate successors
        for next_state, move in get_neighbors(state):
 
            if next_state not in visited:
 
                new_g = g + 1
                new_h = heuristic(next_state)
                new_f = new_g + new_h
 
                heapq.heappush(
                    pq,
                    (new_f, new_g, next_state, path + [move])
                )
 
    return None, None
 
 
# Run A*
path, cost = a_star(initial, goal)
 
print("Optimal Path:")
print(" -> ".join(path))
 
print("\nTotal Cost:", cost)
 
# Display each step
state = initial
 
print("\nInitial State:")
print_state(state)
 
for move in path:
 
    for next_state, next_move in get_neighbors(state):
        if next_move == move:
            state = next_state
            break
 
    print("Move:", move)
    print_state(state)
