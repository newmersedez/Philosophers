/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:32:19 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/13 22:39:34 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	time_in_ms(void)
{
	struct timeval	tv;
	time_t			time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000L + tv.tv_usec / 1000;
	return (time_ms);
}

void	display_message(t_table *table_info, t_philo philo, unsigned int type)
{
	pthread_mutex_lock(&table_info->msg_mutex);
	if (type == PHILO_TAKE_FORK)
		printf("%ld %zu has taken a fork\n", table_info->start_time, philo.id);
	if (type == PHILO_EAT)
		printf("%ld %zu is eating\n", table_info->start_time, philo.id);
	if (type == PHILO_SLEEP)
		printf("%ld %zu is sleeping\n", table_info->start_time, philo.id);
	if (type == PHILO_THINK)
		printf("%ld %zu is thinking\n", table_info->start_time, philo.id);
	if (type == PHILO_DIED)
		printf("%ld %zu died\n", table_info->start_time, philo.id);
	pthread_mutex_unlock(&table_info->msg_mutex);
}
