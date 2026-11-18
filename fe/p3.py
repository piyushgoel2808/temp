"""
Practical Exercise P3: Depth First Search (DFS) Traversal  [CO1/BTL3]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

graph = {
    "a": ["b", "e", "f"], "b": ["a", "c", "e"],
    "c": ["b", "d"], "d": ["c", "e"],
    "e": ["a", "b", "d"], "f": ["a"]
}
 
 
def dfs(start):
    visited = set()
    order = []
 
    def visit(node):
        visited.add(node)
        order.append(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                visit(neighbor)
 
    visit(start)
    return order
 
 
print("DFS traversal:", " -> ".join(dfs("a")))
