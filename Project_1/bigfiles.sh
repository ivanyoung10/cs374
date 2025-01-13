#! /bin/zsh

ls -al /usr/bin | awk '{print $5, $9}' | sort -rn | head -n 7