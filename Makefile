# Target
NAME = so_long

# Command for copying files
CC = cc

# Header
HEADER = $(SRCF_DIR)/so_long.h

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -framework AppKit -framework OpenGL -L./helper_functions/minilibx42 -lmlx

# Command for deleting files and directories
RM = rm -rf

# Libft directory and path
LIBFT_DIR = ./helper_functions/ft_printf/libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX_42 directory and path
MLX_42_DIR = ./helper_functions/minilibx42
MLX_42 = $(MLX_42_DIR)/libmlx.a

# Printf directory and path
PRINTF_DIR = ./helper_functions/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

# So_Long directory and files
SRCF_DIR = ./srcf
SRCF	=	so_long.c \
					texture.c \
					game_init.c \
					read_map.c \
					map_checking.c \
					action.c \
					gameplay.c \
					exit_game.c

#Sources from source files
SOURCES = $(addprefix $(SRCF_DIR)/, $(SRCF))

# Object files obtained from source files
SL_OBJF = $(SOURCES:.c=.o)

# ANSI Escape Codes
BGreen=\033[1;32m
BRed=\033[1;31m

# Default "all" target
all : tag $(NAME)

# Rule for building libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Rule for building mlx_42 lib
$(MLX_42):
	@$(MAKE) -C $(MLX_42_DIR)

# Rule for building printf
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

# Rule for building the target file
$(NAME): $(SL_OBJF) $(LIBFT) $(MLX_42) $(PRINTF)
	@echo "\nBuilding target file: $(NAME)"
	@$(CC) $(CFLAGS) $(SL_OBJF) $(LIBFT) $(PRINTF) $(MLX_42) $(MLXFLAGS) -o $(NAME)

# Rule for building object files
%.o: %.c $(HEADER) 
	@/bin/echo -n "..........."
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

# Rule for cleaning object files
clean:
	@echo "$(BRed)Cleaning object files"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	@$(MAKE) clean -C $(MLX_42_DIR)
	@$(RM) $(SL_OBJF)
	@echo ".......................... READY"

# Rule for full clean (including libft, printf, mlx_42)
fclean:
	@echo "$(BRed)Cleaning object files and ./so_long"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	@$(RM) $(NAME) $(SL_OBJF)
	@if [ -e .tag ]; then \
		$(RM) .tag; \
	fi

# Rule for recompiling
re: fclean all

# Declare targets that are not real files
.PHONY: all clean fclean re libft minilibx42

# Rule for displaying the tag
tag:
	@if [ ! -e .tag ]; then \
		echo "$(BGreen)"; \
		echo " ░▒▓███████▓▒░░▒▓██████▓▒░░        ▒▓█▓▒░      ░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░"; \
		echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░        ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░"; \
		echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░        ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░"; \
		echo " ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░        ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒▒▓███▓▒░"; \
		echo "       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░        ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░"; \
		echo "       ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░   OG   ▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░"; \
		echo "░▒▓███████▓▒░ ░▒▓██████▓▒░░ ██████ ▒▓████████▓▒░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░"; \
		touch .tag; \
	fi

