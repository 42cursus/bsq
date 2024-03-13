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

#$(info ************ BSQ_SQ ************)

FILES   = sq_legend_parser.c \
          sq_parser.c \
          sq_solver.c \
          sq_utils.c \
          sq_utils2.c \
          sq_utils3.c

SRCS    += $(FILES:%.c=sq/%.c)
