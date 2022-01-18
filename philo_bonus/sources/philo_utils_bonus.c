/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:32:19 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/18 14:52:48 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

time_t	current_time(void)
{
	struct timeval	tv;
	time_t			res;

	gettimeofday(&tv, NULL);
	res = 1000 * tv.tv_sec + tv.tv_usec / 1000;
	return (res);
}

void	display_message(t_philo *philo, unsigned int type)
{
	time_t	time;

	sem_wait(philo->table_info->msg_sem);
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
	sem_post(philo->table_info->msg_sem);
}
