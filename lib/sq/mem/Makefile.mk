# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 18:58:13 by abelov            #+#    #+#              #
#    Updated: 2024/03/12 18:58:16 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#$(info ************ BSQ_MEM ************)

FILES   = mem_utils.c

SRCS    += $(FILES:%.c=mem/%.c)
