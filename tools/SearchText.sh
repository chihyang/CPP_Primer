#!/bin/bash
echo 'Usage: SearchText <path> <ext> <keywords>'
echo
find $1 -type f -name "*."$2 |xargs grep -E $3
