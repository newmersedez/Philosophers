/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routines_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:50:15 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/18 14:55:47 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	philo_eat(t_philo *philo)
{
	sem_wait(philo->table_info->forks_sem);
	sem_wait(philo->table_info->forks_sem);
	display_message(philo, PHILO_TAKE_FORK);
	sem_wait(philo->eating_sem);
	display_message(philo, PHILO_EAT);
	philo->last_time_ate = current_time();
	usleep(philo->table_info->time_to_eat * 1000 - 15000);
	while (current_time() - philo->last_time_ate
		< philo->table_info->time_to_eat)
		continue ;
	sem_post(philo->table_info->eating_sem);
	sem_post(philo->eating_sem);
	sem_post(philo->table_info->forks_sem);
	sem_post(philo->table_info->forks_sem);
}

static void	philo_sleep(t_philo *philo)
{
	time_t	time;

	time = current_time();
	display_message(philo, PHILO_SLEEP);
	usleep(philo->table_info->time_to_sleep * 1000 - 15000);
	while (current_time() - time < philo->table_info->time_to_sleep)
		continue ;
}

static void	philo_think(t_philo *philo)
{
	display_message(philo, PHILO_THINK);
}

void	*philo_routins(t_philo *philo)
{
	while (TRUE)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(100);
	}
	return (NULL);
}
