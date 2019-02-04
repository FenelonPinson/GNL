# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fepinson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 18:43:04 by fepinson          #+#    #+#              #
#    Updated: 2019/02/04 16:51:29 by fepinson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	$(realpath .)/src

INC_DIR		=	$(realpath .)

NAME		=	libft.a

CC			=	clang

SRCS		=	memdup			\
				bzero			\
				itoa			\
				memalloc		\
				memcpy			\
				memdel			\
				memset			\
				putchar			\
				putchar_fd		\
				putendl			\
				putendl_fd		\
				putnbr			\
				putnbr_fd		\
				putstr			\
				putstr_fd		\
				strchr			\
				strclr			\
				strdel			\
				strequ			\
				striter			\
				striteri		\
				strjoin			\
				strlen			\
				strmap			\
				strmapi			\
				strnequ			\
				strnew			\
				strrchr			\
				strsplit		\
				strsub			\
				strtrim			\
				strdup			\
				strlcat			\
				strcpy			\
				strncmp			\
				tolower			\
				toupper			\
				strncat			\
				strncpy			\
				strstr			\
				strnstr			\
				strdup			\
				strndup			\
				isascii			\
				isalpha			\
				isdigit			\
				atoi			\
				strcmp			\
				strnstr			\
				strcat			\
				memccpy			\
				memchr			\
				memmove			\
				memcmp			\
				isalnum			\
				lstadd			\
				lstdel			\
				lstdelone		\
				lstiter			\
				lstmap			\
				lstnew			\
				isprint			\
				atoi_base		\
				atoi_cbase		\
				putnbr_base		\
				str_isalpha		\
				dyncat			\
				str_isalnum		\
				str_isdigit		\
				revstr			\
				swap			\
				xorswap			\
				freetab			\
				strssplit		\
				itoa_base		\
				itoa_cbase		\
				get_next_line

SRCS 		:=	$(addprefix $(SRC_DIR)/ft_, $(SRCS))

SRCS		:=	$(addsuffix .c, $(SRCS))

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -g3

CPPFLAGS	=	-I$(INC_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				@ ar -rcs $(NAME) $(OBJS)

clean:
				@ $(RM) $(OBJS)

fclean:			clean
				@ $(RM) $(NAME)

re:				fclean
				 $(MAKE)

.PHONY:			all clean fclean re
