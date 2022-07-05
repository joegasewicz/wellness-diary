all:

clean:
	rm -rf gui

build:
	gcc gui.c -o gui `pkg-config --cflags --libs gtk+-3.0`

run:
	./gui