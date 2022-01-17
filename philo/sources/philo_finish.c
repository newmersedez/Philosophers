/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:59:06 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/17 18:47:45 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	deallocate_forks(t_table *table_info)
{
	size_t	i;

	if (!table_info->forks)
		return ;
	i = 0;
	while (i < table_info->num_of_philos)
	{
		pthread_mutex_destroy(&table_info->forks[i]);
		i++;
	}
	free(table_info->forks);
}

static void	deallocate_philosophers(t_table *table_info)
{
	size_t	i;

	if (!table_info->philos)
		return ;
	i = 0;
	while (i < table_info->num_of_philos)
	{
		pthread_mutex_destroy(&table_info->philos[i]->eating_mutex);
		free(table_info->philos[i]);
		i++;
	}
	free(table_info->philos);
}

void	deallocate_memory(t_table *table_info)
{
	if (!table_info)
		return ;
	pthread_mutex_destroy(&table_info->msg_mutex);
	deallocate_forks(table_info);
	deallocate_philosophers(table_info);
}
