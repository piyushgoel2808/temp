"""
Practical Exercise P11: Confusion Matrix & Classification Report on Breast Cancer Dataset  [CO2/BTL4]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import classification_report, confusion_matrix
 
data = load_breast_cancer()
x_train, x_test, y_train, y_test = train_test_split(
    data.data, data.target, test_size=0.2, random_state=42, stratify=data.target)
model = make_pipeline(StandardScaler(), LogisticRegression(max_iter=2000))
model.fit(x_train, y_train)
predictions = model.predict(x_test)
print("Confusion matrix:\n", confusion_matrix(y_test, predictions))
print(classification_report(y_test, predictions, target_names=data.target_names))
