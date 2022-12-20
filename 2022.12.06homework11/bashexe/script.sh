#!/bin/bash

cd ~/Desktop/hw2/2022.12.06homework11/bashexe
#pwd
#ls -l
./1.exe &
./2.exe &
./3.exe &
./4.exe &
wait
if cmp outnob1.txt out1.txt
then echo "файлы 1 равны"
fi

if cmp outnob2.txt out2.txt
then echo "файлы 2 равны"
fi

if cmp outnob3.txt out3.txt
then echo "файлы 3 равны"
fi

if cmp outnob4.txt out4.txt
then echo "файлы 4 равны"
fi

echo Finished