/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:53 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/13 18:04:06 by lorphan          ###   ########.fr       */
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

	table_info->philos = (t_philo *)malloc(table_info->nop * sizeof(t_philo));
	if (!table_info->philos)
		return (FALSE);
	i = 0;
	while (i < table_info->nop)
	{
		table_info->philos[i].id = i + 1;
		table_info->philos[i].nta = 0;
		table_info->philos[i].left_id = i;
		table_info->philos[i].right_id = (i + 1) % table_info->nop;
		if (pthread_mutex_init(&table_info->philos[i].eating_mutex, NULL) != 0)
			return (FALSE);
		++i;
	}	
	return (TRUE);
}

static int	try_init_forks(t_table *table_info)
{
	(void)table_info;
	return (TRUE);
}

int	try_init_table(int argc, char *argv[], t_table *table_info)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (!check_args(argc, argv))
		return (FALSE);
	table_info->nop = ft_atoi(argv[1]);
	table_info->ttd = ft_atoi(argv[2]);
	table_info->tte = ft_atoi(argv[3]);
	table_info->tts = ft_atoi(argv[4]);
	table_info->optional_arg = FALSE;
	table_info->death = FALSE;
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
