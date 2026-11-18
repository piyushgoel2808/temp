"""
Practical Exercise P9: Data Cleaning & Random Forest Classifier  [CO2/BTL3]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
 
iris = load_iris(as_frame=True)
frame = iris.frame.drop_duplicates().reset_index(drop=True)
x = frame.drop(columns="target")
y = frame["target"]
x_train, x_test, y_train, y_test = train_test_split(
    x, y, test_size=0.25, random_state=42, stratify=y)
model = RandomForestClassifier(n_estimators=200, random_state=42)
model.fit(x_train, y_train)
print("Rows after removing duplicates:", len(frame))
print("Accuracy after cleaning:", accuracy_score(y_test, model.predict(x_test)))
