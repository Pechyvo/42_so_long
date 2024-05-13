NAME = so_long

SRCSDIR			= srcs/
HDRDIR			= incl/
PRINTFDIR		= ft_printf/
MLX_DIR 		= minilibx-linux/

SRCS			= ${shell find ${SRCSDIR} -maxdepth 1 -type f -name '*.c'}
OBJS			= $(SRCS:.c=.o)

PRINTF			= ${PRINTFDIR}libftprintf.a
MLX 			= ${MLX_DIR}libmlx.a

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
MLX_FLAGS 		= -L/usr/X11/lib -lX11 -lXext -lm


all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(PRINTF) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(SRCS) $(PRINTF) $(MLX)

$(PRINTF):
	make -C $(PRINTFDIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	make fclean -C $(PRINTFDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re

# find . -name "*.c" -not -path "./minilibx-linux/*" -exec norminette {} +
# valgrind --tool=memcheck
# valgrind --leak-check=full
# -lmlx -framework OpenGL -framework AppKit
# -fsanitize=address -g
# -L/usr/X11/lib -lX11 -lXext -lm