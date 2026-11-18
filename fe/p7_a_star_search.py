"""
Practical Exercise P7: A* Search Algorithm on Weighted Graph  [CO1/BTL6]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import heapq
 
# Graph: node -> [(neighbor, edge_cost), ...]
graph = {
    'A': [('B', 6), ('F', 3)],
    'B': [('A', 6), ('D', 2), ('C', 3)],
    'C': [('B', 3), ('D', 1), ('E', 5)],
    'D': [('B', 2), ('C', 1), ('E', 8)],
    'E': [('C', 5), ('D', 8), ('I', 5), ('J', 5)],
    'F': [('A', 3), ('G', 1), ('H', 7)],
    'G': [('F', 1), ('I', 3)],
    'H': [('F', 7), ('I', 2)],
    'I': [('G', 3), ('H', 2), ('E', 5), ('J', 3)],
    'J': [('E', 5), ('I', 3)]
}
 
# Heuristic values from the graph
h = {
    'A': 10,
    'B': 8,
    'C': 5,
    'D': 7,
    'E': 3,
    'F': 6,
    'G': 5,
    'H': 3,
    'I': 1,
    'J': 0
}
 
 
def a_star(start, goal):
 
    # Priority queue contains:
    # (f, g, node, path)
    pq = []
 
    g_cost = 0
    f_cost = g_cost + h[start]
 
    heapq.heappush(pq, (f_cost, g_cost, start, [start]))
 
    visited = set()
 
    while pq:
 
        f, g, current, path = heapq.heappop(pq)
 
        if current in visited:
            continue
 
        visited.add(current)
 
        print(
            "Expanding:", current,
            "g =", g,
            "h =", h[current],
            "f =", f
        )
 
        # Goal reached
        if current == goal:
            return path, g
 
        # Generate successors
        for neighbor, cost in graph[current]:
 
            if neighbor not in visited:
 
                new_g = g + cost
                new_f = new_g + h[neighbor]
 
                heapq.heappush(
                    pq,
                    (new_f, new_g, neighbor, path + [neighbor])
                )
 
    return None, None
 
 
# Run A*
start = 'A'
goal = 'I'
 
path, cost = a_star(start, goal)
 
print("\nOptimal Path:")
print(" -> ".join(path))
 
print("Total Cost:", cost)
