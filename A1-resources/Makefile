SCAN = a1



yoursclp : $(SCAN).l parser.tab.h
	lex $(SCAN).l
	g++  lex.yy.c -include allheaders.h -L. -Wl,-rpath=.  -o yoursclp -lsclpshared -lfl -ly

clean:
	rm -f lex.yy.* yoursclp a.out
