#!/bin/sh

set -e

find cases/mandatory -mindepth 1 -maxdepth 1 | xargs -I {} sh {}/test.sh
