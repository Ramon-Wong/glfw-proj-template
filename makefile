CC			= gcc
source		= main.c functions.c
objects		= main.o functions.o
option		= -Wall
compile 	= -Wall -c
build		= -Wall -o
library		= -lm -lglfw -lGL -lGLEW
target		= main
executable	= ./main

compile:
	$(CC) $(compile) $(source) $(library)

build:
	$(CC) $(build) $(target) $(objects) $(library)

clean: 
	rm $(target) *.o 
