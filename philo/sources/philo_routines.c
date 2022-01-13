/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:53 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/13 22:52:34 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eat(t_table *table_info, t_philo philo)
{
	pthread_mutex_lock(&table_info->forks[philo.left_id]);
	pthread_mutex_lock(&table_info->forks[philo.right_id]);
	display_message(table_info, philo, PHILO_TAKE_FORK);
	pthread_mutex_lock(&philo.eating_mutex);
	display_message(table_info, philo, PHILO_EAT);
	philo.last_time_ate = time_in_ms();
	usleep(table_info->time_to_eat);
	philo.number_of_ate++;
	pthread_mutex_unlock(&philo.eating_mutex);
	pthread_mutex_unlock(&table_info->forks[philo.left_id]);
	pthread_mutex_unlock(&table_info->forks[philo.right_id]);
}

static void	philo_sleep(t_table *table_info, t_philo philo)
{
	display_message(table_info, philo, PHILO_SLEEP);
	usleep(table_info->time_to_sleep);
}

static void	philo_think(t_table *table_info, t_philo philo)
{
	display_message(table_info, philo, PHILO_THINK);
}

void	philo_routins(t_table *table_info, t_philo philo)
{
	while (table_info->death)
	{
		philo_eat(table_info, philo);
		philo_sleep(table_info, philo);
		philo_think(table_info, philo);
	}
}
