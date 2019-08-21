#!/bin/bash
make clean
make
for f in ./Level2/*.c
do
    ./yoursclp -ast $f
    mv $f.ast $f.our
    ./sclp -ast $f
    mv $f.ast $f.their
    echo $f
    diff -Z $f.our $f.their
done
