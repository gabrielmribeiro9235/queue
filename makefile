CC = gcc
CFLAGS = -Wall -Wextra

.PHONY: all clean simple circular

all: simple circular

simple: simple-queue/simple_queue

simple-queue/simple_queue: simple-queue/main.o simple-queue/queue.o
	$(CC) $(CFLAGS) -o simple-queue/simple_queue simple-queue/main.o simple-queue/queue.o

simple-queue/main.o: simple-queue/main.c simple-queue/queue.h
	$(CC) $(CFLAGS) -c -o simple-queue/main.o simple-queue/main.c

simple-queue/queue.o: simple-queue/queue.c simple-queue/queue.h
	$(CC) $(CFLAGS) -c -o simple-queue/queue.o simple-queue/queue.c

circular: circular-queue/circular_queue

circular-queue/circular_queue: circular-queue/main.o circular-queue/queue.o
	$(CC) $(CFLAGS) -o circular-queue/circular_queue circular-queue/main.o circular-queue/queue.o

circular-queue/main.o: circular-queue/main.c circular-queue/queue.h
	$(CC) $(CFLAGS) -c -o circular-queue/main.o circular-queue/main.c

circular-queue/queue.o: circular-queue/queue.c circular-queue/queue.h
	$(CC) $(CFLAGS) -c -o circular-queue/queue.o circular-queue/queue.c

clean:
	rm -f simple-queue/simple_queue simple-queue/*.o circular-queue/circular_queue circular-queue/*.o