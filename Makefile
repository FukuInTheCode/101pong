##
## EPITECH PROJECT, 2023
## my_printf Makefile
## File description:
## Placeholder
##

NAME   = 101pong

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

SRC	= pong.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML) \
	$(CRITERION) -lm
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
