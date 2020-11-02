CC=gcc
CFLAGS=-Wall
EXECUTABLE=test
list: queue.o main.c stack.o
	$(CC) $(CFLAGS) stack.o queue.o main.c -o $(EXECUTABLE)
queue.o: queue.h
stack.o: stack.h
clean:
	rm -rf *.o *.gch $(EXECUTABLE)
leaks:
	valgrind --leak-check=yes ./$(EXECUTABLE)
