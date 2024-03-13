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

NAME			:= libsq.a
CC				:= cc
DEBUG_FLAGS		:= -g3 -gdwarf-3
INCLUDE_FLAGS	:= -I. -I./include -I/usr/include -I../../include
OPTIMIZE_FLAGS	:= -O0
MANDATORY_FLAGS	:= -Wall -Wextra -Werror
CFLAGS			= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS)

CTAGS			:= ctags
LIB_COMMAND		:= ar rcs
RM				:= /bin/rm

BUILD_DIR		= build
OBJ_DIR			= $(BUILD_DIR)/obj
SRCS	 		:=
DIRS			:= mem sq

include $(addsuffix /Makefile.mk,$(DIRS))

OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(BUILD_DIR):
		@mkdir -p $(BUILD_DIR)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) -c $^ -o $@

$(NAME): $(BUILD_DIR) $(OBJS)
		$(LIB_COMMAND) $@ $(OBJS)

clean:
		@$(RM) -fr $(OBJ_DIR)

fclean: clean
		@$(RM) -fr $(NAME) $(BUILD_DIR) a.out

re: fclean all

norm:
		@norminette $(SRCS)

.PHONY: all clean flean re norm $(NAME)
