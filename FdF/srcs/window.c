/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:23:05 by rcotter-          #+#    #+#             */
/*   Updated: 2019/03/12 17:46:55 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		put_text(t_camera *cam)
{
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 50, 0xFFFFFF,
		"Change height  - '+', '-'");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 80, 0xFFFFFF,
		"Change angle x - 'Q', 'A'");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 110, 0xFFFFFF,
		"Change angle y - 'W', 'S'");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 140, 0xFFFFFF,
		"Change angle z - 'E', 'D'");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 170, 0xFFFFFF,
		"Change scale   - scroll up, down");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 200, 0xFFFFFF,
		"Move image     - arrorws");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 230, 0xFFFFFF,
		"Iso projection - 'space'");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 260, 0xFFFFFF,
		"Parallel       - 'command'");
	mlx_string_put(cam->mlx_ptr, cam->win_ptr, 50, 290, 0xFFFFFF,
		"Quit programm  - 'esc'");
	return (0);
}

void	fdf_cam_iso(t_arr *arr, t_camera *cam)
{
	float	tmp_x;
	float	tmp_y;
	t_point	p1;

	cam->x = 30;
	cam->y = 30;
	cam->z = -30;
	cam->z_hght = 1;
	p1.x = (2 * arr->x) * cos(30 * M_PI / 180) + (arr->y) *
		sin(30 * M_PI / 180);
	p1.y = (2 * arr->y) * cos(30 * M_PI / 180) * sin(30 * M_PI / 180);
	tmp_x = ((float)p1.x / IMG_WIDTH);
	tmp_y = ((float)p1.y / IMG_HEIGHT);
	cam->scale = (tmp_x > tmp_y) ? (1 / tmp_x) : (1 / tmp_y);
	cam->offset_x = IMG_WIDTH - (p1.x) * cam->scale * 0.7;
	cam->offset_y = IMG_HEIGHT - (p1.y) * cam->scale * 0.9;
}

int		window(t_arr *arr)
{
	t_image		*img;
	t_camera	cam;

	if (!(cam.mlx_ptr = mlx_init()))
		exit(0);
	if (!(cam.win_ptr = mlx_new_window(cam.mlx_ptr, 1280, 720, "mlx")))
		exit(0);
	fdf_cam_iso(arr, &cam);
	cam.hook = arr;
	img = fdf_set_image(arr, &cam, cam.mlx_ptr);
	mlx_put_image_to_window(cam.mlx_ptr, cam.win_ptr, img->img_ptr, 0, 0);
	ft_printf("Give me a moment, I'm printing...\n");
	put_text(&cam);
	mlx_hook(cam.win_ptr, 2, 1, deal_key, &cam);
	mlx_hook(cam.win_ptr, 4, 1, deal_mouse, &cam);
	mlx_loop(cam.mlx_ptr);
	return (0);
}
