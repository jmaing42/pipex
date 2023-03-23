#!/bin/sh

set -e

if [ "$1" = "" ]; then
  find data -depth 1 | xargs -L1 sh "$0"
  exit
fi

cd "$1"

while IFS="," read -r input cmd
do
  sh -c "../../../tmp/pipex $input \"$(echo $cmd | sed -e "s/,/\" \"/g")\" tmp.$$.txt";
  sh -c "< $input $(echo $cmd | sed -e "s/,/ | /g")" | cmp -s - tmp.$$.txt;
  rm -f tmp.$$.txt
  if [ "$V" = "1" ] || [ "$V" = "2" ] || [ "$V" = "3" ]; then
    if [ -t 1 ]; then
      printf "\033[0;32m[PASS]\033[0m "
    else
      printf "[PASS] "
    fi
    printf "%s\n" "< $input $(echo $cmd | sed -e "s/,/ | /g") > tmp.$$.txt"
  fi
done < "index.csv"
