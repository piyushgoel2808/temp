"""
Practical Exercise P1: Breadth First Search (BFS) Traversal  [CO1/BTL3]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from collections import deque
 
graph = {
    "a": ["b", "e", "f"], "b": ["a", "c", "e"],
    "c": ["b", "d"], "d": ["c", "e"],
    "e": ["a", "b", "d"], "f": ["a"]
}
 
 
def bfs(start):
    visited = {start}
    queue = deque([start])
    order = []
    while queue:
        node = queue.popleft()
        order.append(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    return order
 
 
print("BFS traversal:", " -> ".join(bfs("a")))
