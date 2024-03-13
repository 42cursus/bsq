# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 18:58:13 by abelov            #+#    #+#              #
#    Updated: 2024/03/12 19:49:02 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#$(info ************ FT_STRING ************)

FILES   = string_utils1.c \
			  string_utils2.c \
			  string_utils3.c \
			  string_utils4.c \
			  string_utils5.c \

SRCS    += $(FILES:%.c=ft_string/%.c)
