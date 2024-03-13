# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 22:50:54 by abelov            #+#    #+#              #
#    Updated: 2023/10/23 22:50:57 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.8.2)

project("bsq" VERSION 0.1.0 LANGUAGES C ASM)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_REQUIRED_LIBRARIES "-lbsd")

set(TARGET_NAME bsq)

set(TARGET_CFLAGS
        -g
        -Wall -Wextra -Werror)

set(TARGET_LINK_FLAGS -w -W)

# Create an executable

file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.c")

add_executable(${TARGET_NAME} ${HEADERS} ${SOURCES})
target_compile_options(${TARGET_NAME} PRIVATE ${TARGET_CFLAGS})
target_link_options(${TARGET_NAME} PRIVATE ${TARGET_LINK_FLAGS})
