# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 18:59:38 by asoumare          #+#    #+#              #
#    Updated: 2025/04/08 17:02:26 by asoumare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -g3 -Wall -Wextra -Werror

# Paths
SRC_PATH = src/
OBJ_PATH = obj/
MLX_PATH = minilibx-linux/
LIBFT_PATH = libft/

# Libraries and flags
MLX     = ${MLX_PATH}libmlx.a
LFLAGS  = -L${MLX_PATH} -lmlx -lXext -lX11
IFLAGS  = -I${MLX_PATH}
LIBFT = $(LIBFT_PATH)libft.a

# Source and object files
SRC     = main.c \
          actu_map.c \
          check_map.c \
          check_map_utils.c \
          check_obj.c \
          draw_img.c \
          init_map.c \
          key.c \
          make_map.c \
          mouv.c \
          utils.c

SRCS    = ${addprefix ${SRC_PATH}, ${SRC}}
OBJS    = ${addprefix ${OBJ_PATH}, ${SRC:.c=.o}}

# Output
NAME    = so_long

# Rules
all: ${OBJ_PATH} ${LIBFT} ${NAME}

${OBJ_PATH}:
	mkdir -p ${OBJ_PATH}

${OBJ_PATH}%.o: ${SRC_PATH}%.c
	${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${MAKE} -C ${MLX_PATH}
	${CC} ${OBJS} ${MLX} ${LIBFT} ${LFLAGS} -o ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFT_PATH}

clean:
	${RM} ${OBJS}
	${MAKE} -C ${LIBFT_PATH} ${OBJ_PATH} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: all clean fclean re
