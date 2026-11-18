"""
Practical Exercise P2: Snake and Ladder Minimum Dice Throws  [CO1/BTL4]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from collections import deque
 
# Square number: destination reached after applying a snake/ladder jump.
snakes_and_ladders = {3: 22, 5: 8, 11: 26, 20: 29, 27: 1, 21: 9, 17: 4}
 
 
def minimum_throws(source, destination):
    queue = deque([(source, 0)])
    visited = {source}
    while queue:
        square, throws = queue.popleft()
        if square == destination:
            return throws
        for roll in range(1, 7):
            next_square = square + roll
            if next_square > destination:
                continue
            next_square = snakes_and_ladders.get(next_square, next_square)
            if next_square not in visited:
                visited.add(next_square)
                queue.append((next_square, throws + 1))
    return None
 
 
print("Minimum dice throws:", minimum_throws(1, 30))
