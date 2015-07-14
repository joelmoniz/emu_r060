#!/bin/bash

# command line input is of the form <path>/<file>.asm
a=$1
xpath=${a%/*}
xbase=${a##*/}
xpref=${xbase%.*}
nasm -f elf $xpath/$xpref.asm
ld -m elf_i386 -s -o $xpath/$xpref $xpath/$xpref.o
./$xpath/$xpref