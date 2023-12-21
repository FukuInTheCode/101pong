##
## EPITECH PROJECT, 2023
## 101pong bonus Makefile
## File description:
## Placeholder
##

NAME   = bonus

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include_1 -lm -lcurses -lpthread

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

SRC_BONUS_1 = pongter_main.c \

OBJ_BONUS_1	= $(SRC_BONUS_1:.c=.o)

OBJ = $(OBJ_BONUS_1) \

all: $(NAME)

$(NAME)_1: fclean $(OBJ_BONUS_1)
	@$(CC) -o $(NAME) $(OBJ_BONUS_1) $(CFLAGS) \
		$(CRITERION) $(CSFML)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
