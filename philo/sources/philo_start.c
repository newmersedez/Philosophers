/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:59:02 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/13 22:58:49 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int philo_terminator(t_philo philo)
{
	(void)philo;
}

static int	try_start_threads(t_table *table)
{
	(void)table;
}

void	start_philosophers(t_table *table_info)
{
	if (!table_info)
		return ;
	if (!try_start_threads(table_info))
		return ;
}
