#!/bin/sh

set -e

find src -name "*.c" -o -name "*.h" | while IFS= read -r line
do
  cp "$line" "tmp/$(basename "$line")"
done
