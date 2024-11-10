# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifan <rohanafan@sina.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 21:28:38 by lifan             #+#    #+#              #
#    Updated: 2024/11/06 18:20:52 by lifan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################     COMPILATION ########################################

CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = push_swap

#######################     COMMANDES   ########################################

RM = rm -f
VAL = valgrind --leak-check=full --track-origins=yes
ARG = "1 4 005 7 02 0 -00002147483649"

FILE = clean.c initial.c main.c op_ps.c\
op_rr.c sort_larg.c sort_small.c calcul.c\
operations.c check.c get.c utils.c
SRCP = code
LIBP = libft
INCP = include

SRCS = ${addprefix $(SRCP)/, $(FILE)}
OBJS = ${SRCS:.c=.o}
LIBFT = ${LIBP}/libft.a

#######################  LIBS AND ATHS    #######################################

INCLUDE = -I${INCP} -I${LIBP}
LIBS = -L${LIBP} -lft

#######################     Messages    ########################################

WELL = 		echo "${BLUE}|￣￣￣￣￣￣￣|"&&\
		 	echo "${BLUE}|   Okay!     |"&&\
 			echo "${BLUE}|   make...   |"&&\
 			echo "${BLUE}|   DONE !    |"&&\
 			echo "${BLUE}|_____________|"&&\
 			echo "${BLUE}(\__/) ||"&&\
 			echo "${BLUE}(•ㅅ•) ||"&&\
 			echo "${BLUE}/ 　 づ"\


FAIL = 		echo "${YELLOW}|￣￣￣￣￣￣￣|"&&\
 			echo "${YELLOW}|  Nope...    |"&&\
 			echo "${YELLOW}|  Something  |"&&\
 			echo "${YELLOW}|  went wrong.|"&&\
 			echo "${YELLOW}|_____________|"&&\
 			echo "${YELLOW}(\__/) ||"&&\
 			echo "${YELLOW}(•ㅅ•) ||"&&\
 			echo "${YELLOW}/ 　 づ"\

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

${NAME}:	$(LIBFT) ${OBJS}
			@$(CC) $(CFLAG) $(OBJS) ${LIBS} ${INCLUDE} -o ${NAME}

${LIBFT}:
			@make all -C ${LIBP} -s

clean:
		@${RM} ${OBJS} ${BONJS}
		@make clean -C ${LIBP} -s
		@echo "Clean done, objs cleaned\n"

fclean:	clean
		@${RM} ${NAME} ${BONUS}
		@make fclean -C ${LIBP} -s
		@echo "Fclean done, all cleaned.\n"

checkleak:	${NAME}
		${VAL} ./${NAME} ${ARG}

42check:	${NAME}
		./${NAME} ${ARG} | ./checker_linux ${ARG}

norm:
		norminette code

re:	fclean all

.PHONY:	clean fclean all re checkleak norm 42check
