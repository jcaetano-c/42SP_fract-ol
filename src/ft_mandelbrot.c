/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:02:34 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/28 18:31:12 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_render_mandelbrot(t_data *data);
static void	ft_init_mandelbrot(t_data *data);

void	ft_mandelbrot(t_data *data)
{
	ft_init_mandelbrot(data);
	ft_render_mandelbrot(data);
}

static void	ft_render_mandelbrot(t_data *data)
{
	int			iter;
	t_complex	z;

	while (data->y < H)
	{
		data->c.im = data->max.im - (data->y * data->factor.im);
		data->x = 0;
		while (data->x < W)
		{
			data->c.re = data->min.re + (data->x * data->factor.re);
			z = ft_init_complex(data->c.re, data->c.im);
			z.module = pow(z.re, 2.0) + pow(z.im, 2.0);
			iter = 0;
			data->x++;
			while (z.module <= 4 && iter < NMAX)
			{
				z = ft_init_complex(pow(z.re, 2.0) - pow(z.im, 2.0)
						+ data->c.re, 2 * z.re * z.im + data->c.im);
				z.module = pow(z.re, 2.0) + pow(z.im, 2.0);
				iter++;
			}
			ft_img_pixel_put(&data->img, data->x, data->y, ft_get_color(iter));
		}
		data->y++;
	}
}

static void	ft_init_mandelbrot(t_data *data)
{
	data->min = ft_init_complex(-2.0, -2.0);
	data->max.re = 1.5;
	data->max.im = data->min.im + (data->max.re - data->min.re) * H / W;
	data->factor.re = (data->max.re - data->min.re) / (W - 1);
	data->factor.im = (data->max.im - data->min.im) / (H - 1);
}
