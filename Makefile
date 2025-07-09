CC=cc
CFLAGS=-Wall -Wextra

maze: maze.c
	$(CC) $(CFLAGS) -o maze maze.c
