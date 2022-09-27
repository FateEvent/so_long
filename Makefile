# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 11:47:12 by faventur          #+#    #+#              #
#    Updated: 2022/09/27 12:02:33 by faventur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c window.c image.c hooks.c maps.c utils.c display_image.c \
	pixies.c moves.c tools.c check.c colours.c colour_conversions.c \
	display.c

OBJS	= $(addprefix srcs/, ${SRCS:.c=.o})

FLAGS = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

RM =	rm -f

NAME = so_long

NONE = \033[0m
HIGREEN = \033[92m
HIBLUE = \033[94m
CURSIVE = \033[3m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC ./libft
	@mv ./libft/libft.a .
	@$(MAKE) -sC ./MLX
#	@mv ./libft/libft.a .
	@gcc $(FLAGS) $(OBJS) $(LINKS) libft.a -o $(NAME)
	@echo "$(CURSIVE)$(HIBLUE)Parce qu'ouvrir une fenêtre,$(NONE)"
	@echo "$(CURSIVE)$(HIGREEN)c'est surfait.$(NONE)"

.c.o:
	gcc -Wall -Wextra -Werror -c -I./includes -I./libft/includes $< -o ${<:.c=.o}

exe: all
	@./$(NAME)

clean:
	@$(RM) libft.a $(OBJS)
	@$(MAKE) clean -C ./libft
#	@$(RM) libft.a $(OBJS)
#	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all
