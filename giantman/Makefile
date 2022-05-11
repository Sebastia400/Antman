##
## EPITECH PROJECT, 2021
## d10
## File description:
## description
##

OBJ = $(SRC:.c=.o)

LIB = -L./lib/my -lmy

SFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

CFLAGS = -W -Werror -Wextra -Wall

##SRC		=	sources/

SRC	=		sources/main.c								\
			sources/main2.c								\
			sources/file_func.c 						\
			sources/fundamental_func/extra_func.c 		\
			sources/fundamental_func/my_callocs.c 		\
			sources/fundamental_func/my_getnbr.c 		\
			sources/fundamental_func/my_strcat.c		\
			sources/fundamental_func/my_charcat.c		\
			sources/fundamental_func/my_return_char.c	\
			sources/fundamental_func/my_strdup.c		\
			sources/fundamental_func/my_strcpy.c 		\
			sources/fundamental_func/my_revstr.c		\
			sources/fundamental_func/my_strlen.c 		\
			sources/fundamental_func/my_nbrlen.c		\
			sources/fundamental_func/my_strcmp.c


SRCS_C	= 	$(addprefix $(SRC), $(SRC_C))

CFLAGS = -I./includes

NAME = 		giantman

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g -W -Werror -Wextra -Wall -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
