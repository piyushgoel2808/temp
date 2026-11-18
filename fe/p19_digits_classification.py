"""
Practical Exercise P19: Handwritten Digits Classification using Logistic Regression  [CO4/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from sklearn.datasets import load_digits
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
 
digits = load_digits()
x = StandardScaler().fit_transform(digits.data)
x_train, x_test, y_train, y_test = train_test_split(
    x, digits.target, test_size=0.2, random_state=42, stratify=digits.target)
model = LogisticRegression(max_iter=2000).fit(x_train, y_train)
predictions = model.predict(x_test)
print("Accuracy:", accuracy_score(y_test, predictions))
print(classification_report(y_test, predictions))
