NAME =	cub3D

SRC =	cub.c \
		parser/parser.c parser/check_first_last_line.c parser/check_one_plr.c \
		parser/check_val_play.c parser/check_valid_simbol.c parser/ft_cat_map.c \
		parser/init_player.c parser/init_sprites.c parser/kill_spaces.c parser/pars_ceiling.c \
		parser/pars_floor.c parser/pars_parsov.c parser/pars_res.c parser/pars_textur.c parser/trim_map.c \
		raycast/ray_cast.c raycast/wall_cast.c raycast/wall_cast2.c raycast/sprite_cast.c raycast/walk_player.c \
		bmp/bitmap.c utils/utils.c utils/utils2.c utils/ft_atoi.c utils/ft_calloc.c utils/ft_isdigit.c \
		utils/ft_lstadd_back.c utils/ft_lstnew.c utils/ft_lstsize.c utils/ft_putchar_fd.c utils/ft_split.c \
		utils/ft_strchr.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c \
		utils/ft_strtrim.c utils/get_next_line.c utils/init_struct.c 

OBJ =	${SRC:.c=.o}

DEP = $(SRC:.c=.d)

CC =	gcc

CFLAGS			= -Wall -Wextra -Werror -MMD

MLX_FLAGS 		= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLXSCREENSIZE	= ./mlx/mlx_get_screen_size.m

MLX				= ./mlx/

MLXLIB 			= ./mlx/libmlx.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

-include $(DEP)

$(NAME): $(OBJ)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(MLXLIB) $(MLXSCREENSIZE) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(DEP)
	make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	rm -rf screenshot.bmp
	rm -rf *.d

re: fclean all

.PHONY: all clean fclean re
