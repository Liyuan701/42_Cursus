# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 21:28:38 by lifan             #+#    #+#              #
#    Updated: 2024/12/30 20:32:36 by lifan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################     COMPILATION ########################################

CC = gcc
CFLAG = -Wall -Wextra -Werror -lpthread -g
NAME = philo

#######################     COMMANDES   ########################################

RM = rm -f
FILE = main.c monitor.c routine.c utils.c control.c
SRCP = code
INCP = include

SRCS = ${addprefix $(SRCP)/, $(FILE)}
OBJS = ${SRCS:.c=.o}

#######################  LIBS AND ATHS    #######################################

INCLUDE = -I${INCP}

#######################     Messages    ########################################

WELL = 		echo -e "${BLUE}|￣￣￣￣￣￣￣|"&&\
		 	echo -e "${BLUE}|   Okay!     |"&&\
 			echo -e "${BLUE}|   make...   |"&&\
 			echo -e "${BLUE}|   DONE !    |"&&\
 			echo -e "${BLUE}|_____________|"&&\
 			echo -e "${BLUE}(\__/) ||"&&\
 			echo -e "${BLUE}(•ㅅ•) ||"&&\
 			echo -e "${BLUE}/ 　 づ"\


FAIL = 		echo -e "${YELLOW}|￣￣￣￣￣￣￣|"&&\
 			echo -e "${YELLOW}|  Nope...    |"&&\
 			echo -e "${YELLOW}|  Something  |"&&\
 			echo -e "${YELLOW}|  went wrong.|"&&\
 			echo -e "${YELLOW}|_____________|"&&\
 			echo -e "${YELLOW}(\__/) ||"&&\
 			echo -e "${YELLOW}(•ㅅ•) ||"&&\
 			echo -e "${YELLOW}/ 　 づ"\

BLUE = \033[94m
YELLOW = = \033[93m

#######################     RULES       ########################################

all:		${NAME}
			@if [ $$? -eq 0 ]; then \
				${WELL}; \
			else \
				${FAIL}; \
			fi

%.o:		%.c
			@${CC} ${CFLAG} ${INCLUDE} -c $< -o $@

${NAME}:	${OBJS}
			@$(CC) $(CFLAG) $(OBJS) ${INCLUDE} -o ${NAME}

clean:
		@${RM} ${OBJS}
		@echo -e "${BLUE}Clean done, objs cleaned\n"

fclean:	clean
		@${RM} ${NAME}
		@echo -e "${BLUE}Fclean done, all cleaned.\n"

norm:
		norminette code

re:	fclean all

.PHONY:	clean fclean all re norm
