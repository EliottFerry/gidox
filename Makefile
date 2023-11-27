CC=gcc
UTILS_SRC=	src/utils/str_to_word_array.c \
			src/utils/check_file_extension.c
SRC=src/main.c \
	src/errors/errors.c
CFLAGS=-W -Wall -I ./src/utils -I ./src/logger -I ./src/errors
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
