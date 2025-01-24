#!/bin/bash

if [ "$#" -ne 6 ]; then
    printf "Usage: $0 <MIN> <MAX> <SIZE> <PROGRAM> <DISPLAY_LIST> <CHECKER>"
    exit 1
fi

MIN=$1
MAX=$2
SIZE=$3
PROGRAM=$4
DISPLAY_LIST=$5
CHECKER=$6

if [ ! -f push_swap ]; then
    printf "Error: the push_swap binary file does not exist.\n\
    \"make\" before to compile the project and create the file.\n"
    exit 1
fi

AVAILABLE=$((MAX - MIN + 1))

if [ "$SIZE" -gt "$AVAILABLE" ]; then
    printf "Error: impossible to generate $SIZE unique int \n\
        in the range [$MIN, $MAX]. Check Pigeonhole principle."
    exit 1
fi

ARG=$(shuf -i "$MIN-$MAX" -n "$SIZE" | tr '\n' ' ')

if [ $DISPLAY_LIST -ne 0 ]; then
    printf "Generated list: $ARG\n"
fi

if [ $CHECKER -eq 0 ]; then
    $PROGRAM $ARG
elif [ $CHECKER -eq 1 ]; then
    if [ -f checker_Mac ]; then
        $PROGRAM $ARG | ./checker_Mac $ARG
    else
        printf "Error: checker_Mac file does not exist.\n\
        Please download it, or use the bonus one:\n\
        \"make bonus\"\n"
        exit 1
    fi
elif [ $CHECKER -eq 2 ]; then
    if [ -f checker_linux ]; then
        $PROGRAM $ARG | ./checker_linux $ARG
    else
        printf "Error: checker_linux file does not exist.\n\
        Please download it, or use the bonus one:\n\
        \"make bonus\"\n"
        exit 1
    fi
elif [ $CHECKER -eq 3 ]; then
    if [ -f checker ]; then
        $PROGRAM $ARG | ./checker $ARG
    else
        printf "Error: checker file does not exist.\n\
        \"make bonus\" to get it.\n"
        exit 1
    fi
else
    printf "CHECKER Makefile's variable usage:\n\
    - 0: No checker used\n\
    - 1: checker_Mac used\n\
    - 2: checker_linux used\n\
    - 3: checker (my own, from the bonus part) used\n\
    Other value are not accepted.\n"
    exit 1
fi

if [ $DISPLAY_LIST -ne 0 ]; then
    printf "Careful: do not count the lines with any | wc -l\n\
    The numbers list has been printed before the moves.\n"
fi
