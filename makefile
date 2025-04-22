CC=gcc
CFLAGS=-Wall -Wextra 
DEPS=board.h player.h io.h ./ui/ui.h
OBJ=main.o board.o player.o io.o ./ui/ui.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY:
	clean

clean:
	rm -f $(OBJ) *.exe