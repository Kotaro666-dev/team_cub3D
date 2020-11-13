
SRCS = ${shell find ./draw_utils/ -type f -name "*.c"}
SRCS += ${shell find ./render/ -type f -name "*.c"}
SRCS += ${shell find ./hook/ -type f -name "*.c"}
SRCS += ${shell find ./cast_ray/ -type f -name "*.c"}
SRCS += start_game.c
SRCS += testmain.c

INCLUDE = definition.h
OBJS = ${SRCS:%.c=%.o}
LIBMLX = ./../../libmlx.a
CC = gcc
CFLAGS = -lm -lXext -lX11
CFLAGS += -Wall -Wextra -Werror
SANITIZE = -g -fsanitize=address,undefined
NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	${CC} -o ${NAME} -I ${INCLUDE} ${OBJS} ${LIBMLX} ${CFLAGS} ${SANITIZE}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ./cub3D

run:
	./${NAME}

.PHONY: all clean fclean run