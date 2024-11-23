NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

PREF_SRC = src/
PREF_OBJ = obj/
DEST_DIR = $(shell pwd)/

SRC = $(addprefix $(PREF_SRC), ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_strdup.c ft_strlen.c ft_memcmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_striteri.c \
		ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
		ft_strlcpy.c ft_substr.c ft_strlcat.c ft_strncmp.c ft_strjoin.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strncpy.c \
		get_next_line.c gnl_utils.c ft_strcpy.c ft_atoi_hex.c)
		
BONUS_SRC = $(addprefix $(PREF_SRC), ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c)

OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))
BONUS_OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(BONUS_SRC))

all: $(DEST_DIR)$(NAME)

$(DEST_DIR)$(NAME): $(OBJ)
	ar rc $(DEST_DIR)$(NAME) $(OBJ)
	ranlib $(DEST_DIR)$(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(DEST_DIR)$(NAME) $(OBJ) $(BONUS_OBJ)
	ranlib $(DEST_DIR)$(NAME)

$(PREF_OBJ)%.o: $(PREF_SRC)%.c | $(PREF_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(PREF_OBJ):
	mkdir -p $(PREF_OBJ)

clean:
	rm -rf $(PREF_OBJ)

fclean: clean
	rm -f $(DEST_DIR)$(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
