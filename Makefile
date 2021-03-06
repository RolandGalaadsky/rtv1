NAME = rtv1

# src / obj files
SRCS =  main.c \
		draw.c \
		errors.c \
		hooks.c \
		get_data/ft_atod.c \
		get_data/get_arr.c \
		get_data/init_lights.c \
		get_data/init_objects.c \
		get_data/set_objects.c \
		get_data/init_scene.c \
		get_data/init_cam.c \
		math_fun/scalars_vector_fun.c \
		math_fun/vectors_op.c \
		math_fun/del_matrix.c \
		objects_props/intersects.c \
		objects_props/normals.c \
		objects_props/cone_normal.c \
		trace_ray/compute_color.c \
		trace_ray/compute_light.c \
		trace_ray/find_t.c \
		trace_ray/trace_ray.c \
		math_fun/matrix_op.c \
		math_fun/rotate_fun.c \
		math_fun/field_op.c
		
OBJ = $(SRCS:%.c=%.o)

CC = clang

HDEP = includes/rtv1.h 

LIBS = -L libft/ -lft -lXext -lX11 -L libmlx/ -lmlx_Linux -lm

INCLUDES = -I libft/includes -I includes -I libmlx

FLAGS = -Wall -Wextra -Werror -O3 $(INCLUDES)

%.o: %.c $(HDEP)
	$(CC) -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libmlx
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	@make -C libft/ clean
	@make -C libmlx/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@make -C libmlx/ clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
