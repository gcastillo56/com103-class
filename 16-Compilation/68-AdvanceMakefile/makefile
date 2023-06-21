# A bit more advanced version of a Makefile
# Observe the use of Makefile variables (CC, CFLAGS, DEPS, OBJ)
# Also observe the use of the wildcards and special characters
# in order to aovid being very explicit in the creation of the 
# file.

# The comipler we will use
CC=gcc
# The flags for the compilation
CFLAGS=-I.
# The files that are part of the dependencies
DEPS = vehicles.h
# The target of the files that contain executable code
OBJ = main.o vehicles.o cars.o bikes.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o all