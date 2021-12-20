# Makefile for Writing Make Files Example
 
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -ggdb
 
# ****************************************************

# Targets needed to bring the executable up to date
all: clean main pre_proc assembler
 
main: main.o test.o
	$(CC) $(CFLAGS) -o main_exe main.o test.o
	
main.o: main.cpp test.h main.h
	$(CC) $(CFLAGS) -c main.cpp
	
test.o: test.cpp test.h
	$(CC) $(CFLAGS) -c test.cpp
	
pre_proc: test.cpp test.h main.cpp main.h
	$(CC) $(CFLAGS) -E test.cpp -o test.ii
	$(CC) $(CFLAGS) -E main.cpp -o main.ii

assembler: test.cpp test.h main.cpp main.h
	$(CC) $(CFLAGS) -S test.cpp -o test.s
	$(CC) $(CFLAGS) -S main.cpp -o main.s
	
clean:
	del *.o *.exe
	
	