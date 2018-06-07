##
##  Created by Nicolas.
##

NAME	= trade_bordeaux_$

RM	= rm -f

CC	= g++

CFLAGS	= -I include -std=c++1z
CFLAGS	+= -Wall -Wextra -W

SRC	= src/Bot.cpp \
      src/MarketPlace.cpp   \
      src/main.cpp

OBJ	= $(SRC:.cpp=.o)

BOLD	= "\033[1m"

RED     = "\033[31m"

GREEN	= "\033[32m"

YELLOW	= "\033[33;1m"

RESET	= "\033[0m"

OKTEXT	= \r"$(BOLD)$(GREEN)"\342\234\224"$(RESET)"

KOTEXT	= \r"$(BOLD)$(RED)"\342\234\230"$(RESET)"

ARROW	= "$(BOLD)$(YELLOW)"\342\206\222"$(RESET)"

COND	= printf "$(OKTEXT)\n"

$(NAME): $(OBJ)
	@printf "\n$(KOTEXT) Binary generated : "$(BOLD)"$(NAME)"$(RESET)""
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && $(COND)

%.o: %.cpp
	@printf "$(KOTEXT) %s $(ARROW) %s" "$<" "$@"
	@$(CC) -o $@ $< -c $(CFLAGS) && $(COND)

all: $(NAME)

clean:
	@printf "$(KOTEXT) Cleaning objects"
	@$(RM) $(OBJ) && $(COND)

fclean: clean
	@printf "$(KOTEXT) Cleaning binary"
	@$(RM) $(NAME) && $(COND)

re: fclean _newline all

_newline:
	@printf "\n"

.PHONY: all install uninstall clean fclean re _newline bonus
