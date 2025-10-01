/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:00:54 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/28 22:01:40 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double  get_time(void)
{
  struct timeval time_frame;

  gettimeofday(&time_frame, NULL);
  return (time_frame.tv_sec + time_frame.tv_usec / 1000000.0);
}

void get_fps(t_data *data)
{
    double curr_time = get_time();
    double elapsed = curr_time - data->last_time;
    static int fps_display = 0;
    
    data->frames++;
   if (elapsed >= 0.15)
    {
        fps_display = (data->frames / elapsed);
        data->frames = 0;
        data->last_time = curr_time;
    }
    mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, "FPS: ");
    mlx_string_put(data->mlx, data->win, 36, 10, 0xFFFFFF, ft_itoa(fps_display));
}
