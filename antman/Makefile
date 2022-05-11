##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRCS_C:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

CFLAGS = -W -Werror -Wextra -Wall

SRC		=	sources/

SRC_C	=	create_func.c						\
			file_func.c							\
			free_func.c							\
			get_information.c 					\
			get_information2.c 					\
			get_information3.c 					\
			ini_func.c							\
			ini_func_2.c						\
			linked_func.c						\
			main.c 								\
			save_func.c							\
			save_func_2.c						\
			write_compress.c					\
			fundamental_func/extra_func.c 		\
			fundamental_func/my_callocs.c 		\
			fundamental_func/my_getnbr.c 		\
			fundamental_func/my_strcat.c		\
			fundamental_func/my_charcat.c		\
			fundamental_func/my_return_char.c	\
			fundamental_func/my_strdup.c		\
			fundamental_func/my_strcpy.c 		\
			fundamental_func/my_revstr.c		\
			fundamental_func/my_strlen.c 		\
			fundamental_func/my_nbrlen.c		\
			fundamental_func/my_strcmp.c

SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./includes

NAME = 		antman

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g -W -Werror -Wextra -Wall -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
