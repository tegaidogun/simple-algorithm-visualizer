CC = gcc
CFLAGS = -Iinclude
LDFLAGS = 
OBJ = $(patsubst %.c,%.o,$(wildcard src/*.c src/*/*.c))
EXEC = visualizer

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(EXEC)
