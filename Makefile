.POSIX:

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

SRC_DIR = src
# OBJ = $(SRC:.c =.o)
# INC = -I$(wildcard include/*.h)
INC = -Iinclude

tinyshell: 
	$(CC) $(SRC_DIR)/*.c $(INC) -o $@ $(CFLAGS) 
	chmod +x $@

debug: 
	$(CC) $(SRC_DIR)/*.c $(INC) -o $@ $(CFLAGS) -g
	chmod +x $@

	
clean:
	rm -f src/*.o tinyshell debug
