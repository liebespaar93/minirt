# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 01:52:31 by kyoulee           #+#    #+#              #
#    Updated: 2023/02/18 06:17:08 by kyoulee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = minirt

CC = gcc 
CXXFLAGS = $(NULL)
CFLAGS = -Wall -Werror -Wextra
DFLAGS = $(NULL) -g
IFLAGS =					\
	-I $(INCLUDE_DIR)		\
	-I $(INCLUDE_MIX_DIR)	\
	-I $(MINILIBX_DIR)
LDFLAGS =						\
	-L $(MINILIBX_DIR)
LDLIBS =											\
	-lmlx -lm -framework OpenGL -framework AppKit

## MODULES ##
MINILIBX = $(MINILIBX_DIR)/libmlx.a

#####***** DIR *****#####
ROOTDIR = $(abspath $(dir $(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST))))
INCLUDE_DIR = $(ROOTDIR)/include
INCLUDE_MIX_DIR = $(ROOTDIR)/include/mlx
OBJ_DIR = $(ROOTDIR)/obj

SRC_01_MAIN_DIR = $(ROOTDIR)/src_01
SRC_02_FD_DIR = $(ROOTDIR)/src_02_fd
SRC_03_PARAM_DIR = $(ROOTDIR)/src_03_param
SRC_04_RT_DIR = $(ROOTDIR)/src_04_rt
SRC_05_SCENE_DIR = $(ROOTDIR)/src_05_scene
SRC_06_RENDER_DIR = $(ROOTDIR)/src_06_render
SRC_07_INTERSECTION_DIR = $(ROOTDIR)/src_07_intersection
SRC_08_SHADOW_DIR = $(ROOTDIR)/src_08_shadow


SRC_TOOL_DIR = $(ROOTDIR)/src_tool
SRC_VECTOR_DIR = $(ROOTDIR)/src_vector
SRC_MATRIX_DIR = $(ROOTDIR)/src_matrix
SRC_QUATERNION_DIR = $(ROOTDIR)/src_quaternion
SRC_GEOMETRIC_TRANSFORM_DIR = $(ROOTDIR)/src_geometric_transform
SRC_MLX_DIR = $(ROOTDIR)/src_mlx
SRC_MLX_KEYBOARD_DIR = $(SRC_MLX_DIR)/src_mlx_keyboard
SRC_MLX_MOUSE_DIR = $(SRC_MLX_DIR)/src_mlx_mouse
SRC_MLX_WIN_DIR = $(SRC_MLX_DIR)/src_mlx_win

## MODULES ##
MINILIBX_DIR = $(ROOTDIR)/modules/minilibx_opengl_20191021

#####***** SRC *****#####
SRC_01_MAIN_SRC =	main.c

SRC_01_MAIN_C = $(addprefix $(SRC_01_MAIN_DIR)/, $(SRC_01_MAIN_SRC))

SRC_02_FD_SRC =	ft_fd.c	\
				ft_get_next_line.c	\
				ft_read.c

SRC_02_FD_C = $(addprefix $(SRC_02_FD_DIR)/, $(SRC_02_FD_SRC))


SRC_03_PARAM_SRC =	ft_param.c 

SRC_03_PARAM_C = $(addprefix $(SRC_03_PARAM_DIR)/, $(SRC_03_PARAM_SRC))


SRC_04_RT_SRC =	ft_rt_ambient_lightning.c	\
				ft_rt_camera.c		\
				ft_rt_cylinder.c	\
				ft_rt_light.c	\
				ft_rt_plane.c	\
				ft_rt_sphere.c	\
				ft_rt_tool.c	\
				ft_rt.c	
	
SRC_04_RT_C = $(addprefix $(SRC_04_RT_DIR)/, $(SRC_04_RT_SRC))


SRC_05_SCENE_SRC =	ft_scene_camera.c	\
					ft_scene_image.c	\
					ft_scene_image_set.c\
					ft_scene_light.c	\
					ft_scene_obj.c	\
					ft_scene.c
					
SRC_05_SCENE_C = $(addprefix $(SRC_05_SCENE_DIR)/, $(SRC_05_SCENE_SRC))


SRC_06_RENDER_SRC = ft_render.c
					
SRC_06_RENDER_C = $(addprefix $(SRC_06_RENDER_DIR)/, $(SRC_06_RENDER_SRC))


SRC_07_INTERSECTION_SRC =	ft_intersection.c				\
							ft_intersection_obj.c			\
							ft_intersection_obj_plane.c		\
							ft_intersection_obj_sphere.c	\
							ft_intersection_obj_cylinder.c	\
							ft_intersection_obj_math.c		\
							ft_intersection_light.c			\
							ft_intersection_light_ambient.c	\
							ft_intersection_light_light.c	\
							ft_intersection_light_math.c
					
SRC_07_INTERSECTION_C = $(addprefix $(SRC_07_INTERSECTION_DIR)/, $(SRC_07_INTERSECTION_SRC))

SRC_08_SHADOW_SRC = ft_shadow.c
					
SRC_08_SHADOW_C = $(addprefix $(SRC_08_SHADOW_DIR)/, $(SRC_08_SHADOW_SRC))



SRC_TOOL_SRC =					\
				ft_atof.c			\
				ft_atoi.c			\
				ft_bzero.c			\
				ft_calloc.c			\
				ft_error.c			\
				ft_isdigit.c		\
				ft_is_end_space.c	\
				ft_lst_len.c		\
				ft_lst_malloc.c		\
				ft_lstadd_back.c	\
				ft_lstnew.c			\
				ft_memcmp.c			\
				ft_memcpy.c			\
				ft_memset.c			\
				ft_ptrcpy.c			\
				ft_ptrlen.c			\
				ft_split.c			\
				ft_strchr.c			\
				ft_strcmp.c			\
				ft_strdup.c			\
				ft_strlcpy.c		\
				ft_strlen.c			\
				ft_strncpy.c		\
				ft_zeromalloc.c

SRC_TOOL_C = $(addprefix $(SRC_TOOL_DIR)/, $(SRC_TOOL_SRC))


SRC_VECTOR_SRC =						\
				ft_vector_2.c			\
				ft_vector_2_operator.c	\
				ft_vector_3.c			\
				ft_vector_3_operator.c	\
				ft_vector_to.c

SRC_VECTOR_C = $(addprefix $(SRC_VECTOR_DIR)/, $(SRC_VECTOR_SRC))

SRC_MATRIX_SRC =						\
				ft_matrix_2.c			\
				ft_matrix_2_mult.c		\
				ft_matrix_3.c			\
				ft_matrix_3_mult.c		\
				ft_matrix_3_inverse.c	\
				ft_matrix_4.c			\
				ft_matrix_4_rotation.c	\
				ft_matrix_4_mult.c		\
				ft_matrix_4_inverse.c	\
				ft_matirx_to.c

SRC_MATRIX_C = $(addprefix $(SRC_MATRIX_DIR)/, $(SRC_MATRIX_SRC))


SRC_QUATERNION_SRC =	ft_quaternion.c				\
						ft_quaternion_aixs.c		\
						ft_quaternion_euler.c		\
						ft_quaternion_matrix.c		\
						ft_quaternion_operator.c	\
						ft_quaternion_roration.c

SRC_QUATERNION_C = $(addprefix $(SRC_QUATERNION_DIR)/, $(SRC_QUATERNION_SRC))


SRC_GEOMETRIC_TRANSFORM_SRC =	ft_geometric_transform.c

SRC_GEOMETRIC_TRANSFORM_C = $(addprefix $(SRC_GEOMETRIC_TRANSFORM_DIR)/, $(SRC_GEOMETRIC_TRANSFORM_SRC))


SRC_MLX_KEYBOARD_SRC =						\
				ft_mac_key_hold.c			\
				ft_mac_key_down.c			\
				ft_mac_key_up.c			\
				ft_mac_keyboard.c

SRC_MLX_KEYBOARD_C = $(addprefix $(SRC_MLX_KEYBOARD_DIR)/, $(SRC_MLX_KEYBOARD_SRC))


SRC_MLX_MOUSE_SRC =						\
				ft_mac_mouse_down.c			\
				ft_mac_mouse_drag.c			\
				ft_mac_mouse_up.c				\
				ft_mac_mouse.c	

SRC_MLX_MOUSE_C = $(addprefix $(SRC_MLX_MOUSE_DIR)/, $(SRC_MLX_MOUSE_SRC))


SRC_MLX_WIN_SRC =	ft_mac_win.c

SRC_MLX_WIN_C = $(addprefix $(SRC_MLX_WIN_DIR)/, $(SRC_MLX_WIN_SRC))


OBJS =	$(SRC_01_MAIN_C:$(SRC_01_MAIN_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_02_FD_C:$(SRC_02_FD_DIR)/%.c=$(OBJ_DIR)/%.o)		\
		$(SRC_03_PARAM_C:$(SRC_03_PARAM_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_04_RT_C:$(SRC_04_RT_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_05_SCENE_C:$(SRC_05_SCENE_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_06_RENDER_C:$(SRC_06_RENDER_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_07_INTERSECTION_C:$(SRC_07_INTERSECTION_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_08_SHADOW_C:$(SRC_08_SHADOW_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_TOOL_C:$(SRC_TOOL_DIR)/%.c=$(OBJ_DIR)/%.o)				\
		$(SRC_VECTOR_C:$(SRC_VECTOR_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_QUATERNION_C:$(SRC_QUATERNION_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_GEOMETRIC_TRANSFORM_C:$(SRC_GEOMETRIC_TRANSFORM_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MATRIX_C:$(SRC_MATRIX_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_MLX_KEYBOARD_C:$(SRC_MLX_KEYBOARD_DIR)/%.c=$(OBJ_DIR)/%.o)	\
		$(SRC_MLX_MOUSE_C:$(SRC_MLX_MOUSE_DIR)/%.c=$(OBJ_DIR)/%.o)			\
		$(SRC_MLX_WIN_C:$(SRC_MLX_WIN_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJS_CLEAN = $(OBJS)

#####***** working *****#####

all : $(TARGET)

$(OBJ_DIR) : 
	mkdir $@

$(TARGET) : $(OBJ_DIR) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $(TARGET)
	@echo "$(FG_LMAGENTA)$(CC) $(FG_BLUE) $(CFLAGS)"
	@(for i in $(IFLAGS) $(LDFLAGS); do echo $$i; done)
	@echo "$(LDLIBS) $(FG_LCYAN)"
	@(for i in $(OBJS); do echo $$i; done)
	@echo "$(FG_BLUE)-o $(FG_LYELLOW)$(TARGET)$(NO_COLOR)"



$(OBJ_DIR)/%.o : $(SRC_01_MAIN_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_02_FD_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_03_PARAM_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_04_RT_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_05_SCENE_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_06_RENDER_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_07_INTERSECTION_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_08_SHADOW_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_TOOL_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_VECTOR_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_QUATERNION_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o : $(SRC_GEOMETRIC_TRANSFORM_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@
	
$(OBJ_DIR)/%.o : $(SRC_MATRIX_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_KEYBOARD_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_MOUSE_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_MLX_WIN_DIR)/%.c
	$(CC) $(CXXFLAGS) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@

## MODULES ##
$(MINILIBX):
	echo "$(FG_MAGENTA)module $(FG_LYELLOW)minilibx$(NO_COLOR) -> $(FG_LCYAN)$(MINILIBX)$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(MINILIBX_DIR)
	@echo "$(NO_COLOR)"



#####***** clean *****#####
clean : clean_minilibx
	rm -f $(OBJS_CLEAN)

fclean : OBJS_CLEAN+=$(TARGET)
fclean : clean

re : fclean all

.PHONY: all re  clean fclean clean_minilibx

## MODULES ##
clean_minilibx :
	@echo "clean $(FG_MAGENTA)module $(FG_LYELLOW)$(notdir $(MINILIBX))$(NO_COLOR)$(BG_MAKE1)"
	$(MAKE) -C $(MINILIBX_DIR) clean 
	@echo "$(NO_COLOR)"



#####***** COLOR *****#####
BG_RED     = \033[41m
BG_GREEN   = \033[42m
BG_YELLOW  = \033[43m
BG_BLUE    = \033[44m
BG_MAGENTA = \033[45m
BG_CYAN    = \033[46m
BG_LGREY   = \033[47m
BG_DGREY   = \033[100m
BG_LRED    = \033[101m
BG_LGREEN  = \033[102m
BG_LYELLOW = \033[103m
BG_LBLUE   = \033[104m
BG_LMAGENTA= \033[105m
BG_LCYAN   = \033[106m
BG_WHITE   = \033[107m
BG_MAKE1   = \033[48;5;236m
BG_MAKE2   = \033[48;5;238m
BG_MAKE3   = \033[48;5;240m

FG_BLACK   = \033[30m
FG_RED     = \033[31m
FG_GREEN   = \033[32m
FG_YELLOW  = \033[33m
FG_BLUE    = \033[34m
FG_MAGENTA = \033[35m
FG_CYAN    = \033[36m
FG_LGREY   = \033[37m
FG_DGREY   = \033[90m
FG_LRED    = \033[91m
FG_LGREEN  = \033[92m
FG_LYELLOW = \033[93m
FG_LBLUE   = \033[94m
FG_LMAGENTA= \033[95m
FG_LCYAN   = \033[96m
FG_WHITE   = \033[97m
 
CL_BOLD   = \033[1m
CL_DIM    = \033[2m
CL_UDLINE = \033[4m
CL_BLINK  = \033[5m
CL_INVERT = \033[7m
CL_HIDDEN = \033[8m
 
NO_COLOR = \033[0m
