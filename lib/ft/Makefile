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

NAME			:= libft.a
CC				:= gcc-13

ifdef BUILD_WITH_ASAN
DEBUG_FLAGS		:= -g3 -gdwarf-3 \
					-fsanitize-address-use-after-scope \
					-fsanitize=address,undefined,bounds,alignment,object-size \
					-fsanitize=shift,signed-integer-overflow,null,return \
					-fsanitize=float-divide-by-zero,float-cast-overflow \
					-fno-sanitize-recover=all
else
DEBUG_FLAGS		:= -g3 -gdwarf-3
endif

INCLUDE_FLAGS	:= -I. -I./include -I/usr/include
OPTIMIZE_FLAGS	:= -O0
MANDATORY_FLAGS	:= -Wall -Wextra -Werror
CFLAGS			= $(MANDATORY_FLAGS) $(OPTIMIZE_FLAGS)

# CFLAGS += -ffile-prefix-map=$(PWD)=/src
# optional, for macro-expansion paths:
# CFLAGS += -fmacro-prefix-map=$(PWD)=/src
# only DWARF rewritten:
# CFLAGS += -fdebug-prefix-map=$(PWD)=/src

CTAGS			:= ctags
LIB_COMMAND		:= ar rcs
RM				:= /bin/rm

BUILD_DIR		= build
OBJ_DIR			= $(BUILD_DIR)/obj
SRCS	 		:=
DIRS			:= ft_ctype \
					ft_libio \
					ft_stdlib \
					ft_string

include $(addsuffix /Makefile.mk,$(DIRS))

OBJS			= $(SRCS:%.c=$(BUILD_DIR)/obj/%.o)

all: $(NAME)

$(BUILD_DIR):
		mkdir -pv $(BUILD_DIR)

$(BUILD_DIR)/obj/%.o: %.c
		@mkdir -pv $(@D)
		$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) -c $(abspath $<) -o $@

$(NAME): $(BUILD_DIR) $(OBJS)
		$(LIB_COMMAND) $@ $(OBJS)

clean:
		$(RM) -f $(OBJS) $(ASM_FILES)

fclean: clean
		$(RM) -fr $(NAME) $(BUILD_DIR) a.out

re: fclean all

norm:
		@norminette $(SRCS)

.PHONY: all clean flean re norm $(NAME)
