# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestrep <drestrep@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 19:54:56 by drestrep          #+#    #+#              #
#    Updated: 2023/08/02 14:39:33 by drestrep         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		push_swap

LIBFT_DIR	=		libft
LIBFT		=		$(LIBFT_DIR)/libft.a

SRCS		=		$(wildcard	src/*.c)

CC 			= 		gcc
CFLAGS 		= 		-g3 -Wall -Wextra -Werror 

OBJ_DIR		=		obj
OBJS 		= 		$(addprefix obj/, $(notdir $(SRCS:%.c=%.o)))

INCLUDE_DIRS =		-I$(LIBFT_DIR) -Iinclude

all:		$(NAME)

$(NAME):	$(OBJS)  $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $(notdir $(NAME))
	@echo " "
	@echo "䷭䷭䷭䷭    ䷭䷭  ䷭䷭  ䷭䷭䷭䷭  ䷭䷭  ䷭䷭        ䷭䷭䷭䷭  ䷭䷭       ䷭䷭    ䷭䷭    ䷭䷭䷭䷭"
	@echo "䷭䷭  ䷭䷭  ䷭䷭  ䷭䷭  ䷭䷭    ䷭䷭  ䷭䷭        ䷭䷭    ䷭䷭       ䷭䷭  ䷭䷭  ䷭䷭  ䷭䷭  ䷭䷭"
	@echo "䷭䷭䷭䷭    ䷭䷭  ䷭䷭  ䷭䷭䷭䷭  ䷭䷭䷭䷭䷭䷭        ䷭䷭䷭䷭  ䷭䷭  ䷭䷭   ䷭䷭  ䷭䷭䷭䷭䷭䷭  ䷭䷭䷭䷭"
	@echo "䷭䷭      ䷭䷭  ䷭䷭    ䷭䷭  ䷭䷭  ䷭䷭          ䷭䷭  ䷭䷭ ䷭䷭ ䷭䷭ ䷭䷭  ䷭䷭  ䷭䷭  ䷭䷭"
	@echo "䷭䷭       ䷭䷭䷭䷭   ䷭䷭䷭䷭  ䷭䷭  ䷭䷭  ䷭䷭䷭䷭  ䷭䷭䷭䷭    ䷭䷭   ䷭䷭    ䷭䷭  ䷭䷭  ䷭䷭"
	@echo " "


$(OBJ_DIR)/%.o:	src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all