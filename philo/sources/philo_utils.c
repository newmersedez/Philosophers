/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:32:19 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/14 02:06:01 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	time_in_ms(void)
{
	struct timeval	te;
	time_t			milliseconds;

	gettimeofday(&te, NULL);
	milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (milliseconds);
}

void	display_message(t_philo *philo, unsigned int type)
{
	pthread_mutex_lock(&philo->table_info->msg_mutex);
	if (type == PHILO_TAKE_FORK)
		printf("%ld %zu has taken a fork\n", philo->table_info->start_time, philo->id + 1);
	if (type == PHILO_EAT)
		printf("%ld %zu is eating\n", philo->table_info->start_time, philo->id + 1);
	if (type == PHILO_SLEEP)
		printf("%ld %zu is sleeping\n", philo->table_info->start_time, philo->id + 1);
	if (type == PHILO_THINK)
		printf("%ld %zu is thinking\n", philo->table_info->start_time, philo->id + 1);
	if (type == PHILO_DIED)
		printf("%ld %zu died\n", philo->table_info->start_time, philo->id + 1);
	pthread_mutex_unlock(&philo->table_info->msg_mutex);
}
