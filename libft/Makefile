# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 09:38:32 by jocaille          #+#    #+#              #
#    Updated: 2019/11/08 09:38:54 by jocaille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRC_NAME	=	ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isalpha.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c
SRC_NAME_B	=	ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c
OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_NAME_B	=	$(SRC_NAME_B:.c=.o)
SRC_PATH	=	.
SRC_PATH_B	=	.
OBJ_PATH	=	.
OBJ_PATH_B	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_B		=	$(addprefix $(SRC_PATH_B)/,$(SRC_NAME_B))
OBJ			=	$(addprefix	$(OBJ_PATH)/,$(OBJ_NAME))
OBJ_B		=	$(addprefix	$(OBJ_PATH_B)/,$(OBJ_NAME_B))
INC			=	libft.h
INC_B		=	libft_bonus.h
INC_PATH	=	.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INC_PATH)
RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

bonus: $(OBJ_B) $(OBJ) $(INC) $(INC_B)
	ar rc $(NAME) $(OBJ_B) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH_B)/%.o: $(SRC_PATH_B)/%.c 
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
