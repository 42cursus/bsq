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

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_COMPILER gcc-13)

project("bsq" VERSION 0.1.0 LANGUAGES C ASM)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_REQUIRED_LIBRARIES "-lbsd")

#==============================================================================#
# SQ lib
#==============================================================================#

set(SQ_LIB_NAME sq)
set(SQ_LIB_FILENAME libsq.a)
set(SQ_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/sq")
set(SQ_LIB_PATH "${SQ_LIB_DIR}/${SQ_LIB_FILENAME}")
set(MLX_BUILD_DIR "${CMAKE_BINARY_DIR}/sq_build")

file(GLOB_RECURSE SQ_LIB_HEADERS "${SQ_LIB_DIR}/*.h")
file(GLOB_RECURSE SQ_LIB_SOURCES "${SQ_LIB_DIR}/*.c")

# Custom target to build and patch MLX
add_custom_target(${SQ_LIB_NAME}_target ALL
		COMMAND make -C ${SQ_LIB_DIR}
		BYPRODUCTS "${SQ_LIB_DIR}/${SQ_LIB_FILENAME}"
		SOURCES "${SQ_LIB_HEADERS};${SQ_LIB_SOURCES}"
		COMMENT "Building SQ_LIB")

add_library(${SQ_LIB_NAME} STATIC IMPORTED)
add_dependencies(${SQ_LIB_NAME} "${SQ_LIB_NAME}_target")
set_target_properties(${SQ_LIB_NAME} PROPERTIES
		IMPORTED_LOCATION "${SQ_LIB_DIR}/${SQ_LIB_FILENAME}" # Make sure to use absolute path here
		INTERFACE_COMPILE_DEFINITIONS ""
		INTERFACE_SOURCES "${SQ_LIB_HEADERS}"
		INTERFACE_INCLUDE_DIRECTORIES "${SQ_LIB_DIR}")

#==============================================================================#
# FT lib
#==============================================================================#

set(FT_LIB_NAME ft)
set(FT_LIB_FILENAME libft.a)
set(FT_LIB_DIR "${PROJECT_SOURCE_DIR}/lib/ft")

file(GLOB_RECURSE FT_LIB_HEADERS "${FT_LIB_DIR}/*.h")
file(GLOB_RECURSE FT_LIB_SOURCES "${FT_LIB_DIR}/*.c")

add_custom_target(${FT_LIB_NAME}_target ALL
		COMMAND make -C ${FT_LIB_DIR} BUILD_WITH_ASAN=1
		BYPRODUCTS "${FT_LIB_DIR}/${FT_LIB_FILENAME}"
		SOURCES "${FT_LIB_HEADERS};${FT_LIB_SOURCES}"
		COMMENT "Building FT_LIB")

add_library(${FT_LIB_NAME} STATIC IMPORTED)

add_dependencies(${FT_LIB_NAME} "${FT_LIB_NAME}_target")
set_target_properties(${FT_LIB_NAME} PROPERTIES
		IMPORTED_LOCATION ${FT_LIB_DIR}/${FT_LIB_FILENAME}
		INTERFACE_COMPILE_DEFINITIONS ""
		INTERFACE_LINK_OPTIONS ""
		INTERFACE_SOURCES "${FT_LIB_HEADERS}"
		INTERFACE_INCLUDE_DIRECTORIES "${FT_LIB_DIR};${FT_LIB_DIR}/include")

#==============================================================================#

set(TARGET_NAME "${PROJECT_NAME}_exe")

set(TARGET_CFLAGS
		-g3 -O0
		-Wall -Wextra -Werror -Wwrite-strings
		-Wformat
		-Werror=format-security
		-fsanitize-address-use-after-scope
		-fsanitize=address,undefined,bounds,alignment,object-size
		-fsanitize=shift,signed-integer-overflow,null,return
		-fsanitize=float-divide-by-zero,float-cast-overflow
		-fno-sanitize-recover=all
)

set(TARGET_LINK_FLAGS
		-w -W
		-fsanitize-address-use-after-scope
		-fsanitize=address,undefined,bounds,alignment,object-size
		-fsanitize=shift,signed-integer-overflow,null,return
		-fsanitize=float-divide-by-zero,float-cast-overflow
		-fno-sanitize-recover=all
)

set(TARGET_LIBRARIES
		${SQ_LIB_NAME}
		${FT_LIB_NAME}
)

# Create an executable
file(GLOB HEADERS "include/*.h")
file(GLOB SOURCES "src/*.c")

add_executable(${TARGET_NAME} ${HEADERS} ${SOURCES})
target_compile_options(${TARGET_NAME} PRIVATE ${TARGET_CFLAGS})
target_link_options(${TARGET_NAME} PRIVATE ${TARGET_LINK_FLAGS})
target_link_libraries(${TARGET_NAME} PRIVATE "${TARGET_LIBRARIES}")
target_link_directories(${TARGET_NAME} PUBLIC "${FT_LIB_DIR}" "${SQ_LIB_DIR}")
target_include_directories(${TARGET_NAME} PRIVATE
		${PROJECT_SOURCE_DIR}
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/lib/sq/include
		/usr/include
		/usr/include/x86_64-linux-gnu)

set_target_properties(${TARGET_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}"
		OUTPUT_NAME "${PROJECT_NAME}")
