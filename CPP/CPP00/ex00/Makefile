# Makefile
NAME    = megaphone
CXX     = c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror

SRC     = megaphone.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Done"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	@echo "Cleaning objects"
	@rm -f $(OBJ)
	@echo "Done"

fclean: clean
	@echo "Cleaning executables"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re
