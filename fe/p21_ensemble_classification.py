"""
Practical Exercise P21: Ensemble Classification (Bagging, Random Forest, Extra Trees)  [CO5/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from sklearn.datasets import load_diabetes
from sklearn.ensemble import BaggingClassifier, ExtraTreesClassifier, RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score
import numpy as np
 
data = load_diabetes()
y = (data.target > np.median(data.target)).astype(int)
x_train, x_test, y_train, y_test = train_test_split(
    data.data, y, test_size=0.25, random_state=42, stratify=y)
models = {
    "Bagged decision trees": BaggingClassifier(estimator=DecisionTreeClassifier(), n_estimators=100, random_state=42),
    "Random forest": RandomForestClassifier(n_estimators=100, random_state=42),
    "Extra trees": ExtraTreesClassifier(n_estimators=100, random_state=42),
}
for name, model in models.items():
    model.fit(x_train, y_train)
    print(name, accuracy_score(y_test, model.predict(x_test)))
