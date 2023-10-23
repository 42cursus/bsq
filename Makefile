# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 22:28:51 by abelov            #+#    #+#              #
#    Updated: 2023/10/23 22:34:31 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
DEBUG_FLAGS		:= -g
WARNING_FLAGS	:= -Wall -Wextra -Werror
CFLAGS = $(DEBUG_FLAGS) $(WARNING_FLAGS)

.PHONY: all
.DEFAULT: all
all:	clean bsq test

SOURCES = $(wildcard *.c)

.PHONY: bsq
bsq: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: tests
test:
	printf '\033[36m%s\033[0m\n' 'this is a test'
	./bsq 1 2

.PHONY: clean
clean:
	@echo cleaning
	rm -rf a.out bsq main;
	rm -rf *.o;
