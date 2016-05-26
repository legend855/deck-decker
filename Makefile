#Makefile for project 2

#flags
CFLAGS = -std=c++11 -g -w
CC = g++

default: main

main: driver.o cards.o hands.o play.o
	$(CC) $(CFLAGS) -o main driver.o cards.o hands.o play.o

driver.o: driver.cc cards.h hands.h play.h
	$(CC) $(CFLAGS) -c driver.cc -o driver.o

cards.o: cards.cc cards.h
	$(CC) $(CFLAGS) -c cards.cc -o cards.o

hands.o: hands.cc cards.h hands.h
	$(CC) $(CFLAGS) -c hands.cc -o hands.o

play.o: play.cc play.h cards.h hands.h
	$(CC) $(CFLAGS) -c play.cc -o play.o

clean:
	rm *.o main
