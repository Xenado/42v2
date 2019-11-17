# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/17 10:41:51 by jocaille          #+#    #+#              #
#    Updated: 2019/11/17 10:42:29 by jocaille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	

LIB			=	libft
SRC_NAME	=	
SRC_NAME_B	=	
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
INC			=	
INC_B		=	
INC_PATH	=	.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I$(INC_PATH)
RM			=	rm -
LDLIBS		=	-lft
LDFLAGS		=	-Llibft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

bonus: $(OBJ_B) $(OBJ) $(INC) $(INC_B)
	@$(MAKE) -C $(LIB)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) $(ONJ_B) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH_B)/%.o: $(SRC_PATH_B)/%.c 
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIB)
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re