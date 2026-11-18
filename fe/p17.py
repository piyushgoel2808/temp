"""
Practical Exercise P17: Linear Regression - Head Size vs Brain Weight  [CO3/BTL4]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
 
head_size = np.array([4512, 4432, 4561, 4458, 4487, 4380, 4455, 4375, 4396, 4450]).reshape(-1, 1)
brain_weight = np.array([1530, 1510, 1535, 1520, 1525, 1500, 1515, 1498, 1505, 1518])
model = LinearRegression().fit(head_size, brain_weight)
prediction = model.predict(head_size)
print("RMSE:", np.sqrt(mean_squared_error(brain_weight, prediction)))
print("R-squared:", r2_score(brain_weight, prediction))
print("Predicted brain weight for head size 4500:", model.predict([[4500]])[0])
