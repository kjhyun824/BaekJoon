#!/bin/bash

g++ --std=c++11 bracket2.cpp

rm -rf output.txt

for i in {1..6}
do
    ./a.out < sample_input${i}.txt >> output.txt
done

python3 check.py
