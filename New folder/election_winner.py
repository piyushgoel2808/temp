def election_winner(votes):
    counts = {}
    for name in votes:
        counts[name] = counts.get(name, 0) + 1

    max_votes = max(counts.values())
    top_candidates = [name for name, c in counts.items() if c == max_votes]
    top_candidates.sort()

    return top_candidates, top_candidates[0], max_votes


if __name__ == "__main__":
    n = int(input("Enter number of votes: "))
    votes = []

    print("Enter candidate names:")
    for _ in range(n):
        votes.append(input().strip())

    top_list, winner, vote_count = election_winner(votes)

    print("Candidates with maximum votes (lexicographical order):")
    print(*top_list)
    print("Winner (tie -> lexicographically smaller):", winner)
    print("Votes received:", vote_count)
