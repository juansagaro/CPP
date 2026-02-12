# ************************************************************************** #
#                                                                            #
#                Makefile for GlobalBanksters United                        #
#                Created on  : Thu Nov 20 23:45:02 1989                      #
#                Last update : Wed Jan 04 09:23:52 1992                      #
#                Made by : Brad "Buddy" McLane <bm@gbu.com>                  #
#                                                                            #
# ************************************************************************** #

NAME		= bank

SRCS		= src/Account.cpp src/tests.cpp

OBJS		= $(SRCS:.cpp=.o)

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

Y			= \033[38;5;220m
G			= \033[38;5;46m
R			= \033[38;5;196m
B			= \033[38;5;33m
P			= \033[38;5;129m
C			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(Y)Linking GlobalBanksters United executable...$(C)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(G)╔══════════════════════════════════════════════╗$(C)"
	@echo "$(G)║    GlobalBanksters United App compiled!      ║$(C)"
	@echo "$(G)║         Ready to make some money! 💰         ║$(C)"
	@echo "$(G)╚══════════════════════════════════════════════╝$(C)"

%.o: %.cpp
	@echo "$(B)Compiling $(notdir $<)...$(C)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(R)Removing object files...$(C)"
	@rm -f $(OBJS)
	@echo "$(P)Object files cleaned! ✨$(C)"

fclean: clean
	@echo "$(R)Removing $(NAME) executable...$(C)"
	@rm -f $(NAME)
	@echo "$(P)Everything cleaned! Back to 1992! 🕺$(C)"

re: fclean all

test: all
	@echo "$(Y)Running tests...$(C)"
	@./$(NAME)

.PHONY: all clean fclean re test