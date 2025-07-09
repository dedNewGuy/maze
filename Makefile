CC = cc 
CFLAGS = -Wall -Wextra -I./include -L./build/raylib

BUILD = build
SRC = src

BUILDS = $(BUILD)/maze.o
SRCS = $(SRC)/maze.c
TARGET = maze

$(BUILDS): $(SRCS)
	$(CC) $(CFLAGS) -o $(BUILDS) -c $(SRCS)


$(TARGET): $(BUILDS)
	$(CC) $(CFLAGS) -o $(TARGET) $(BUILDS) -lraylib -lm

.PHONY = clean run

run: $(TARGET)
	./$(TARGET)

clean: 
	rm $(BUILDS)
	rm $(TARGET)
