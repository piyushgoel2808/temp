"""
Practical Exercise P15: Linear Regression Scatter & Fitted Line Plot (CO2 vs Engine Size)  [CO3/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import matplotlib.pyplot as plt
import pandas as pd
from sklearn.linear_model import LinearRegression
 
data = pd.DataFrame({"engine_size": [1.2, 1.6, 2.0, 2.5, 3.0, 3.5],
                     "co2": [110, 140, 180, 220, 270, 310]})
model = LinearRegression().fit(data[["engine_size"]], data["co2"])
plt.scatter(data.engine_size, data.co2, label="Observed")
plt.plot(data.engine_size, model.predict(data[["engine_size"]]), color="red", label="Regression")
plt.xlabel("Engine size")
plt.ylabel("CO2 emission")
plt.legend()
plt.tight_layout()
plt.savefig("p15_regression_plot.png")
print("Saved regression plot to p15_regression_plot.png")
import os
if os.environ.get("HEADLESS") != "1":
    try:
        plt.show()
    except Exception:
        pass
