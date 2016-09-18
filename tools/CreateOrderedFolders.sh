#!/bin/bash

function usage() {
    echo "Create ordered directories with a given prefix"
    echo "Usage: $0 [-p PREFIX] [-L LOWER_limit] -u UPPER_LIMIT [-d DEST_DIR]"
    echo "  -p         -- optional PREFIX that contains valid file names, default is null"
    echo "  -l         -- optional LOWER_LIMIT, integer, default is 1, minimum is 1"
    echo "  -u         -- UPPER_LIMIT, integer, must be larger than lower limit"
    echo "  -d         -- specify destination directory with DEST_DIR"
    echo "  -h         -- print this help info"
    echo "Example: $0 -p chap -l 1 -u 20 -d ../"
    echo "  Create directories chap01, chap02, ..., chap20 in parent directory"
}

function is_numeral() {
    var=$1

    if [ "$var" -eq "$var" ] 2>/dev/null; then
        return 0                # is a number
    else
        return 1                # not a number
    fi
}

function get_decimal_bits() {
    var=$1
    bits=1
    var=$(($var/10))
    while test $var -ne 0
    do
        bits=$(($bits+1))
        var=$(($var/10))
    done
    return $bits;
}

prefix=""
upper_limit=
lower_limit=1
dest="."
while getopts "p:l:u:d:h" OPTION
do
    case $OPTION in
        p):
          prefix=${OPTARG}
          ;;
        l):
          is_numeral ${OPTARG}
          if [ $? -eq 0 ]; then
              echo "Not a valid lower limit!"
              exit 1
          else
              lower_limit=${OPTARG}
          fi
          ;;
        u):
          is_numeral ${OPTARG}
          if [ $? -ne 0 ]; then
              echo "Not a valid upper limit!"
              exit 1
          else
              upper_limit=${OPTARG}
          fi
          ;;
        d):
          dest=${OPTARG}
          ;;
        h):
          usage
          exit 0
          ;;
        ?)
        echo "Unknown arguments!"
        usage
        exit 1
        ;;
        esac
done

if [ $# -eq 0 ]; then
    echo "Not enough arguments!"
    usage
    exit 1
fi

if [ -z "$upper_limit" ]; then
    echo "You must specify UPPER_LIMIT with -u option"
    exit 1
fi

if [ $upper_limit -le $lower_limit ]; then
    echo "upper_limit $upper_limit is less than or equal to lower_limit $lower_limit, exit!"
    exit 1
else
    for i in $(seq -w $lower_limit $upper_limit)
    do
        o="$dest/$prefix$i" # No space between expressions and '='
        if [ -d $o ];then
            echo "$o already exists" | sed 's/\/\//\//'
        else
            mkdir -p $o
            echo "$o is created" | sed 's/\/\//\//'
        fi
    done
    exit 0
fi
