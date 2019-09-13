CC=g++
#CFLAGS = -ggdb -Wall
CFLAGS =

all: driver

#put all the file needed, like .h files as well
#note, you need a tab, not spaces.

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

driver: driver.o
	$(CC) $(CFLAGS) -o driver driver.o

clean:
	rm -f driver.o driver
