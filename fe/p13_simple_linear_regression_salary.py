"""
Practical Exercise P13: Simple Linear Regression - Salary vs Experience  [CO3/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
 
experience = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]).reshape(-1, 1)
salary = np.array([30, 33, 38, 42, 48, 55, 62, 68, 75, 82])
x_train, x_test, y_train, y_test = train_test_split(
    experience, salary, test_size=0.2, random_state=42)
model = LinearRegression().fit(x_train, y_train)
print("Predicted salaries:", model.predict(x_test))
print("MSE:", mean_squared_error(y_test, model.predict(x_test)))
print("Coefficient (salary per year):", model.coef_[0])
print("Intercept:", model.intercept_)
