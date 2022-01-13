/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitry <dmitry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:53 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/14 01:37:14 by dmitry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eat(t_table *table_info, t_philo *philo)
{
	pthread_mutex_lock(&table_info->forks[philo->left_id]);
	pthread_mutex_lock(&table_info->forks[philo->right_id]);
	display_message(table_info, philo, PHILO_TAKE_FORK);
	pthread_mutex_lock(&philo->eating_mutex);
	display_message(table_info, philo, PHILO_EAT);
	philo->is_eating = TRUE;
	philo->last_time_ate = time_in_ms();
	usleep(table_info->time_to_eat);
	philo->number_of_ate++;
	philo->is_eating = FALSE;
	pthread_mutex_unlock(&philo->eating_mutex);
	pthread_mutex_unlock(&table_info->forks[philo->left_id]);
	pthread_mutex_unlock(&table_info->forks[philo->right_id]);
}

static void	philo_sleep(t_table *table_info, t_philo *philo)
{
	display_message(table_info, philo, PHILO_SLEEP);
	usleep(table_info->time_to_sleep);
}

static void	philo_think(t_table *table_info, t_philo *philo)
{
	display_message(table_info, philo, PHILO_THINK);
}

void	philo_routins(t_philo *philo)
{
	while (philo->table_info->death)
	{
		philo_eat(philo->table_info, philo);
		philo_sleep(philo->table_info, philo);
		philo_think(philo->table_info, philo);
	}
}
