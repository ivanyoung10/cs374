#! /bin/zsh

ls -al $1 | awk '{print $5, $9}' | sort -rn | head -n 7