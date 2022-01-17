/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:59:02 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/17 19:07:18 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*philo_terminator(t_philo *philo)
{
	while (philo->table_info->alive)
	{
		if (!philo->is_eating && current_time() - philo->last_time_ate >= philo->table_info->time_to_die)
		{
			pthread_mutex_lock(&philo->eating_mutex);
			display_message(philo, PHILO_DIED);
			philo->table_info->alive = FALSE;
			pthread_mutex_unlock(&philo->eating_mutex);
		}
		if (philo->table_info->philos[philo->table_info->num_of_philos - 1]->number_of_ate == philo->table_info->notepme)
			philo->table_info->alive = FALSE;
		usleep(100);
	}
	return (NULL);
}

static int	try_start_threads(t_table *table_info)
{
	size_t	i;

	i = 0;
	table_info->start_time = current_time();
	while (i < table_info->num_of_philos)
	{
		table_info->philos[i]->last_time_ate = current_time();
		if (pthread_create(&table_info->philos[i]->philo_thread, NULL, (void *)&philo_routins, (void *)table_info->philos[i]) != 0)
			return (FALSE);
		++i;
		usleep(100);
	}
	i = 0;
	while (i < table_info->num_of_philos)
	{
		if (pthread_create(&table_info->philos[i]->terminator_thread, NULL, (void *)&philo_terminator, (void *)table_info->philos[i]) != 0)
			return (FALSE);
		++i;
		usleep(100);
	}
	while (table_info->alive)
		continue ;
	return (TRUE);
}

void	start_philosophers(t_table *table_info)
{
	if (!table_info)
		return ;
	if (!try_start_threads(table_info))
		return ;
}
