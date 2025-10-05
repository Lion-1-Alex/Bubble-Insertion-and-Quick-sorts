#!/bin/bash

cd InsertionSort
gcc -o Insertion Insertion_sort.c

./Insertion

cd ..
cd pythonProjectGraphics
python3 Animation_Insertion.py
