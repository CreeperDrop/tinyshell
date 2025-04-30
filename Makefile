CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c =.o)
# INC = -I$(wildcard include/*.h)
INC = -Iinclude

.PHONY: all

all: tinyshell

tinyshell: $(OBJ)
	$(CC) $(SRC) $(INC) -o $@ $(CFLAGS) 
	chmod +x $@

debug: $(OBJ)
	$(CC) -g $(SRC) $(INC) -o $@ $(CFLAGS) -g
	chmod +x $@

	
clean:
	rm -f src/*.o tinyshell debug
