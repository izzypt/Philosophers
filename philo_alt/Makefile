# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: simao <simao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 19:06:43 by ncolomer          #+#    #+#              #
#    Updated: 2023/06/02 17:23:55 by simao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philosophers

SRCS			= main.c utils.c exit.c messages.c init.c forks.c eat.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
LIBS			= -lpthread

all:			$(NAME)

$(NAME):		$(SRCS)
				cc ${SRCS} ${LIBS} ${CFLAGS} -o ${NAME} 

clean:
				$(RM) $(NAME)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
