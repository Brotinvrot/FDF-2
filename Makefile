NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -g

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

INCLUDES = -I $(LIBFT_DIR) -I $(MLX_DIR)

LDFLAGS = $(MLX) -lXext -lX11 -lm

SRC = main.c parser.c filling.c window.c draw.c support_draw.c rotate.c
OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(MLX_DIR) $(MLX) $(NAME)

$(MLX_DIR):
	git clone $(MLX_REPO) $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX):
		$(MAKE) -C $(MLX_DIR)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) $(LDFLAGS) -o $(NAME) $(LIBFT) $(INCLUDES)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		rm -f $(OBJ)

fclean : clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re : fclean  all

.PHONY: all clean fclean re
