/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaetano <jcaetano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 05:40:01 by jcaetano          #+#    #+#             */
/*   Updated: 2021/12/27 11:37:26 by jcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, W, H, data->title);
	if (!data->win_ptr)
		free(data->win_ptr);
}
