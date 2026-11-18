"""
Practical Exercise P18: Logistic Regression - Customer Purchase Prediction  [CO4/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
 
rng = np.random.default_rng(42)
age = rng.integers(18, 60, 400)
salary = rng.integers(20000, 150000, 400)
buy = ((age > 35) & (salary > 60000)).astype(int)
x = StandardScaler().fit_transform(np.column_stack([age, salary]))
x_train, x_test, y_train, y_test = train_test_split(x, buy, test_size=0.25, random_state=42, stratify=buy)
model = LogisticRegression().fit(x_train, y_train)
predictions = model.predict(x_test)
print("Confusion matrix:\n", confusion_matrix(y_test, predictions))
print(classification_report(y_test, predictions))
