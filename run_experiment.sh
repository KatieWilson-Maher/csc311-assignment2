#!/bin/bash

for i in $(seq $1 $3 $2)
do
	./a.out $i >> output.txt
done

for i in $(seq $1 $3 $2)
do
	python3 sort.py $i >> output.txt
done
