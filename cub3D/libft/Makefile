# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efaustin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 20:52:49 by efaustin          #+#    #+#              #
#    Updated: 2024/05/20 20:52:51 by efaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC	= 	ft_atoi.c		\
		ft_bzero.c			\
		ft_calloc.c 		\
		ft_isdigit.c		\
		ft_memset.c 		\
		ft_split.c			\
		ft_strchr.c 		\
		ft_strdup.c 		\
		ft_strjoin.c		\
		ft_strlcpy.c 		\
		ft_strlen.c 		\
		ft_strncmp.c 		\
		ft_strrchr.c		\
		ft_strtrim.c 		\
		ft_substr.c 		\
		gnl_clean.c		\
		get_next_line.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

