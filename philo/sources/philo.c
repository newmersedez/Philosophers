/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:51 by lorphan           #+#    #+#             */
/*   Updated: 2022/01/18 15:51:53 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_table	table_info;

	if (!try_init_table(argc, argv, &table_info))
		return (1);
	start_philosophers(&table_info);
	deallocate_memory(&table_info);
	return (0);
}
