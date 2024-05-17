NAME = so_long
HDRDIR			= incl/
SRCSDIR			= srcs/
SRCS			= ${SRCSDIR}main.c \
				  ${SRCSDIR}ft_game.c \
				  ${SRCSDIR}ft_map.c \
				  ${SRCSDIR}ft_map_check.c \
				  ${SRCSDIR}ft_pathfinder.c \
				  ${SRCSDIR}ft_hooks.c \
				  ${SRCSDIR}ft_utils.c
OBJS			= $(SRCS:.c=.o)

PRINTFDIR		= ft_printf/
PRINTF			= ${PRINTFDIR}libftprintf.a

MLX_DIR 		= minilibx-linux/
MLX 			= ${MLX_DIR}libmlx.a

CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror -I$(HDRDIR) -g
MLX_FLAGS 		= -L/usr/X11/lib -lX11 -lXext -lm


all: $(NAME)
$(NAME): $(OBJS) $(MLX) $(PRINTF) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(SRCS) $(PRINTF) $(MLX)

$(PRINTF):
	make -C $(PRINTFDIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	make fclean -C $(PRINTFDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re