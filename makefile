assembler: assembler.o asmWord.o labelTable.o assemberlHelper.o
	gcc -o assembler assembler.o asmWord.o labelTable.o assemberlHelper.o
 
assembler.o: assembler.c asmWord.h assemblerHelper.h labelTable.h
	gcc -c -g -Wall -ansi -pedantic assembler.c -o assembler.o

assemberlHelper.o: assemberlHelper.c assemberlHelper.h
	gcc -c -g -Wall -ansi -pedantic assemberlHelper.c -o assemberlHelper.o

labelTable.o: labelTable.c labelTable.h
	gcc -c -g -Wall -ansi -pedantic labelTable.c -o labelTable.o

asmWord.o: asmWord.c asmWord.h
	gcc -c -g -Wall -ansi -pedantic asmWord.c -o asmWord.o
