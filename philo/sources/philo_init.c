/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:53 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/13 22:50:32 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_args(int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (!ft_isnumber(argv[i]))
			return (FALSE);
		if (ft_atoi(argv[i]) < 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

static int	try_init_philosophers(t_table *table_info)
{
	size_t	i;

	table_info->philos = (t_philo *)malloc(table_info->num_of_philos
			* sizeof(t_philo));
	if (!table_info->philos)
		return (FALSE);
	i = 0;
	while (i < table_info->num_of_philos)
	{
		table_info->philos[i].id = i;
		table_info->philos[i].left_id = i;
		table_info->philos[i].right_id = (i + 1) % table_info->num_of_philos;
		table_info->philos[i].last_time_ate = time_in_ms();
		table_info->philos[i].number_of_ate = 0;
		if (pthread_mutex_init(&table_info->philos[i].eating_mutex, NULL) != 0)
			return (FALSE);
		++i;
	}	
	return (TRUE);
}

static int	try_init_forks(t_table *table_info)
{
	size_t	i;

	table_info->forks = (pthread_mutex_t *)malloc(table_info->num_of_philos
			* sizeof(pthread_mutex_t));
	if (!table_info->forks)
		return (FALSE);
	i = 0;
	while (i < table_info->num_of_philos)
	{
		if (pthread_mutex_init(&table_info->forks[i], NULL) != 0)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

int	try_init_table(int argc, char *argv[], t_table *table_info)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (!check_args(argc, argv))
		return (FALSE);
	table_info->num_of_philos = ft_atoi(argv[1]);
	table_info->time_to_die = ft_atoi(argv[2]);
	table_info->time_to_eat = ft_atoi(argv[3]);
	table_info->time_to_sleep = ft_atoi(argv[4]);
	table_info->death = FALSE;
	table_info->optional_arg = FALSE;
	table_info->start_time = 0;
	if (argc == 6)
	{
		table_info->notepme = ft_atoi(argv[5]);
		table_info->optional_arg = TRUE;
	}
	if (pthread_mutex_init(&table_info->msg_mutex, NULL) != 0)
		return (FALSE);
	if (!try_init_philosophers(table_info))
		return (FALSE);
	if (!try_init_forks(table_info))
		return (FALSE);
	return (TRUE);
}
