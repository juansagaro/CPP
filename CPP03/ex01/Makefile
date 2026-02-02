# Variables del Proyecto
NAME        = serena,MyLove!
CXX         = c++
CXXFLAGS    = -std=c++98 -Wall -Wextra -Werror

# Directorios
SRC_DIR     = src
OBJ_DIR     = obj

# Archivos Fuente
SRC_FILES   = main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp

# Rutas completas (SRC = src/main.cpp, etc.)
SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Objetos: Sustituimos 'src/%.cpp' por 'obj/%.o'
OBJ         = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# --- Reglas ---

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@echo "Done!"

# Regla para compilar objetos
# 1. Crea el directorio obj si no existe (mkdir -p)
# 2. Compila el .cpp de src/ hacia .o en obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJ_DIR)
	@echo "Done"

fclean: clean
	@echo "Cleaning executable"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re