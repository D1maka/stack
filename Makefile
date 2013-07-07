CFLAGS=-Wall -g

all: driver

driver: node.o stack.o

clean:
	rm -f driver