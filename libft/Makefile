# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoumare <asoumare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 19:11:13 by asoumare          #+#    #+#              #
#    Updated: 2024/09/23 19:47:58 by asoumare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		get_next_line.c get_next_line_utils.c

ADDITIONAL =	ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c ft_striteri.c

BONUS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
		
SRCS = ${LIBC} ${ADDITIONAL}

SRCSALL = ${LIBC} ${ADDITIONAL} ${BONUS}

OBJS = ${SRCS:.c=.o}

OBJSALL = ${SRCSALL:.c=.o}

LIB = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra 

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

bonus:	${OBJSALL}
		ar -rsc ${LIB} ${OBJSALL}

all: 	${LIB}

clean:	
		rm -f ${OBJSALL}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re