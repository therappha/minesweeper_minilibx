
NAME= game
CC= cc
CFLAGS = -g  -I $(INCLUDES)
LDFLAGS =  -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm
INCLUDES= ./includes
LIBFT_DIR= ./libs/libft
MLX_DIR= ./libs/mlx
MLX= $(MLX_DIR)/libmlx.a
LIBFT= $(LIBFT_DIR)/libft.a
SRCS_DIR= ./srcs

SRCS= $(SRCS_DIR)/main.c $(SRCS_DIR)/input_handler.c $(SRCS_DIR)/free_displays.c \
$(SRCS_DIR)/make_window.c $(SRCS_DIR)/load_images.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)
	@echo "${GREEN}Project built!${RESET}"
	@echo "${GREEN}Please use${RESET} ${YELLOW}./game <board size x> <board size y> <number of bombs>${RESET}"

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Compiling game!"

%.o : %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory


$(MLX):
	@make -C $(MLX_DIR) --no-print-directory

clean:
	@rm -rf $(OBJS)
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@make clean -C $(MLX_DIR) --no-print-directory
	@echo "Cleaning Objects!"
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@echo "Cleaning Objects and game!"

re: fclean all

.PHONY: all clean fclean re

GREEN  := \033[0;32m
YELLOW := \033[0;33m
RESET  := \033[0m
