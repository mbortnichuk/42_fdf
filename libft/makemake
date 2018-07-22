# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 17:33:05 by mbortnic          #+#    #+#              #
#    Updated: 2017/11/20 12:02:39 by mbortnic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strclr.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strnequ.c \
	   ft_strsplit.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_numberlength.c \
	   ft_wordcount.c \
	   ft_wordlength.c \
	   ft_swap.c \
	   ft_list_size.c \
	   ft_swap_bits.c \
	   ft_sqrt.c \
	   ft_isnumber.c \
	   ft_lstaddback.c \
	   ft_create_node.c \
	   ft_strndup.c \
	   ft_isspace.c \
	   get_next_line.c

BINS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I. -c

HEADER = libft.h

all: $(NAME)

$(NAME): 
	@ gcc $(SRCS) $(CFLAGS)
	@ ar rc $(NAME) $(BINS)
	@ ranlib $(NAME)
	@ echo "\033[32;1m$(NAME) is ready\033[0m"

clean:
	@ rm -f $(BINS)
	@ echo "\033[33mlibft obj files are removed\033[0m"

fclean: clean
	@ rm -f $(NAME)
	@ echo "\033[31;m$(NAME) is deleted\033[0m"

re: fclean all
	@ echo "\033[36;1mre performed\033[0m"

.PHONY: all clean fclean re
