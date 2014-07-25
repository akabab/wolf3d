# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 12:03:20 by ycribier          #+#    #+#              #
#    Updated: 2014/01/19 19:47:08 by ycribier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	wolf3d
NAME_MINILIBX	=	mlx
LIB				=	libft/libft.a
LIB_PATH		=	libft/
INCLUDES		=	./includes
DIR_LIBS		=	/usr/X11/lib
LDFLAGS			=	-L$(DIR_LIBS) -lXext -lX11 -lmlx
FLAGS			=	-Wall -Wextra -Werror
SRCS			=	wolf.c			\
					draw.c			\
					draw_line.c		\
					keys.c			\
					move.c			\
					map.c			\
					mmap.c			\
					collide.c		\
					dbg.c
OBJS			=	$(SRCS:.c=.o)

# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LDFLAGS) -L $(LIB_PATH) -lft
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c $(INCLUDES)/wolf.h
	@$(CC) $(FLAGS) -c -o $@ $< -I $(LIB_PATH)$(INCLUDES) -I $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean
