/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:50:18 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/18 15:04:51 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	*eat_counter_handler(t_table *table_info)
{
	size_t	eat_counter;
	size_t	i;

	eat_counter = 0;
	while (eat_counter < (size_t)table_info->notepme)
	{
		i = 0;
		while (i < table_info->num_of_philos)
		{
			sem_wait(table_info->eating_sem);
			i++;
		}
		eat_counter++;
	}
	sem_wait(table_info->msg_sem);
	i = 0;
	while (i < table_info->num_of_philos)
	{
		kill(table_info->philos[i]->pid, SIGKILL);
		++i;
	}
	return (NULL);
}

static void	child_waiter(t_table *table_info)
{
	size_t	i;
	size_t	j;
	int		status;

	i = 0;
	while (i < table_info->num_of_philos)
	{
		j = 0;
		waitpid(-1, &status, 0);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			while (j < table_info->num_of_philos)
				kill(table_info->philos[j++]->pid, SIGKILL);
		i++;
	}
	return ;
}

void	*philo_terminator(t_philo *philo)
{
	while (TRUE)
	{
		sem_wait(philo->eating_sem);
		if (current_time() - philo->last_time_ate
			>= philo->table_info->time_to_die)
		{
			display_message(philo, PHILO_DIED);
			exit(1);
		}
		sem_post(philo->eating_sem);
		usleep(100);
	}
	return (NULL);
}

static int	try_start_threads(t_table *table_info)
{
	size_t	i;

	i = 0;
	if (table_info->notepme != -1 && pthread_create(&table_info->eat_counter,
			NULL, (void *)&eat_counter_handler, table_info) != 0)
		return (FALSE);
	table_info->start_time = current_time();
	while (i < table_info->num_of_philos)
	{
		table_info->philos[i]->pid = fork();
		table_info->philos[i]->last_time_ate = current_time();
		if (table_info->philos[i]->pid == 0)
		{
			if (pthread_create(&table_info->philos[i]->terminator_thread, NULL,
					(void *)&philo_terminator, table_info->philos[i]) != 0)
				return (FALSE);
			philo_routins(table_info->philos[i]);
			exit(1);
		}
		usleep(100);
		i++;
	}
	child_waiter(table_info);
	return (TRUE);
}

void	start_philosophers(t_table *table_info)
{
	if (!table_info)
		return ;
	if (!try_start_threads(table_info))
		return ;
}
