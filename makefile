FLAGS = -Wall -g

.PHONY: all clean

all: digitcompress


digitcompress: compress.o encodemain.o
	gcc $(FLAGS) compress.o encodemain.o

compress.o: compress.c compress.h
	gcc -c $(FLAGS) compress.c -o compress.o

encodemain.o: encodemain.c compress.h
	gcc -c $(FLAGS) encodemain.c -o encodemain.o

# Cleaning:
clean:
	rm -f digitcompress *.o