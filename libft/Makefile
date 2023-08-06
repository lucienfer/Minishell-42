# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luciefer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 13:15:21 by luciefer          #+#    #+#              #
#    Updated: 2022/11/16 11:28:24 by luciefer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_atoi.c	\
	ft_bzero.c		\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_isprint.c	\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_memmove.c	\
	ft_memcpy.c		\
	ft_memset.c		\
	ft_strchr.c		\
	ft_strdup.c		\
	ft_strlen.c		\
	ft_strlcat.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strlcpy.c	\
	ft_strncmp.c	\
	ft_tolower.c	\
	ft_toupper.c	\
	ft_strjoin.c	\
	ft_substr.c		\
	ft_strtrim.c	\
	ft_split.c		\
	ft_itoa.c		\
	ft_putchar_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putstr_fd.c	\
	ft_strmapi.c	\
	ft_calloc.c		\
	ft_striteri.c	\
	ft_strcmp.c		\

SRC_BONUS =	ft_lstnew_bonus.c	\
	ft_lstadd_front_bonus.c		\
	ft_lstsize_bonus.c			\
	ft_lstlast_bonus.c			\
	ft_lstadd_back_bonus.c		\
	ft_lstdelone_bonus.c		\
	ft_lstclear_bonus.c			\
	ft_lstiter_bonus.c			\
	ft_lstmap_bonus.c			\


OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

NAME = libft.a

CFLAGS =	-Werror -Wextra -Wall

all :	$(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ) 
		ranlib $(NAME)

clean :
		rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -f $(NAME)

re : fclean $(NAME)

bonus : $(OBJ) $(OBJ_BONUS)
		ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
		ranlib $(NAME)

.PHONY: all clean fclean re
