/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:09:09 by meserghi          #+#    #+#             */
/*   Updated: 2024/02/13 17:51:24 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_julai(int x, int y, t_data *data)
{
	t_nb_cmp	z;
	t_nb_cmp	c;
	int			i;
	int			color;

	c.r = data->input.r;
	c.i = data->input.i;
	i = 0;
	z.r = to_another_rang(x, data->dir.x_n, data->dir.x_p, WIDTH) + data->s.x;
	z.i = to_another_rang(y, data->dir.y_p, data->dir.y_n, HEIGHT) + data->s.y;
	while (i < data->max_itra)
	{
		z = small_equa(z, c);
		if ((pow(z.r, 2) + pow(z.i, 2)) > data->axis)
		{
			color = to_another_rang(i, BLACK, RED, data->max_itra);
			my_pixel_put(&data->img, x, y, color);
			return ;
		}
		i++;
	}
	my_pixel_put(&data->img, x, y, BLACK);
}
