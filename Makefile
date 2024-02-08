# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:41:42 by astavrop          #+#    #+#              #
#    Updated: 2024/02/08 21:43:31 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -g
LIBS				= -L$(FT_PINTF_PATH) -L$(LFT_PATH) -lftprintf -lft -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES			= -I/usr/include -Imlx_linux
NAME				= fdf

SRCS				+= fdf.c
SRCS				+= hooks.c
OBJS				= $(SRCS:.c=.o)

FT_PINTF_PATH		= ./ft_printf/
FT_PINTF_BIN		= $(FT_PINTF_PATH)libftprintf.a

LFT_PATH			= ./libft/
LFT_BIN				= $(LFT_PATH)libft.a


MLX_BIN				= libmlx.a
MLX_PATH			= ./minilibx-linux/


all: $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS) $(LFT_BIN) $(FT_PINTF_BIN)
	@if [ ! -d $(MLX_PATH) ]; then \
		@make -s compile-mlx; \
	fi
	@echo -n "\033[32;49;3m... Compiling code ...\033[0m\r"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)
	@echo "\033[32;49;1m>>>   Done!   <<<\033[0m          "


$(FT_PINTF_BIN):
	@echo -n "\033[32;49;3m... Making ft_printf ...\033[0m\r"
	@$(MAKE) -sC $(FT_PINTF_PATH)
	@echo -n "\033[32;49;1m> ft_printf ready! <\033[0m\r"


$(LFT_BIN):
	@echo -n "\033[32;49;3m... Making libft ...\033[0m\r"
	@$(MAKE) -sC $(LFT_PATH)
	@echo -n "\033[32;49;1m> libft ready! <\033[0m\r"


compile-mlx:
	@echo -n "\033[32;49;3m... Making MiniLibX ...\033[0m\r"
	@make -C $(MLX_PATH)
	@echo -n "\033[32;49;1m> MiniLibX ready! <\033[0m\r    "


clean:
	@rm -f $(OBJS)
	@echo "\033[32;1mObjects cleand!\033[0m"


fclean: clean
	@rm -f $(NAME)
	@make -sC $(FT_PINTF_PATH) fclean
	@echo "\033[32mft_printf cleand!\033[0m"
	@make -sC $(LFT_PATH) fclean
	@echo "\033[32mlibft cleand!\033[0m"
	@make -sC $(MLX_PATH) clean
	@echo "\033[32mMiniLibX cleand!\033[0m"
	@echo "\033[32;1mEverything cleand!\033[0m"


re: fclean all


.PHONY: all clean fclean re compile-mlx