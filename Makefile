NAME			= push_swap

SRCS 			= src/main.c\
				src/stack.c\
				src/libtool.c\
				src/stack_util.c\
				src/command.c\
				src/command_base.c\
				src/push_swap.c
				
OBJS 			= $(SRCS:.c=.o)

HEADER			= $(HEADER_DIR)push_swap.h
HEADER_DIR		= header/

LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_DIR		= libft/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
FT_LINK			= -lft -L$(LIBFT_DIR)
INCLUDES		= -I$(HEADER_DIR) -I$(LIBFT_DIR)

RM				= rm -f

all: $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(FT_LINK) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(NAME): object file and $(NAME) created"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(NAME): $(LIBFT) created"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(RM) $(OBJS)
	@echo "$(NAME): objects deleted"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME)
	@echo "$(NAME): $(NAME), $(LIBFT) deleted"

re: fclean all

.PHONY : all clean fclean re