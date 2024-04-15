# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 07:01:53 by ogoman            #+#    #+#              #
#    Updated: 2024/04/09 09:45:56 by ogoman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target file name (library)
NAME = libftprintf.a

# Command for creating a static library
AR = ar rcs

# Command for copying files
CP = cp

# Compiler
CC = cc

# Command for deleting files and directories
RM = rm -rf

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

# Directory with the source files of libft
LIBFT_DIR = ./libft

# Path to the libft library and its name
LIBFT = libft/libft.a

# Source files
SRC_FILES = ft_printf.c ft_putchar_ft.c ft_putstr_ft.c ft_putptr_ft.c ft_putnbr_ft.c \
ft_putuni_ft.c ft_puthex_ft.c ft_format.c

# Object files obtained from source files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Default "all" target
all: $(NAME)

# Rule for building the target file
$(NAME): $(LIBFT) $(OBJ_FILES)
	@$(CP) $(LIBFT) $(NAME) 
	@$(AR) $(NAME) $(OBJ_FILES)

# Rule for building libft
$(LIBFT) : $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)

# Rule for cleaning object files
clean :
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_FILES)

# Rule for full clean (including libft)
fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

# Rule for recompiling
re: fclean all

# Declare targets that are not real files
.PHONY: all clean fclean re
