"""
Practical Exercise P16: Find-S Algorithm for Finding Most Specific Hypothesis  [CO3/BTL4]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import csv
 
data = [
    ["Sunny", "Warm", "Normal", "Strong", "Warm", "Same", "Yes"],
    ["Sunny", "Warm", "High", "Strong", "Warm", "Same", "Yes"],
    ["Rainy", "Cold", "High", "Strong", "Warm", "Change", "No"],
    ["Sunny", "Warm", "High", "Strong", "Cool", "Change", "Yes"],
]
 
 
def find_s(rows):
    hypothesis = ["0"] * (len(rows[0]) - 1)
    for row in rows:
        if row[-1].lower() != "yes":
            continue
        for index, value in enumerate(row[:-1]):
            if hypothesis[index] == "0":
                hypothesis[index] = value
            elif hypothesis[index] != value:
                hypothesis[index] = "?"
    return hypothesis
 
 
with open("clients_training.csv", "w", newline="") as file:
    csv.writer(file).writerows(data)
print("Most specific hypothesis:", find_s(data))
