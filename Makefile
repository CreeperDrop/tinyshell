CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c =.o)
# INC = -I$(wildcard include/*.h)
INC = -Iinclude

.PHONY: all

all: tinyshell

tinyshell: $(SRC)
	$(CC) $^ $(INC) -o $@ $(CFLAGS) 
	chmod +x $@

debug: $(SRC)
	$(CC) -g $^ $(INC) -o $@ $(CFLAGS) -g
	chmod +x $@

	
clean:
	rm -f src/*.o tinyshell debug
