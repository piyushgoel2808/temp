"""
Practical Exercise P5: Tower of Hanoi Problem  [CO1/BTL6]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

def hanoi(disks, source="A", auxiliary="B", target="C"):
    if disks == 0:
        return
    hanoi(disks - 1, source, target, auxiliary)
    print(f"Move disk {disks}: {source} -> {target}")
    hanoi(disks - 1, auxiliary, source, target)
 
 
number_of_disks = 3
print(f"Solving Towers of Hanoi for {number_of_disks} disks:")
hanoi(number_of_disks)
print("Minimum moves:", 2 ** number_of_disks - 1)
