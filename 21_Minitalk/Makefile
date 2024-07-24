# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifan <lifan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 14:01:11 by lifan             #+#    #+#              #
#    Updated: 2024/07/23 18:44:55 by lifan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################     COMPILATION ########################################

CC = cc
FLAG = -Wall -Wextra -Werror
NAME = minitalk

#######################     COMMANDES   ########################################

RM = rm -f

#######################     FILES       ########################################

S_SRCS = server.c
S_SRCSB = server_bonus.c
C_SRCS = client.c
C_SRCSB = client_bonus.c
S_OBJS = ${S_SRCS:.c=.o}
S_OBJSB = ${S_SRCSB:.c=.o}
C_OBJS = ${C_SRCS:.c=.o}
C_OBJSB = ${C_SRCSB:.c=.o}
IN = -I include
LIBA = libft.a

C_NB = client_bonus
S_NB = server_bonus
C_N = client
S_N = server
#######################     Messages    ########################################

WELL = 		echo "|￣￣￣￣￣￣￣|"&&\
		 	echo "|   Okay!     |"&&\
 			echo "|   make...   |"&&\
 			echo "|   DONE !    |"&&\
 			echo "|_____________|"&&\
 			echo "(\__/) ||"&&\
 			echo "(•ㅅ•) ||"&&\
 			echo "/ 　 づ"\


FAIL = 		echo "|￣￣￣￣￣￣￣|"&&\
 			echo "|  Nope...    |"&&\
 			echo "|  Something  |"&&\
 			echo "|  went wrong.|"&&\
 			echo "|_____________|"&&\
 			echo "(\__/) ||"&&\
 			echo "(•ㅅ•) ||"&&\
 			echo "/ 　 づ"\

#######################     RULES       ########################################

all:		${NAME}
			@if [ $$? -eq 0 ]; then \
				${WELL}; \
			else \
				${FAIL}; \
	fi

%.o:		%.c
			@${CC} ${FLAG} -c $< -o $@

${NAME}:	$(LIBA) ${S_N} ${C_N}


${LIBA}:
			@make all -C libft -s

${S_N}:		${S_OBJS}
			@$(CC) $(FLAG) $(S_OBJS) ${IN} libft/$(LIBA) -o ${S_N}

${C_N}:		${C_OBJS}
			@$(CC) $(FLAG) $(C_OBJS) ${IN} libft/$(LIBA) -o ${C_N}

${S_NB}:	${S_OBJSB}
			@$(CC) $(FLAG) $(S_OBJSB) ${IN} libft/$(LIBA) -o ${S_NB}

${C_NB}:	${C_OBJSB}
			@$(CC) $(FLAG) $(C_OBJSB) ${IN} libft/$(LIBA) -o ${C_NB}

clean:
		@${RM} ${S_OBJS} ${C_OBJS} ${S_OBJSB} ${C_OBJSB}
		@make clean -C libft -s


fclean:	clean
		@${RM} ${C_N} ${S_N} ${S_NB} ${C_NB}
		@make fclean -C libft -s

re:	fclean all

bonus : fclean $(LIBA) ${C_NB} ${S_NB}

rebonus : fclean bonus

.PHONY	:	clean fclean all re
