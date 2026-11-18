"""
Practical Exercise P24: Content-Based Recommendation using TF-IDF & Cosine Similarity  [CO6/BTL6]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
 
movies = ["The space mission saves Earth", "A space crew explores a planet", "A detective solves a city crime", "A family protects their home"]
matrix = TfidfVectorizer(stop_words="english").fit_transform(movies)
similarity = cosine_similarity(matrix)
for index, score in enumerate(similarity[0]):
    if index != 0 and score >= 0.1:
        print(f"Similar to movie 1: movie {index + 1} (score={score:.3f})")
