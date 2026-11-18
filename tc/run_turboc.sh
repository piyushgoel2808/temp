#!/bin/bash
# Runner script for all Turbo C compatible DAA Lab (MCA-201) programs
# Author: Piyush Goel (09311604425)

set -e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$DIR"

echo "=================================================================="
echo "  BHARATI VIDYAPEETH'S INSTITUTE OF COMPUTER APPLICATIONS (BVICAM)"
echo "      DESIGN AND ANALYSIS OF ALGORITHMS LAB (MCA-201)"
echo "             TURBO C / TURBO C++ COMPATIBLE SUITE"
echo "        Submitted By: Piyush Goel (Roll No: 09311604425)"
echo "=================================================================="

python3 "$DIR/test_turboc.py"
