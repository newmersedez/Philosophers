#include "../includes/philo_bonus.h"

void deallocate_memory(t_table *table_info)
{
	size_t	i;

	i = 0;
	while (i < table_info->num_of_philos)
	{
		pthread_join(table_info->philos[i]->terminator_thread, NULL);
		++i;
	}
	i = 0;
	while (i < table_info->num_of_philos)
	{
		sem_close(table_info->philos[i]->eating_sem);
		sem_unlink("eating");
		free(table_info->philos[i]);
		++i;
	}
	free(table_info->philos);
	sem_unlink("forks");
	sem_close(table_info->forks_sem);
	sem_unlink("death");
	sem_close(table_info->death_sem);
	sem_unlink("message");
	sem_close(table_info->msg_sem);
	sem_unlink("eating_table");
	sem_close(table_info->eating_sem);
}
