/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:23:32 by prichugh          #+#    #+#             */
/*   Updated: 2024/08/05 15:23:32 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <X11/keysym.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/Xatom.h>
# include <string.h>
# include <stdarg.h>

# define LEN 800
# define HEIGHT 800
# define MIN_SCALE 2.0
# define MAX_SCALE 50.0

typedef struct s_menu
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_menu;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		width;
	int		height;
}			t_img;

typedef struct s_transform
{
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	center_x;
	float	center_y;
}			t_transform;

typedef struct s_help
{
	int		visible;
	char	*content;
}			t_help;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*filename;
	t_img		img;
	int			height;
	int			width;
	int			**map;
	float		scale;
	int			color;
	int			shift_x;
	int			shift_y;
	float		x_distance;
	float		y_distance;
	int			max;
	int			z1;
	int			z2;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		z_scale;
	float		scale_factor;
	t_help		help;
	t_transform	transform;
}			t_data;

char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		check_type(const char *format, int i, va_list args);
void	ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putstr_ptr(char *s);
char	*ft_itoa(int n);
char	*ft_puthex(unsigned int n, const char format);
char	*ft_putptr(void *ptr);

size_t	ft_strlen(const char *c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strchr(const char *s, char c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	count_tokens(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
int		ft_putstr(char *s);
char	*get_next_line(int fd);

int		max(int x, int y);
int		abs_val(int i);
void	draw(t_data *data);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	calculate_wireframe_center(t_data *data);
int		cleanup(t_data *data);
void	reset_data(t_data *data);
void	draw_rect_horizontal(t_img *img, int x, int y, int width);
void	draw_rect_vertical(t_img *img, int x, int y, int height);
void	draw_rect(t_img *img);
void	draw_help_menu(t_data *data);
void	handle_help_menu(int keysym, t_data *data);
void	clear_image(t_img *img, int width, int height, int color);
void	handle_exit(int keysym, t_data *data);
void	handle_reset(int keysym, t_data *data);
void	adjust_scale(t_data *data, float scale_factor);
void	handle_movement(int keysym, t_data *data);
void	handle_rotation(int keysym, t_data *data);
void	redraw_image(t_data *data);
int		handle_input(int keysym, t_data *data);
void	isometric(float *x, float *y, int z, t_data *data);
void	init_bresenham_vars(t_data *data);
void	set_color(int z1, int z2, t_data *data);
void	transform_coordinates(t_data *data);
void	draw_line(t_data *data);
void	bresenham(t_data *data);
int		get_height(char *file_name);
int		get_width(char *file_name);
void	fill_map(int *z_line, char *line);
void	read_file(char *file_name, t_data *data);
void	center_data(t_data *data);
void	reset_data(t_data *data);
void	set_data(t_data *data);
int		validate_args(int argc);
int		validate_file(char *filename);
t_data	*init_data(char *filename);
int		create_window(t_data *data);
int		create_image(t_data *data);
void	setup_hooks(t_data *data);
int		cleanup(t_data *data);
int		main(int argc, char **argv);

#endif
