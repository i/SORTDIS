CC = gcc
CFLAGS = -Wall -g
CFILES = src/sorted-list.c src/main.c -c

all: main archive
	$(CC) sorted-list.o main.o -o sl
	rm *.o

main:
	$(CC) $(CFILES) $(CFLAGS)

archive: main
	ar -r libsl.a sorted-list.o

clean:
	rm *.o sl libsl.a
