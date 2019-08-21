#!/bin/bash
make clean
make
for f in ./testcases/*.c
do
	echo
	echo "TEST START -------------------------------------------------------------" $f
	echo
	echo
	echo

    ./yoursclp -icode  $f
    # mv $f.ast $f.our
   	mv $f.ic $f.ouric
    # mv $f.eval $f.oureval
	# mv $f.spim $f.ourspim
	# mv $f.sym $f.oursym
	# mv $f.toks $f.ourtoks

    ./sclp -icode  $f
    # mv $f.ast $f.their
   	mv $f.ic $f.theiric
    # mv $f.eval $f.theireval
	# mv $f.spim $f.theirspim
	# mv $f.sym $f.theirsym
	# mv $f.toks $f.theirtoks
    echo $f

	# diff  $f.ourspim $f.theirspim
	# diff -q $f.oursym $f.theirsym
	diff  $f.ouric $f.theiric
	# diff -q $f.oureval $f.theireval
	# diff -q $f.ourtoks $f.theirtoks
    # diff -q $f.our $f.their

	echo
	echo
	echo "TEST END ----------------------------------------------------------------" $f
	echo
	echo
done
