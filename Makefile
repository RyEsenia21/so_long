NAME = so_long

SRCS = so_long.c get_next_line.c get_next_line_utils.c check_chars.c chek_map.c hook.c init_map.c liba.c move_msg.c moves.c print_error.c

INCLUDE = so_long.h

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) libmlx.dylib -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re all