#!/bin/bash

PWD=$(dirname $(readlink -f $0))

gcc -g -Iinclude ${PWD}/main.c -o ${PWD}/obmain && ${PWD}/obmain
[ -z "$1" ] && rm -f ${PWD}/obmain
