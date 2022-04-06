SRCS = main.c window.c image.c color.c hooks.c maps.c utils.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

LINKS = -lmlx -framework OpenGL -framework AppKit

RM =	rm -f

NAME = so_long

NONE = '\033[0m'
PINK = '\033[1;35m'
RED	 = '\033[1;31m'
YELLOW = '\033[1;33m'
GREEN =	'\033[32m'
GRAY = '\033[2;37m'
CURSIVE = '\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./libft
	@mv ./libft/libft.a .
	@gcc $(FLAGS) $(OBJS) $(LINKS) libft.a -o $(NAME)
	@echo $(RED)Missi$(NONE)on accomp$(GREEN)lished!$(NONE);
	@rm $(OBJS)

$(OBJS): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

exe: all
	@./$(NAME)

clean:
	@$(RM) $(OBJS) libft.a
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all
