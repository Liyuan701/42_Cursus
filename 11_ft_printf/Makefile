# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifan <lifan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 14:01:11 by lifan             #+#    #+#              #
#    Updated: 2023/12/02 15:28:29 by lifan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c print_char.c print_nb.c 
OBJS = ${SRCS:.c=.o}
CC = cc
FLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
APPEND = ar q

%.o	:	%.c
		${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJS}
		${AR} ${NAME} ${OBJS}

all :		${NAME}

clean	:
		${RM} ${OBJS}

fclean	:	clean
		${RM} ${NAME}

re	:	fclean all

.PHONY	:	clean fclean all re
