CC = g++
CFLAGS = -Wall -Werror -pedantic 
OBJECTS = Triangle.o TFractal.o
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all:TFractal 

TFractal:$(OBJECTS)
	$(CC) $(CFLAGS) -o TFractal $(OBJECTS) $(SFML)
Triangle.o:Triangle.cpp Triangle.h
	$(CC) $(CFLAGS) -o Triangle.o -c Triangle.cpp
TFractal.o:TFractal.cpp
	$(CC) $(CFLAGS) -o TFractal.o -c TFractal.cpp

clean: 
	rm *.o TFractal 