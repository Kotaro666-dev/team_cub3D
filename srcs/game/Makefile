
SRCS = ${shell find ./draw_utils/ -type f -name "*.c"}
SRCS += ${shell find ./render/ -type f -name "*.c"}
SRCS += ${shell find ./hook/ -type f -name "*.c"}
SRCS += testmain.c

INCLUDE = definition.h
OBJS = ${SRCS:%.c=%.o}
LIBMLX = ./libmlx.a
CC = gcc
CFLAGS = -g -fsanitize=address,undefined -lm -lXext -lX11
NAME = cub3D

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	${CC} -o ${NAME} -I ${INCLUDE} ${OBJS} ${LIBMLX} ${CFLAGS}

run:
	./${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ./cub3D


.PHONY: all clean run