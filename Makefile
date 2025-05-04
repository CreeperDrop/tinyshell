CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c =.o)
# INC = -I$(wildcard include/*.h)
INC = -Iinclude

tinyshell: $(SRC)
	$(CC) $^ $(INC) -o $@ $(CFLAGS) 
	chmod +x $@

debug: $(SRC)
	$(CC) $^ $(INC) -o $@ $(CFLAGS) -g
	chmod +x $@

	
clean:
	rm -f src/*.o tinyshell debug
