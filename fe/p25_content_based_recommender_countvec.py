"""
Practical Exercise P25: Content-Based Recommendation using CountVectorizer & Cosine Similarity  [CO3, CO6/BTL5]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity
 
movies = [
    {"title": "Inception", "director": "Christopher Nolan", "actors": "Leonardo DiCaprio Joseph Gordon-Levitt", "genres": "action science fiction", "keywords": "dream heist"},
    {"title": "Interstellar", "director": "Christopher Nolan", "actors": "Matthew McConaughey Anne Hathaway", "genres": "science fiction drama", "keywords": "space time"},
    {"title": "The Matrix", "director": "Lana Wachowski", "actors": "Keanu Reeves Laurence Fishburne", "genres": "action science fiction", "keywords": "virtual reality"},
    {"title": "The Godfather", "director": "Francis Ford Coppola", "actors": "Marlon Brando Al Pacino", "genres": "crime drama", "keywords": "mafia family"},
]
documents = [" ".join(movie.values()) for movie in movies]
matrix = CountVectorizer().fit_transform(documents)
scores = cosine_similarity(matrix[0:1], matrix).ravel()
for index in scores.argsort()[::-1][1:4]:
    print(movies[index]["title"], round(scores[index], 3))
