CC = gcc

CFLAGS = -Wall

LIBS = -lncurses -lSDL2 -lSDL2_mixer -ljson-c

all:
	$(CC) src/main.c -o TheLastConcert $(CFLAGS) $(LIBS)

run:
	./TheLastConcert

clean:
	rm -f TheLastConcert

