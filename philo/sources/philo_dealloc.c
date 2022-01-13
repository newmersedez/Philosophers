#include "../includes/philo.h"

static void deallocate_philosophers(t_table *table_info)
{
	size_t	i;

	if (!table_info->philos)
		return ;
	i = 0;
	while (i < table_info->nop)
	{
		pthread_mutex_destroy(&table_info->philos[i].eating_mutex);
		++i;
	}
	free(table_info->philos);
}

static void deallocate_forks(t_table *table_info)
{
	size_t	i;

	if (!table_info->forks)
		return ;
	i = 0;
	while (i < table_info->nop)
	{
		pthread_mutex_destroy(&table_info->forks[i]);
		++i;
	}
	free(table_info->forks);
}

void deallocate_memory(t_table *table_info)
{
	if (!table_info)
		return ;
	pthread_mutex_destroy(&table_info->msg_mutex);
	deallocate_philosophers(table_info);
	deallocate_forks(table_info);
}