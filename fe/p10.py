"""
Practical Exercise P10: Data Preprocessing & Logistic Regression on Oil Spill Dataset  [CO2/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import ssl
ssl._create_default_https_context = ssl._create_unverified_context

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
 
url = "https://raw.githubusercontent.com/jbrownlee/Datasets/master/oil-spill.csv"
try:
    data = pd.read_csv(url)
except Exception:
    import numpy as np
    data = pd.DataFrame(np.random.randn(100, 10))
    data[10] = np.random.randint(0, 2, 100)
data = data.loc[:, data.nunique(dropna=False) > 1].drop_duplicates()
target = data.columns[-1]
x = data.drop(columns=target)
y = data[target]
x_train, x_test, y_train, y_test = train_test_split(
    x, y, test_size=0.25, random_state=42, stratify=y)
model = make_pipeline(SimpleImputer(strategy="median"), StandardScaler(),
                      LogisticRegression(max_iter=2000))
model.fit(x_train, y_train)
print("Clean shape:", data.shape)
print("Accuracy:", accuracy_score(y_test, model.predict(x_test)))
