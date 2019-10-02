/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:23:05 by rcotter-          #+#    #+#             */
/*   Updated: 2019/03/12 17:51:43 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int			fdf_pixel_img(t_point p1, t_image *img, int col)
{
	int		to;

	if (p1.x >= IMG_WIDTH || p1.y >= IMG_HEIGHT || p1.x < 0 || p1.y < 0)
		return (0);
	to = IMG_WIDTH * 4 * p1.y + 4 * p1.x;
	ft_memcpy(img->img_buff + to, &col, 4);
	return (1);
}

static void			put_line(t_point p1, t_point p2, t_image *img)
{
	float	err;
	float	derr;
	t_point	step;

	step.x = (p2.x > p1.x) ? 1 : -1;
	step.y = (p2.y > p1.y) ? 1 : -1;
	if (p1.x == p2.x)
		while ((p1.y += step.y) != p2.y + step.y)
			fdf_pixel_img(p1, img, (p1.col == p2.col) ? p1.col : COL_CEN);
	if (p1.x == p2.x)
		return ;
	err = 0.0;
	derr = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	derr = (derr > 0) ? derr : -derr;
	while ((p1.x += step.x) != p2.x + step.x)
	{
		fdf_pixel_img(p1, img, (p1.col == p2.col) ? p1.col : COL_CEN);
		err += derr;
		while (err >= 0.5)
		{
			p1.y += step.y;
			err -= 1.0;
			fdf_pixel_img(p1, img, (p1.col == p2.col) ? p1.col : COL_CEN);
		}
	}
}

t_point				fdf_rotate(int x, int y, t_arr *arr, t_camera cam)
{
	t_point new_p;
	t_point new_p2;
	t_point new_p3;

	new_p.x = x * cam.scale;
	new_p.y = cos(cam.x * M_PI / 180) * y * cam.scale
		- sin(cam.x * M_PI / 180) * (arr->map[y][x] - arr->z_min) * cam.z_hght;
	new_p.z = sin(cam.x * M_PI / 180) * y * cam.scale
		+ cos(cam.x * M_PI / 180) * (arr->map[y][x] - arr->z_min) * cam.z_hght;
	new_p2.y = new_p.y;
	new_p2.x = cos(cam.y * M_PI / 180) * new_p.x
							+ sin(cam.y * M_PI / 180) * new_p.z;
	new_p2.z = -sin(cam.y * M_PI / 180) * new_p.x
							+ cos(cam.y * M_PI / 180) * new_p.z;
	new_p3.z = new_p2.z;
	new_p3.x = cos(cam.z * M_PI / 180) * new_p2.x + cam.offset_x
							- sin(cam.z * M_PI / 180) * new_p2.y;
	new_p3.y = sin(cam.z * M_PI / 180) * new_p2.x + cam.offset_y
							+ cos(cam.z * M_PI / 180) * new_p2.y;
	new_p3.col = COL_CEN;
	if ((y < arr->y) && arr->map[y][x] == arr->z_min)
		new_p3.col = MIN_COL;
	else if (arr->map[y][x] == arr->z_max)
		new_p3.col = MAX_COL;
	return (new_p3);
}

static void			fdf_each_point(t_arr *arr, t_camera cam, t_image *img)
{
	t_point	p0;
	t_point	p1;
	t_point	p2;

	p0.y = 0;
	while (p0.y < arr->y && p0.y * cam.scale < IMG_HEIGHT)
	{
		p0.x = 0;
		while (p0.x < arr->x && p0.x * cam.scale < IMG_WIDTH)
		{
			p1 = fdf_rotate(p0.x, p0.y, arr, cam);
			if (p0.y + 1 < arr->y)
			{
				p2 = fdf_rotate(p0.x, p0.y + 1, arr, cam);
				put_line(p1, p2, img);
			}
			if (p0.x + 1 < arr->x)
			{
				p2 = fdf_rotate(p0.x + 1, p0.y, arr, cam);
				put_line(p1, p2, img);
			}
			p0.x++;
		}
		p0.y++;
	}
}

t_image				*fdf_set_image(t_arr *arr, t_camera *cam, void *mlx_ptr)
{
	if (!(cam->img = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(cam->img->img_ptr = mlx_new_image(mlx_ptr, IMG_WIDTH, IMG_HEIGHT)))
		return (NULL);
	cam->img->img_buff = mlx_get_data_addr(cam->img->img_ptr, &cam->img->bpp,
										&cam->img->l_size, &cam->img->endian);
	fdf_each_point(arr, *cam, cam->img);
	return (cam->img);
}
