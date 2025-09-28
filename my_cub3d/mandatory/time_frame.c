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

    data->frames++;

    static int fps_display = 0;

    if (elapsed >= 0.1) // update 5 times per second
    {
        fps_display = (int)(data->frames / elapsed + 0.5); // round FPS
        data->frames = 0;
        data->last_time = curr_time;
    }
    char buf[16] = "FPS: ";
    int n = fps_display;
    int i = 5;
    if (n == 0) buf[i++] = '0';
    while (n > 0)
    {
        buf[i++] = '0' + (n % 10);
        n /= 10;
    }
    buf[i] = '\0';
    for (int j = 5, k = i - 1; j < k; j++, k--)
    {
        buf[j] = buf[j] ^ buf[k];
        buf[k] = buf[j] ^ buf[k];
        buf[j] = buf[j] ^ buf[k];
    }
    mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, buf);
}
