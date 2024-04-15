
# librari name
NAME = libft.a

# compailing
CC = cc

RM = rm -rf

# flags
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

BGreen=\033[1;32m

HEADER = .

# list of files
SRC_FILES = ft_isalpha.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_isprint.c ft_memcmp.c ft_memcpy.c ft_isdigit.c \
ft_strjoin.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c \
ft_get_next_line.c

# from .c to .o
OBJ_FILES = $(SRC_FILES:.c=.o)

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
ft_lstiter_bonus.c ft_lstmap_bonus.c

all: $(NAME)

# Building the library
$(NAME): $(OBJ_FILES)
	@$(AR) $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@$(RM) $(OBJ_FILES)

fclean: clean clean_bonus
	@$(RM) $(NAME)

re: fclean all

#BONUS

bonus: $(OBJ_BONUS)
	@$(AR) $(NAME) $(OBJ_BONUS)

clean_bonus:
	@$(RM) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus

