
SRCS = ${shell find ./draw_utils/ -type f -name "*.c"}
SRCS += ${shell find ./render/ -type f -name "*.c"}
SRCS += ${shell find ./hook/ -type f -name "*.c"}
SRCS += ${shell find ./cast_ray/ -type f -name "*.c"}
SRCS += start_game.c
SRCS += testmain.c

INCLUDE = -I./../../includes/ \
			-I./../../libs/get_next_line/ \
			-I./../../libs/libft/ \
			-I./../../includes/structs/ \
			-I./../../minilibx-linux/

OBJS = ${SRCS:%.c=%.o}
LIBMLX = ./../../libmlx.a
CC = gcc
CFLAGS = -lm -lXext -lX11
CFLAGS += -Wall -Wextra -Werror
SANITIZE = -g -fsanitize=address,undefined
NAME = cub3D

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	${CC} -o ${NAME} ${INCLUDE} ${OBJS} ${LIBMLX} ${CFLAGS} ${SANITIZE}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ./cub3D

run:
	./${NAME}

.PHONY: all clean fclean run
