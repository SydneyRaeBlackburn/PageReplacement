#Troy Ricks: cssc1101
#Sydney Blackburn: cssc1112

#Class: CS570, Professor Leonard, Summer 2017
#Due: June 19, 2017
#Project: Assignment #2, Page Replacement
#File: Makefile

CC = gcc 
CFLAGS = -c
TARGET = a2

all: $(TARGET)

$(TARGET): page.o
	$(CC) page.o -o $(TARGET)
page.o: page.c
	$(CC) $(CFLAGS) page.c

clean:
	rm -f core *.o $(TARGET)