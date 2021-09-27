#!/bin/bash
file=$1
clear && g++ "$HOME/home/all/dsa/leetcode/$file.cpp" -o $file && "$HOME/home/all/dsa/leetcode/$file" && rm "$HOME/home/all/dsa/leetcode/$file"
