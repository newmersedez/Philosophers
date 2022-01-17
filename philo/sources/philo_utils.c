/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:32:19 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/17 19:20:49 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	current_time(void)
{
	struct timeval	tv;
	time_t			res;

	gettimeofday(&tv, NULL);
	res = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (res);
}

void ft_usleep(time_t ms)
{
	time_t	time;

	time = current_time();
	usleep(ms * 1000 - 16000);
	while (current_time() < time + ms)
		continue ;
}

void	display_message(t_philo *philo, unsigned int type)
{
	time_t	time;

	pthread_mutex_lock(&philo->table_info->msg_mutex);
	time = current_time() - philo->table_info->start_time;
	if (type == PHILO_TAKE_FORK)
		printf("%ld %zu has taken a fork\n", time, philo->id + 1);
	if (type == PHILO_EAT)
		printf("%ld %zu is eating\n", time, philo->id + 1);
	if (type == PHILO_SLEEP)
		printf("%ld %zu is sleeping\n", time, philo->id + 1);
	if (type == PHILO_THINK)
		printf("%ld %zu is thinking\n", time, philo->id + 1);
	if (type == PHILO_DIED)
		printf("%ld %zu died\n", time, philo->id + 1);
	pthread_mutex_unlock(&philo->table_info->msg_mutex);
}
