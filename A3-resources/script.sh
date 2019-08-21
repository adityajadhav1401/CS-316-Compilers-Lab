#!/bin/bash
make clean
make
for f in ./Level2/*.c
do
    ./yoursclp -ast -tokens -symtab -icode  $f
    mv $f.ast $f.our
    mv $f.ic $f.ouric
 #   mv $f.eval $f.oureval
	mv $f.spim $f.ourspim
	mv $f.sym $f.oursym
	mv $f.toks $f.ourtoks

    ./sclp -ast -tokens -symtab -icode  $f
    mv $f.ast $f.their
    mv $f.ic $f.theiric
#    mv $f.eval $f.theireval
	mv $f.spim $f.theirspim
	mv $f.sym $f.theirsym
	mv $f.toks $f.theirtoks
    echo $f

	diff $f.ourspim $f.theirspim
	diff $f.oursym $f.theirsym
	diff $f.ouric $f.theiric
#	diff $f.oureval $f.theireval
	diff $f.ourtoks $f.theirtoks
    diff $f.our $f.their
done
