# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/24 08:21:08 by kkamashi          #+#    #+#              #
#    Updated: 2020/10/27 00:27:33 by kkamashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_isascii.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_isalnum.c \
		ft_toupper.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS =	ft_lstnew.c \
				ft_lstlast.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = -I
AR = ar
AR_OPITON = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AR_OPITON) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(AR_OPITON) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
