# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 15:47:43 by zamazzal          #+#    #+#              #
#    Updated: 2019/03/04 20:03:46 by zamazzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS_PATH = srcs/
OBJ_PATH = obj/
LIBFT_PATH = libft/

FLAGS = -Wall -Wextra -Werror
Libft = -L $(LIBFT_PATH) -lft
INCLUDES = -I includes/ -I $(LIBFT_PATH)

srcs_files =	ft_infos.c \
				ft_list.c \
				ft_ls.c \
				ft_main.c \
				ft_messages.c \
				ft_rev.c \
				ft_show.c \
				ft_tools1.c \
				ft_tools2.c \

SRCS = $(addprefix $(SRCS_PATH), $(srcs_files))
OBJ = $(addprefix $(OBJ_PATH), $(srcs_files:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(Libft) $(INCLUDES) -o $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAGS) $(INCLUDES) $< -o $@
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"

clean:
	@make -C $(LIBFT_PATH) clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\x1B[96mObjects Files \x1B[90;0m[\x1B[34;1m $(notdir $(OBJ)) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -f $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"

re: fclean all

.PHONY: all, clean, fclean, re
