#!/bin/bash

for f in ./Level2/*.c
do
    ./yoursclp -tokens $f
    mv $f.toks $f.our
    ./sclp -tokens $f
    mv $f.toks $f.their
    echo $f
    diff $f.our $f.their
done
