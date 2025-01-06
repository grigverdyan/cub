# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

# Compiler
EXEC			= cub3D
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

# Includes
INCLUDE_DIR 	= includes
INCLUDES		= -I$(INCLUDE_DIR)

# Sources
SRC_DIR			= src
SRC_FILES 		= $(shell find src -name "*.c")

# Object files
OBJ_DIR			= objs
OBJS 			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# MLX lib
MLX_DIR			= mlx_macos
MLX				= $(MLX_DIR)/libmlx.a
LDLIBS			= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
INCLUDES		+= -I$(MLX_DIR)

all : $(MLX) $(OBJ_DIR) $(EXEC)

$(MLX) :
	@echo $(CYAN) " - Making mlx..." $(RESET)
	@$(MAKE) $(MLX_DIR)
	@echo $(YELLOW) " - Made mlx!" $(RESET)

$(OBJ_DIR) :
	@$(MKDIR) $(OBJ_DIR)

$(EXEC) : $(OBJS) Makefile
	@echo $(GREEN) " - Compiling $(EXEC)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(EXEC) 
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)

	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@$(RM) $(OBJ_DIR)
	@echo $(RED) " - Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(EXEC)
	@$(MAKE) $(MLX_DIR) clean
	@echo $(RED) " - Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
