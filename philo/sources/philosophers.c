/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:42:49 by lorphan           #+#    #+#             */
/*   Updated: 2021/10/09 21:13:22 by lorphan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv)
{
	t_info	philosophers;
	
	if (set_defaults(&philosophers, argc, argv) != 0)
		return (-1);
	return (0);
}