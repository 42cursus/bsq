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

set(TARGET_LINK_FLAGS -w -Wl)

# Create an executable suitable for Arduino using CMake-style target-creation
set(HEADERS
        "")
set(SOURCES
        "")
file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.c")

add_executable(${TARGET_NAME} ${HEADERS} ${SOURCES})
target_compile_options(${TARGET_NAME} PRIVATE ${TARGET_CFLAGS})
target_link_options(${TARGET_NAME} PRIVATE ${TARGET_LINK_FLAGS})
