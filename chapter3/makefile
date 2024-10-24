main:main.o
	gcc -o main main.o
main.o:main.c FindMax.h FindMax.c
	gcc -c main.c FindMax.c
clean: 
	rm -i *.o