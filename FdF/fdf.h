/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:59:37 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/12 17:36:03 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./libft/includes/libft.h"
# include "mlx.h"
# include <math.h>
# define IMG_HEIGHT 720
# define IMG_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_WIDTH 1280
# define MAX_COL 0xFF0000
# define MIN_COL 0x00FF00
# define COL_CEN 0xF5F5DC

typedef struct	s_arr
{
	int **map;
	int x;
	int y;
	int z_min;
	int z_max;
}				t_arr;

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int col;
}				t_point;

typedef struct	s_image
{
	void		*img_ptr;
	char		*img_buff;
	int			bpp;
	int			l_size;
	int			endian;
}				t_image;

typedef struct	s_camera
{
	int			x;
	int			y;
	int			z;
	int			offset_x;
	int			offset_y;
	float		scale;
	int			z_hght;
	void		*mlx_ptr;
	void		*win_ptr;
	t_arr		*hook;
	t_image		*img;
}				t_camera;

t_arr			*fdf_valid(char *str);
char			*fdf_reader(char *input);
t_arr			*make_arr(t_arr *arr, char *str);
int				window(t_arr *map);
t_image			*fdf_set_image(t_arr *arr, t_camera *cam, void *mlx_ptr);
int				deal_key(int key, void *cam);
t_point			fdf_rotate(int x, int y, t_arr *arr, t_camera cam);
void			fdf_cam_iso(t_arr *arr, t_camera *cam);
int				deal_mouse(int mouse, int x, int y, void *cam);
int				put_text(t_camera *cam);
void			fdf_free_image(t_camera *cam);
#endif
