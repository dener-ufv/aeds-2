all: main

main: main.c student tree
	gcc main.c student.o tree.o

student: student.c
	gcc -c student.c -o student.o

tree: tree.c
	gcc -c tree.c -o tree.o

clean:
	del *.o
	del *.exe
