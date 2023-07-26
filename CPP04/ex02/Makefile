# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 16:24:19 by arasal            #+#    #+#              #
#    Updated: 2023/03/31 22:44:36 by arasal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler Variables
NAME	= Polymorphism3
CC		= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

# File Variables
SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(BOLD)\033[32mPolymorphism is compiled! ༺ (\033[31m♥\033[32m_\033[31m♥\033[32m)༻\n"

clean:

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)\033[32mEverything is fcleaned! ✓ (\033[31m>_<\033[32m)\n"

re: fclean all

.PHONY: all, clean, fclean, re