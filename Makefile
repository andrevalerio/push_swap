# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 22:23:02 by avalerio          #+#    #+#              #
#    Updated: 2022/04/11 00:46:15 by avalerio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	=	main.c check_input.c stack.c moves.c sort.c
SRCDIR	=	./src/
SRCS	=	$(addprefix $(SRCDIR), $(FILES))
OBJS	=	${SRCS:.c=.o}
NAME	=	push_swap
INCLUDE	=	-I includes -I libft
MODULE	=	./libft/libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address
RM		=	rm -f

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(MODULE):
	make bonus -C libft

$(NAME):	$(MODULE) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAG) $(MODULE) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean:     clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re