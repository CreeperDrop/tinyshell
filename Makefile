.POSIX:

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

SRC_DIR = src
# OBJ = $(SRC:.c =.o)
# INC = -I$(wildcard include/*.h)
INC_DIR = include
INC = -Iinclude

tinyshell: $(SRC_DIR)/*.c $(INC_DIR)/*.h
	$(CC) $(SRC_DIR)/*.c $(INC) -o $@ $(CFLAGS) 
	chmod +x $@

debug: $(SRC_DIR)/*.c $(INC_DIR)/*.h
	$(CC) $(SRC_DIR)/*.c $(INC) -o $@ $(CFLAGS) -g
	chmod +x $@

	
clean:
	rm -f src/*.o tinyshell debug
