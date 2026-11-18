"""
Practical Exercise P14: Multiple Linear Regression - CO2 Emission Prediction  [CO3/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
 
url = "https://raw.githubusercontent.com/justmarkham/DAT8/master/data/co2.csv"
try:
    data = pd.read_csv(url)
    data.columns = [column.strip().lower().replace(" ", "_") for column in data]
except Exception:
    data = pd.DataFrame({"engine_size": [1.2, 1.6, 2.0, 2.5, 3.0],
                         "weight": [1000, 1200, 1400, 1600, 1900],
                         "co2": [110, 140, 180, 220, 270]})
features = [column for column in data if "engine" in column or "size" in column or "weight" in column]
target = next(column for column in data if "co2" in column)
x_train, x_test, y_train, y_test = train_test_split(
    data[features], data[target], test_size=0.2, random_state=42)
model = LinearRegression().fit(x_train, y_train)
print("Features:", features)
print("R2 score:", r2_score(y_test, model.predict(x_test)))
