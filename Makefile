# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 22:28:51 by abelov            #+#    #+#              #
#    Updated: 2023/10/23 22:34:31 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= bsq
CC				:= gcc-13
INC_DIR			=  ./include
INCLUDE_FLAGS	:= -I. -I $(INC_DIR) -I/usr/include
OPTIMIZE_FLAGS	:= -O0
DEBUG_FLAGS		:= -g3 -gdwarf-3
MANDATORY_FLAGS	:= -Wall -Wextra -Werror
CFLAGS			= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS)

LIBFT_PATH		=  ./lib/ft
LIBFT			=  $(LIBFT_PATH)/libft.a
LIBSQ_PATH		=  ./lib/sq
LIBSQ			=  $(LIBSQ_PATH)/libsq.a


LINK_FLAGS		:= -L $(LIBFT_PATH) -L $(LIBSQ_PATH) -lsq -lft

CTAGS			:= ctags
RM				:= /bin/rm

BUILD_DIR		= build
SRC_DIR			= src
OBJ_DIR			= $(BUILD_DIR)/obj

SRC_FS	 		:= main.c
SRCS	 		:= $(SRC_FS:%.c=$(SRC_DIR)/%.c)
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: clean $(NAME) test

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<

$(LIBFT):
			@make -C $(LIBFT_PATH) -j8

$(LIBSQ):
			@make -C $(LIBSQ_PATH) -j8

$(NAME): $(OBJS) $(LIBFT) $(LIBSQ)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ $^  $(LINK_FLAGS)

test: $(NAME)
	printf '\033[36m%s\033[0m\n' 'this is a test'
	./bsq test/map1.txt
	@echo
	./bsq test/map2.txt
	@echo
	./test/map_generator.pl 80 80 15 | ./bsq

clean:
		@$(RM) -fr $(OBJ_DIR)
		@make -C $(LIBFT_PATH) clean
		@make -C $(LIBSQ_PATH) clean

fclean: clean
		@$(RM) -fr $(NAME) $(BUILD_DIR) a.out
		@make -C $(LIBFT_PATH) fclean
		@make -C $(LIBSQ_PATH) fclean

re: fclean all

norm:
		@norminette $(SRCS)
		@make -C $(LIBFT_PATH) norm
		@make -C $(LIBSQ_PATH) norm

.PHONY: all clean test re
