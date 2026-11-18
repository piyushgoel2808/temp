"""
Practical Exercise P23: Popularity-Based Movie Recommendation System  [CO6/BTL6]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import pandas as pd
 
movies = pd.DataFrame({
    "title": ["The Shawshank Redemption", "The Godfather", "The Dark Knight", "12 Angry Men", "Pulp Fiction"],
    "rating": [9.3, 9.2, 9.0, 9.0, 8.9], "votes": [2800000, 1900000, 2800000, 850000, 2200000]})
movies["score"] = movies.rating * movies.votes / movies.votes.max()
print(movies.sort_values("score", ascending=False)[["title", "score"]].to_string(index=False))
