#Makefile
OBJS = pa1.o client.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

client: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o client
client.o: client.cpp pa1.h
	$(CC) $(CFLAGS) client.cpp
pa1.o: pa1.cpp pa1.h
	$(CC) $(CFLAGS) pa1.cpp
clean:
	\rm *.o *~ client
