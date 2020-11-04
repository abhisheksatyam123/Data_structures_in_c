CC=gcc
CFLAGS=-Wall
EXECUTABLE=list
list: dll.o main.c
	$(CC) $(CFLAGS) dll.o main.c -o $(EXECUTABLE)
dll.o: dll.h 
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)