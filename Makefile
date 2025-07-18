CC = cc 
CFLAGS = -Wall -Wextra -I./include -L./build/raylib

BUILD = build
SRC = src

BUILDS = $(BUILD)/maze.o
SRCS = $(SRC)/maze.c $(SRC)/grid.c
TARGET = maze

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) -lraylib -lm

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean: 
	rm $(BUILDS)
	rm $(TARGET)
