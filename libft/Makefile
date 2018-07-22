# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 21:32:47 by mbortnic          #+#    #+#              #
#    Updated: 2018/06/05 21:32:48 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I -c

SRCS = $(patsubst %.c,%.o,$(wildcard *.c)) \
		$(patsubst %.c,%.o,$(wildcard ft_printf/*.c))

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	@ ar -cru $(NAME) $(SRCS)
	@ ranlib $(NAME)
	@ echo "\033[32;1m$(NAME) is ready\033[0m"

%.o: %.c
	@ gcc $(CFLAGS) -o $@ -c $<

clean:
	@ $(RM) $(OBJ)
	@ $(RM) ft_printf/*.o
	@ echo "\033[33mlibft obj files are removed\033[0m"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "\033[31;m$(NAME) is deleted\033[0m"

re: fclean all
	@ echo "\033[36;1mre performed\033[0m"

.PHONY: all clean fclean re
