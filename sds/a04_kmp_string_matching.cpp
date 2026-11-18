/*
 * A4. WAP to implement Knuth Morris Pratt algorithm.
 * Subject: Design and Analysis of Algorithms Lab (MCA-201)
 * Name: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B
 */

#include <iostream>
#include <string>
using namespace std;

// Function to create the partial match (prefix) table
void computeLPSArray(string pattern, int M, int lps[])
{
    int len = 0; // Length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0

    // The loop calculates lps[i] for i = 1 to M-1
    for (int i = 1; i < M; i++)
    {
        while (len > 0 && pattern[i] != pattern[len])
        {
            len = lps[len - 1]; // Fall back in the pattern
        }
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len; // We found a new match
        }
        else
        {
            lps[i] = 0; // No match found
        }
    }
}

// KMP algorithm to search for a pattern in a given text
void KMP(string text, string pattern)
{
    int N = text.length();
    int M = pattern.length();

    int lps[M]; // Create lps array to hold the longest prefix suffix values

    // Preprocess the pattern to create the lps array
    computeLPSArray(pattern, M, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    bool found = false;

    while (i < N)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        // Pattern found
        if (j == M)
        {
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1]; // Reset j using the lps array
            found = true;
        }
        else if (i < N && pattern[j] != text[i])
        {
            // Mismatch after j matches
            if (j != 0)
            {
                j = lps[j - 1]; // Use lps array to avoid unnecessary comparisons
            }
            else
            {
                i++;
            }
        }
    }

    if (!found)
    {
        cout << "Pattern not found in the text." << endl;
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMP(text, pattern);

    return 0;
}
