#!/bin/bash 
find $1 -type f -name "*."$2 |xargs grep -E $3
