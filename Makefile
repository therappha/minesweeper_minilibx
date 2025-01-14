
NAME= so_long
CC= cc
CFLAGS = -g -Wall -Wextra -Werror -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft
MLX_DIR= ./libs/mlx
MLX= $(MLX_DIR)/libmlx.a
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs

SRCS= $(SRCS_DIR)/so_long.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/free_displays.c \
$(SRCS_DIR)/make_window.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
