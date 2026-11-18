"""
Practical Exercise P20: K-Means Clustering on Customer Data (Elbow Method & Centers)  [CO4/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import numpy as np
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
 
rng = np.random.default_rng(42)
customers = np.vstack([rng.normal([25, 30], [4, 5], (100, 2)),
                       rng.normal([45, 70], [5, 6], (100, 2)),
                       rng.normal([65, 35], [5, 5], (100, 2))])
x = StandardScaler().fit_transform(customers)
inertias = []
for clusters in range(1, 9):
    inertias.append(KMeans(n_clusters=clusters, n_init=10, random_state=42).fit(x).inertia_)
model = KMeans(n_clusters=3, n_init=10, random_state=42).fit(x)
print("Inertia for k=1..8:", inertias)
print("Cluster centers (age, spending score):\n", model.cluster_centers_)
