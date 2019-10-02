/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:23:05 by rcotter-          #+#    #+#             */
/*   Updated: 2019/03/12 17:56:49 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	change_offset_height(int key, t_camera *cam)
{
	t_image *img;

	if ((int)key == 126)
		cam->offset_y -= 5;
	if ((int)key == 125)
		cam->offset_y += 5;
	if ((int)key == 124)
		cam->offset_x += 5;
	if ((int)key == 123)
		cam->offset_x -= 5;
	if ((int)key == 69)
		cam->z_hght++;
	if ((int)key == 78)
		cam->z_hght--;
	free(((t_camera *)cam)->img);
	mlx_destroy_image(((t_camera *)cam)->mlx_ptr,
				((t_camera *)cam)->img->img_ptr);
	mlx_clear_window(cam->mlx_ptr, cam->win_ptr);
	img = fdf_set_image(cam->hook, cam, cam->mlx_ptr);
	mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, img->img_ptr, 0, 0);
	put_text(cam);
	return (0);
}

static int	change_projection(int key, t_camera *cam)
{
	t_image *img;

	fdf_cam_iso(cam->hook, cam);
	if ((int)key == 259)
	{
		cam->x = 0;
		cam->y = 0;
		cam->z = 0;
		cam->offset_y = IMG_HEIGHT - (cam->hook->y * 1.1) * cam->scale;
	}
	free(((t_camera *)cam)->img);
	mlx_destroy_image(((t_camera *)cam)->mlx_ptr,
					((t_camera *)cam)->img->img_ptr);
	mlx_clear_window(cam->mlx_ptr, cam->win_ptr);
	img = fdf_set_image(cam->hook, cam, cam->mlx_ptr);
	mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, img->img_ptr, 0, 0);
	put_text(cam);
	return (0);
}

static int	change_angle(int key, t_camera *cam)
{
	t_image *img;

	if ((int)key == 12)
		cam->x++;
	if ((int)key == 13)
		cam->y++;
	if ((int)key == 14)
		cam->z--;
	if ((int)key == 0)
		cam->x--;
	if ((int)key == 1)
		cam->y--;
	if ((int)key == 2)
		cam->z++;
	free(((t_camera *)cam)->img);
	mlx_destroy_image(((t_camera *)cam)->mlx_ptr,
					((t_camera *)cam)->img->img_ptr);
	mlx_clear_window(cam->mlx_ptr, cam->win_ptr);
	img = fdf_set_image(cam->hook, cam, cam->mlx_ptr);
	mlx_put_image_to_window(cam->mlx_ptr, cam->win_ptr, img->img_ptr, 0, 0);
	put_text(cam);
	return (0);
}

int			deal_key(int key, void *cam)
{
	if ((int)key == 53)
	{
		free(((t_camera *)cam)->img);
		mlx_destroy_image(((t_camera *)cam)->mlx_ptr,
					((t_camera *)cam)->img->img_ptr);
		ft_printf("esc: quit the program\n");
		mlx_destroy_window(((t_camera *)cam)->mlx_ptr,
			((t_camera *)cam)->win_ptr);
		exit(0);
	}
	if ((int)key == 126 || (int)key == 125 || (int)key == 124
		|| (int)key == 123 || (int)key == 69 || (int)key == 78)
		change_offset_height(key, (t_camera *)cam);
	if ((int)key == 49 || (int)key == 259)
		change_projection(key, (t_camera *)cam);
	if ((int)key == 12 || (int)key == 13 || (int)key == 14
		|| (int)key == 0 || (int)key == 1 || (int)key == 2)
		change_angle(key, (t_camera *)cam);
	return (0);
}

int			deal_mouse(int mouse, int x, int y, void *cam)
{
	t_image *img;

	x = 0;
	y = 0;
	if ((int)mouse == 4 || (int)mouse == 5)
	{
		free(((t_camera *)cam)->img);
		mlx_destroy_image(((t_camera *)cam)->mlx_ptr,
							((t_camera *)cam)->img->img_ptr);
		if ((int)mouse == 5)
			((t_camera *)cam)->scale /= 1.1;
		if ((int)mouse == 4 && ((t_camera *)cam)->scale > 0)
			((t_camera *)cam)->scale *= 1.1;
		mlx_clear_window(((t_camera *)cam)->mlx_ptr,
			((t_camera *)cam)->win_ptr);
		img = fdf_set_image(((t_camera *)cam)->hook,
			((t_camera *)cam), ((t_camera *)cam)->mlx_ptr);
		mlx_put_image_to_window(((t_camera *)cam)->mlx_ptr,
			((t_camera *)cam)->win_ptr, img->img_ptr, 0, 0);
		put_text(cam);
	}
	return (0);
}
