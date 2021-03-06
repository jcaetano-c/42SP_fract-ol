/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:14:53 by jcaetano          #+#    #+#             */
/*   Updated: 2022/01/04 13:31:44 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_zoom_update(t_data *data, t_scale scale, int zoom_in);

int	ft_zoom(int button, int x, int y, t_data *data)
{
	t_scale	scale;

	scale.x_ratio = (double)x / W;
	scale.y_ratio = (double)y / H;
	scale.delta_x2 = data->max.re - data->min.re;
	scale.delta_y2 = data->max.im - data->min.im;
	data->x = 0;
	data->y = 0;
	if (button == SCROLL_UP)
		ft_zoom_update(data, scale, 1);
	if (button == SCROLL_DOWN)
		ft_zoom_update(data, scale, 0);
	ft_render(data);
	return (1);
}

static void	ft_zoom_update(t_data *data, t_scale scale, int zoom_in)
{
	if (zoom_in)
	{
		scale.delta_x2 = ((0.95) * scale.delta_x2) - scale.delta_x2;
		scale.delta_y2 = ((0.95) * scale.delta_y2) - scale.delta_y2;
	}
	else
	{
		scale.delta_x2 = (1.05 * scale.delta_x2) - scale.delta_x2;
		scale.delta_y2 = (1.05 * scale.delta_y2) - scale.delta_y2;
	}
	data->min.re -= (scale.delta_x2 * scale.x_ratio);
	data->max.re += (scale.delta_x2 * (1.0 - scale.x_ratio));
	data->max.im += (scale.delta_y2 * scale.y_ratio);
	data->min.im -= (scale.delta_y2 * (1.0 - scale.y_ratio));
	data->factor.re = (data->max.re - data->min.re) / (W - 1);
	data->factor.im = (data->max.im - data->min.im) / (H - 1);
}
