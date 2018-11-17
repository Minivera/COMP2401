person.o: person.h person.c mystat.h 
	gcc -c person.c
    
mystat.o: mystat.h mystat.c
	gcc -c mystat.c
    
main.o: main.c
	gcc -c main.c
    
tutorial9: main.o person.o mystat.o
	gcc -o tutorial9 main.o person.o mystat.o

build:
	make person.o
	make mystat.o
	make main.o
	make tutorial9
	make clean
    
clean:
	rm -f *.o