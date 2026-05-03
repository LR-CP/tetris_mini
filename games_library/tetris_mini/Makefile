CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2 -Iinc
TARGET = debug/tetris

SRC = src/tetris.c src/render.c src/input.c src/terminal.c src/state.c src/shape.c

all: $(TARGET)

$(TARGET):
	mkdir -p debug
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -rf debug

run: $(TARGET)
	./$(TARGET)