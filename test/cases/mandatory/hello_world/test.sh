#!/bin/sh

set -e

rm -f "$(dirname "$0")/result.txt"
../tmp/pipex "$(dirname "$0")/in.txt" "cat" "cat" "$(dirname "$0")/result.txt"
cmp -s "$(dirname "$0")/result.txt" "$(dirname "$0")/out.txt"
rm -f "$(dirname "$0")/result.txt"
