SRCS = main.c window.c image.c color.c hooks.c maps.c utils.c

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
	@gcc $(FLAGS) $(OBJS) $(LINKS) libft.a -o $(NAME)
	@echo "$(CURSIVE)$(HIBLUE)Parce qu'ouvrir une fenêtre,$(NONE)"
	@echo "$(CURSIVE)$(HIGREEN)c'est surfait.$(NONE)"
	@rm $(OBJS)

exe: all
	@./$(NAME)

clean:
	@$(RM) libft.a $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all
