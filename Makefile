NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -g

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

LDFLAGS = ./minilibx-linux/libmlx.a -lXext -lX11 -lm

SRC = main.c parser.c filling.c window.c draw.c support_draw.c
OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) $(LIBFT) $(INCLUDES)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
		$(MAKE) -C $(LIBFT_DIR) clean
		rm -f $(OBJ)

fclean : clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re : fclean  all

.PHONY: all clean fclean re
