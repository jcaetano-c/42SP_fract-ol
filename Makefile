# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 14:32:11 by jcaetano          #+#    #+#              #
#    Updated: 2022/01/04 13:56:25 by jcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

SRC				=	./src
SRCS			=	main.c					\
					ft_clear_memory.c		\
					ft_create_image.c		\
					ft_create_window.c		\
					ft_encode_trgb.c		\
					ft_get_color.c			\
					ft_handle_keypress.c	\
					ft_img_pixel_put.c		\
					ft_init.c				\
					ft_init_complex.c		\
					ft_init_mlx.c			\
					ft_init_pointers.c		\
					ft_mandelbrot.c			\
					ft_julia.c				\
					ft_render.c				\
					ft_set_defaults.c		\
					ft_write_message.c		\
					ft_write_error.c		\
					ft_zoom.c

OBJ				=	./bin
OBJS			=	$(addprefix $(OBJ)/,$(SRCS:.c=.o))

INC_DIR			=	./includes

SYS_CAL			=	-lmlx -Ilmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR		=	./libft

LIBFT_LIB			=	ft

FT_CAL			=	-L $(LIBFT_DIR) -l $(LIBFT_LIB)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -O3 -g

LIBS			=	$(FT_CAL) $(SYS_CAL)

INCS			=	-I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)

SAN				=	-g3 -fsanitize=address

RM				=	rm -rf

DIR_GUARD		=	mkdir -p $(@D)

$(OBJ)/%.o:	$(SRC)/%.c
				$(DIR_GUARD)
				$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				make all -C $(LIBFT_DIR)
				$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

all:			$(NAME)

bonus:			$(NAME)

fsan:			$(OBJS)
				make all -C $(LIBFT_DIR)
				$(CC) $(SAN) $(CFLAGS) $(OBJS) $(LIBS) $(INCS) -o $(NAME)

clean:
				$(RM) $(OBJ)
				make $@ -C $(LIBFT_DIR)

fclean: 		clean
				$(RM) $(NAME)
				make $@ -C $(LIBFT_DIR)

re:				fclean all

m:
				make
				reset
				./fractol mandelbrot

j:
				make
				reset
				./fractol julia

val:			all
				reset
				valgrind ./fractol mandelbrot --leak-check=full

.PHONY:			all bonus fsan clean fclean re m j
