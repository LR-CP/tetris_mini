all:
	mkdir -p debug
	make build

build:
	gcc src/tetris.c src/draw.c src/input.c src/terminal.c -Iinc/ -o debug/tetris

clean:
	rm -f tetris

run:
	./debug/tetris