#!/bin/bash
for((i=0; i<1; i++))
do
	echo $i > seed
	./ingen < seed > test.in
	./wzor < test.in > w.out
	./brut < test.in > b.out
	if diff -b w.out b.out
	then
		echo "OK $i"
	else
		echo "NIE OK $i"
		break
	fi
done