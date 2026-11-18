"""
Practical Exercise P12: Linear Regression with Bootstrap Bias & Variance (California Housing)  [CO2/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import ssl
ssl._create_default_https_context = ssl._create_unverified_context

from sklearn.datasets import fetch_california_housing
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error
import numpy as np
 
data = fetch_california_housing()
x_train, x_test, y_train, y_test = train_test_split(
    data.data, data.target, test_size=0.2, random_state=42)
model = LinearRegression().fit(x_train, y_train)
predictions = model.predict(x_test)
errors = []
rng = np.random.default_rng(42)
for _ in range(200):
    indices = rng.integers(0, len(x_train), len(x_train))
    sample_model = LinearRegression().fit(x_train[indices], y_train[indices])
    errors.append((sample_model.predict(x_test) - y_test) ** 2)
errors = np.asarray(errors)
print("Test MSE:", mean_squared_error(y_test, predictions))
print("Bootstrap bias:", np.mean((errors.mean(axis=0)) ** 0.5))
print("Bootstrap variance:", np.mean(errors.var(axis=0)))
