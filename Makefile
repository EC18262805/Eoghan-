Assignment3.o: main.c declarations.h createPolys.h addPolys.h subtractPoly.h Multiply.h DividePoly.h NormalisePoly.h
	gcc -Wall -ggdb -c main.c

clean:
	rm *# *~
