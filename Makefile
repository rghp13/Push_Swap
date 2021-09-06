# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 03:44:54 by romain            #+#    #+#              #
#    Updated: 2021/09/06 16:53:28 by rponsonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_SRC		=	srcs/

DIR_HEAD	=	includes/

DIR_LIB		=	libft/

DIR_OBJ		=	obj/

SRCS		=	${DIR_SRC}ft_error.c ${DIR_SRC}ft_parse.c ${DIR_SRC}ft_push_swap.c

OBJS		=	${SRCS:.c=.o}

NAME		=	pushswap.a
LIBFT_A		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
				@${CC} ${CFLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				@make -C ${DIR_LIB}
				@echo Copying ${LIBFT_A} to root
				cp ${DIR_LIB}${LIBFT_A} ${NAME}
				@echo Merging libft archive with pushswap
				ar -rcs ${NAME} ${OBJS}
all:			${NAME}

bonus:			${NAME}

test:
				@echo Compiling Testing Program
				@make -C ${DIR_LIB}
				@cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
				@cp ${DIR_HEAD}pushswap.h pushswap.h
				@cp ${DIR_HEAD}libft.h libft.h
				@cp ${DIR_HEAD}pushswap.h ${DIR_SRC}pushswap.h
				@cp ${DIR_HEAD}libft.h ${DIR_SRC}libft.h
				gcc -g -I${DIR_HEAD} main.c ${SRCS} ${LIBFT_A}
				@rm -f pushswap.h libft.h ${DIR_SRC}pushswap.h ${DIR_SRC}libft.h

clean:
				${RM} ${OBJS}
				@make clean -C ${DIR_LIB}
				@echo Clean Completed
fclean:			clean
				${RM} ${NAME}
				${RM} ${LIBFT_A}
				${RM} ${DIR_HEAD}*.gch
				@make fclean -C ${DIR_LIB}
				@echo FCLEAN complete
re:				fclean ${NAME}
				@echo Recompilation Complete
.PHONY:			all clean fclean re test bonus