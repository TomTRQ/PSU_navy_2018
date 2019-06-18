##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard ./lib/my/*.c)

SRC2    =	$(wildcard ./src/*.c)

OBJ =	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

NAME	=	navy

NAME2	=	libmy.a

NAME3	=	unit_tests

CFLAGS	=	-I./include

all:	compile

tests_run:	fclean
	@gcc $(SRC) $(SRC2) -c --coverage $(CFLAGS)
	@gcc tests/tests_navy.c -c $(CFLAGS)
	@gcc -o $(NAME3) *.o -lcriterion -lgcov
	@echo "Starting $(NAME3)..."
	@./$(NAME3)

compile:	$(OBJ)	\
		$(OBJ2)
	@ar rc $(NAME2) $(OBJ)
	@mv $(NAME2) ./lib/my
	@echo "Combining the main with the src files..."
	@gcc -o $(NAME) $(OBJ2) main.c -Wall -Wextra -L./lib/my -lmy $(CFLAGS)

%.o: %.c
	@echo "Compiling $@..."
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "Removing .c~ files..."
	@rm -f lib/*.c~
	@rm -f *.c~
	@rm -f src/*.c~

fclean:	clean
	@echo "Removing existing binaries and .o files..."
	@rm -f lib/my/$(NAME2)
	@rm -f $(NAME)
	@rm -f lib/my/*.o *.o src/*.o
	@rm -f *.gcno *.gcda *.o

re:	fclean all

.PHONY:	all clean fclean re
