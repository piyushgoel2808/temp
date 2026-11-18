#!/usr/bin/env python3
"""
Automated Test Suite for Turbo C / Turbo C++ Compatible DAA Lab Programs
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
Student: Piyush Goel (Roll No: 09311604425)
"""

import os
import subprocess
import sys
import tempfile

TEST_CASES = [
    {
        "id": "TC_P01",
        "file": "p01_bubble_sort.c",
        "input": "6\n10 7 8 9 1 5\n",
        "expected": ["Sorted array:", "1 5 7 8 9 10"],
        "description": "Bubble Sort (Turbo C)"
    },
    {
        "id": "TC_P02",
        "file": "p02_quick_sort.c",
        "input": "6\n12 11 13 5 6 7\n",
        "expected": ["Sorted array:", "5 6 7 11 12 13"],
        "description": "Quick Sort (Turbo C)"
    },
    {
        "id": "TC_P03",
        "file": "p03_merge_sort.c",
        "input": "5\n40 10 30 50 20\n",
        "expected": ["Sorted array:", "10 20 30 40 50"],
        "description": "Merge Sort (Turbo C)"
    },
    {
        "id": "TC_P04",
        "file": "p04_binary_search.c",
        "input": "5\n10 20 30 40 50\n40\n",
        "expected": ["Element found at position 4"],
        "description": "Binary Search (Turbo C)"
    },
    {
        "id": "TC_P05",
        "file": "p05_radix_sort.c",
        "input": "8\n170 45 75 90 802 24 2 66\n",
        "expected": ["Sorted array:", "2 24 45 66 75 90 170 802"],
        "description": "Radix Sort (Turbo C)"
    },
    {
        "id": "TC_P06",
        "file": "p06_bucket_sort.c",
        "input": "6\n0.897 0.565 0.656 0.1234 0.665 0.3434\n",
        "expected": ["Sorted array:", "0.1234", "0.897"],
        "description": "Bucket Sort (Turbo C)"
    },
    {
        "id": "TC_P07",
        "file": "p07_counting_sort.c",
        "input": "6\n1 4 1 2 5 2\n",
        "expected": ["Sorted array:", "1 1 2 2 4 5"],
        "description": "Counting Sort (Turbo C)"
    },
    {
        "id": "TC_P08",
        "file": "p08_strassen_matrix_multiplication.c",
        "input": "1 2\n3 4\n5 6\n7 8\n",
        "expected": ["Resultant Matrix:", "19 22", "43 50"],
        "description": "Strassen Matrix Multiplication (Turbo C)"
    },
    {
        "id": "TC_P09",
        "file": "p09_matrix_chain_multiplication.c",
        "input": "3\n1 2 3 4\n",
        "expected": ["Minimum number of multiplications = 18"],
        "description": "Matrix Chain Multiplication (Turbo C)"
    },
    {
        "id": "TC_P10",
        "file": "p10_naive_string_matching.c",
        "input": "AABAACAADAABAABA\nAABA\n",
        "expected": ["Pattern found at index 0", "Pattern found at index 9", "Pattern found at index 12"],
        "description": "Naïve String Matching (Turbo C)"
    },
    {
        "id": "TC_P11",
        "file": "p11_disjoint_set.cpp",
        "input": "",
        "expected": ["1 and 3 are in the same set? 1"],
        "description": "Disjoint Set (Turbo C++)"
    },
    {
        "id": "TC_P12",
        "file": "p12_fractional_knapsack.cpp",
        "input": "",
        "expected": ["Maximum value in Knapsack = 240"],
        "description": "Fractional Knapsack (Turbo C++)"
    },
    {
        "id": "TC_P13",
        "file": "p13_huffman_coding.cpp",
        "input": "",
        "expected": ["f: 0", "c: 100", "d: 101", "a: 1100", "b: 1101", "e: 111"],
        "description": "Huffman Coding (Turbo C++)"
    },
    {
        "id": "TC_P14",
        "file": "p14_dijkstra.cpp",
        "input": "",
        "expected": ["Vertex", "Distance from Source", "0 \t\t 0", "1 \t\t 4", "2 \t\t 12", "7 \t\t 8", "8 \t\t 14"],
        "description": "Dijkstra Algorithm (Turbo C++)"
    },
    {
        "id": "TC_P15",
        "file": "p15_prim_kruskal.cpp",
        "input": "",
        "expected": ["PRIM'S ALGORITHM", "KRUSKAL'S ALGORITHM", "0 - 1", "2 -- 3 == 4"],
        "description": "Prim & Kruskal MST (Turbo C++)"
    },
    {
        "id": "TC_P15a",
        "file": "p15a_prim.cpp",
        "input": "",
        "expected": ["Prim's Minimum Spanning Tree", "0 - 1"],
        "description": "Prim MST (Turbo C++)"
    },
    {
        "id": "TC_P15b",
        "file": "p15b_kruskal.cpp",
        "input": "",
        "expected": ["Kruskal's Minimum Spanning Tree", "2 -- 3 == 4"],
        "description": "Kruskal MST (Turbo C++)"
    },
    {
        "id": "TC_P16",
        "file": "p16_longest_common_subsequence.cpp",
        "input": "",
        "expected": ["Length of LCS is 4", "LCS of AGGTAB and GXTXAYB is GTAB"],
        "description": "Longest Common Subsequence (Turbo C++)"
    },
    {
        "id": "TC_P17",
        "file": "p17_matrix_chain_multiplication_dp.cpp",
        "input": "",
        "expected": ["Minimum number of multiplications is: 18"],
        "description": "Matrix Chain Multiplication DP (Turbo C++)"
    },
    {
        "id": "TC_P18",
        "file": "p18_floyd_warshall.cpp",
        "input": "",
        "expected": ["Shortest distances between every pair of vertices:", "0 5 8 9", "INF 0 3 4"],
        "description": "Floyd-Warshall (Turbo C++)"
    },
    {
        "id": "TC_A01",
        "file": "a01_n_queens.cpp",
        "input": "",
        "expected": ["1 0 0 0 0 0 0 0", "0 0 0 0 0 0 1 0"],
        "description": "N-Queens (Turbo C++)"
    },
    {
        "id": "TC_A02",
        "file": "a02_sum_of_subsets.cpp",
        "input": "",
        "expected": ["Subsets that sum to 9:", "{ 3 4 2 }", "{ 4 5 }"],
        "description": "Sum of Subsets (Turbo C++)"
    },
    {
        "id": "TC_A03",
        "file": "a03_job_sequencing.cpp",
        "input": "",
        "expected": ["Scheduled Jobs:", "Job ID: 2 (Profit: 15)", "Job ID: 1 (Profit: 20)", "Job ID: 4 (Profit: 5)"],
        "description": "Job Sequencing (Turbo C++)"
    },
    {
        "id": "TC_A04",
        "file": "a04_kmp_string_matching.cpp",
        "input": "",
        "expected": ["Pattern found at index 10"],
        "description": "KMP Algorithm (Turbo C++)"
    }
]

def run_tests():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    passed = 0
    failed = 0

    print("=" * 70)
    print("  TURBO C / TURBO C++ COMPATIBILITY TEST SUITE")
    print("  Author: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem, Sec-B")
    print("=" * 70)

    with tempfile.TemporaryDirectory() as tmpdir:
        for tc in TEST_CASES:
            file_path = os.path.join(script_dir, tc["file"])
            bin_path = os.path.join(tmpdir, tc["id"])

            if not os.path.exists(file_path):
                print(f"[{tc['id']}] ❌ File not found: {tc['file']}")
                failed += 1
                continue

            compiler = "clang++" if tc["file"].endswith(".cpp") else "clang"
            compile_cmd = [compiler, "-I" + script_dir, "-O2", file_path, "-o", bin_path]

            compile_res = subprocess.run(compile_cmd, capture_output=True, text=True)
            if compile_res.returncode != 0:
                print(f"[{tc['id']}] ❌ Compilation failed for {tc['file']}:")
                print(compile_res.stderr)
                failed += 1
                continue

            run_res = subprocess.run([bin_path], input=tc["input"], capture_output=True, text=True)
            if run_res.returncode != 0:
                print(f"[{tc['id']}] ❌ Execution failed for {tc['file']} (exit code {run_res.returncode}):")
                print(run_res.stderr)
                failed += 1
                continue

            stdout = run_res.stdout
            matched = True
            missing_tokens = []
            for token in tc["expected"]:
                if token not in stdout:
                    matched = False
                    missing_tokens.append(token)

            if matched:
                print(f"[{tc['id']}] ✅ PASS: {tc['description']}")
                passed += 1
            else:
                print(f"[{tc['id']}] ❌ FAIL: {tc['description']}")
                print(f"       Expected tokens not found: {missing_tokens}")
                print(f"       Actual output:\n{stdout}")
                failed += 1

    print("=" * 70)
    print(f"  TEST RESULTS: {passed} PASSED / {passed + failed} TOTAL")
    print("=" * 70)

    if failed == 0:
        print("🎉 ALL TURBO C COMPATIBLE PROGRAMS WORK PERFECTLY!")
        return 0
    else:
        print(f"⚠️ {failed} tests failed.")
        return 1

if __name__ == "__main__":
    sys.exit(run_tests())
