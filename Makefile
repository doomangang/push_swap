NAME			= push_swap

SRCS 			= src/main.c\
				src/stack.c\
				src/libtool.c\
				src/stack_util.c\
				src/command.c\
				src/command_base.c\
				src/push_swap.c

SRCS_B			= bonus/main_bonus.c\
				bonus/check_bonus.c\
				bonus/util_bonus.c\
				bonus/command_bonus.c\
				bonus/stack_bonus.c\
				bonus/stack_util_bonus.c

OBJS 			= $(SRCS:.c=.o)
OBJS_B			= $(SRCS_B:.c=.o)

HEADER			= $(HEADER_DIR)push_swap.h
HEADER_B		= $(HEADER_DIR)push_swap_bonus.h
HEADER_DIR		= header/

LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_DIR		= libft/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
FT_LINK			= -lft -L$(LIBFT_DIR)
INCLUDES		= -I$(HEADER_DIR) -I$(LIBFT_DIR)

RM				= rm -f

ifdef WITH_BONUS
	OBJ_SWITCH	= ${OBJS_B}
	H_SWITCH	= $(HEADER_B)
	NAME		= checker
else
	OBJ_SWITCH	= ${OBJS}
	H_SWITCH	= $(HEADER)
endif

all: $(NAME)

bonus:
	@${MAKE} WITH_BONUS=1 all

%.o: %.c $(H_SWITCH)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJ_SWITCH)
	@$(CC) $(CFLAGS) $(FT_LINK) $(INCLUDES) $(OBJ_SWITCH) -o $(NAME)
	@echo "$(NAME): object file and $(NAME) created"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(NAME): $(LIBFT) created"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(OBJS_B)
	@echo "$(NAME): objects deleted"

fclean: clean
	@$(RM) $(LIBFT)
	@$(RM) $(NAME) checker
	@echo "$(NAME): $(NAME), checker, $(LIBFT) deleted"

re: fclean all

.PHONY : all clean fclean re bonus