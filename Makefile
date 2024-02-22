# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 17:41:42 by astavrop          #+#    #+#              #
#    Updated: 2024/02/22 20:32:59 by astavrop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -pedantic
LIBS				+= -L$(FT_PINTF_PATH) -L$(LFT_PATH) -lftprintf -lft
LIBS				+= -L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11
LIBS				+= -lm
INCLUDES			+= -I/usr/include -Imlx-linux -Ift_printf/includes -I./libft -I./include
INCLUDES			+= -Ignl
NAME				= fdf

SRC_DIR				:= ./src/
SRCS				+= $(SRC_DIR)main.c
SRCS				+= $(SRC_DIR)checks.c
SRCS				+= $(SRC_DIR)parse_map.c
SRCS				+= $(SRC_DIR)mlx_init.c
SRCS				+= $(SRC_DIR)draw.c
SRCS				+= $(SRC_DIR)line.c
SRCS				+= $(SRC_DIR)hooks.c
SRCS				+= $(SRC_DIR)clear.c
SRCS				+= $(SRC_DIR)utils.c
SRCS				+= $(SRC_DIR)more_utils.c
SRCS				+= gnl/get_next_line.c

OBJ_DIR				:= ./obj/
OBJS				:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))


DEPS				:= $(OBJS:.o=.d)


FT_PINTF_PATH		= ./ft_printf/
FT_PINTF_BIN		= $(FT_PINTF_PATH)libftprintf.a

LFT_PATH			= ./libft/
LFT_BIN				= $(LFT_PATH)libft.a


MLX_BIN				= libmlx.a
MLX_PATH			= ./minilibx-linux/


all: $(NAME)


$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o,%.d,$@) $(INCLUDES) -c $< -o $@


$(NAME): $(OBJS) $(LFT_BIN) $(FT_PINTF_BIN)
	@if [ ! -e "$(MLX_PATH)$(MLX_BIN)" ]; then \
		echo -n "\033[32;49;3m... Clone MiniLibX ...\033[0m\r"; \
		make -s compile-mlx; \
	fi
	@echo -n "\033[32;49;3m... Compiling code ...\033[0m\r"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)
	@echo "\033[32;49;1m>>>   Done!   <<<\033[0m          "


test: $(NAME)
	@-if [ -f ~/map-gen.py ]; then \
		python3 ~/map-gen.py -10 10 7 7 > ./test_map.fdf; \
		echo "\033[32;49;3mThis map will be used for test:\033[33m"; \
		cat ./test_map.fdf; \
		echo -n "\033[0m"; \
		valgrind ./$(NAME) test_map.fdf; \
		rm ./test_map.fdf; \
	else \
		echo "\033[31;49;3mNo python script at $(HOME)\033[0m"; \
	fi


norm: $(SRCS)
	-norminette $(SRCS) colors.h fdf.h $(LFT_PATH)libft.h \
		$(FT_PINTF_PATH)includes/ft_printf.h gnl/get_next_line.h \
		| grep --color=always 'ERROR!\|OK!'


$(FT_PINTF_BIN):
	@echo -n "\033[32;49;3m... Making ft_printf ...\033[0m\r"
	@$(MAKE) -sC $(FT_PINTF_PATH)
	@echo -n "\033[32;49;1m> ft_printf ready! <\033[0m\r"


$(LFT_BIN):
	@echo -n "\033[32;49;3m... Making libft ...\033[0m\r"
	@$(MAKE) -sC $(LFT_PATH)
	@echo -n "\033[32;49;1m> libft ready! <\033[0m\r"


compile-mlx:
	@rm -rf $(MLX_PATH)
	@git clone https://github.com/42Paris/minilibx-linux.git
	@echo -n "\033[32;49;3m... Making MiniLibX ...\033[0m\r"
	@make -C $(MLX_PATH)
	@echo -n "\033[32;49;1m> MiniLibX ready! <\033[0m\r    "


clean:
	@rm -f $(OBJS)
	@echo "\033[32;1mObjects cleand!\033[0m"


fclean: clean
	@rm -f $(NAME)
	@make -sC $(FT_PINTF_PATH) fclean
	@rm -rf $(OBJ_DIR)
	@echo "\033[32mft_printf cleand!\033[0m"
	@make -sC $(LFT_PATH) fclean
	@echo "\033[32mlibft cleand!\033[0m"
	@make -sC $(MLX_PATH) clean
	@echo "\033[32mMiniLibX cleand!\033[0m"
	@echo "\033[32;1mEverything cleand!\033[0m"


re: fclean all


.PHONY: all clean fclean re compile-mlx test norm