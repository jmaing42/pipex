#!/bin/sh

set -e

rm -f "$(dirname "$0")/result.txt"
../tmp/pipex "$(dirname "$0")/in.txt" "cat" "cat" "$(dirname "$0")/result.txt"
cmp -s "$(dirname "$0")/result.txt" "$(dirname "$0")/out-1.txt"
../tmp/pipex "$(dirname "$0")/in.txt" "cat" "cat" "$(dirname "$0")/result.txt"
cmp -s "$(dirname "$0")/result.txt" "$(dirname "$0")/out-1.txt"
../tmp/pipex "$(dirname "$0")/in.txt" "grep Bye" "wc -l" "$(dirname "$0")/result.txt"
cmp -s "$(dirname "$0")/result.txt" "$(dirname "$0")/out-2.txt"
rm -f "$(dirname "$0")/result.txt"
