CC=gcc
UTILS_SRC=$(wildcard src/utils/*.c)
SRC=$(wildcard src/*.c src/errors/*.c)
CFLAGS=-g -O2 -W -Wall -iquote ./src/utils -iquote ./src/logger -iquote ./src/errors
OBJ=$(SRC:.c=.o)
NAME=gidox

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(UTILS_SRC) $(SRC) $(CFLAGS)

clean:
	find . src/utils -name "*.o" -delete\
        -o -name "valgrind*" -delete\
        -o -name "*.gcda" -delete\
        -o -name "*.gcno" -delete\
        -o -name "*~" -delete\
        -o -name "#*#" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
