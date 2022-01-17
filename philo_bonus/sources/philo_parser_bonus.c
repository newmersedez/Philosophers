#include "../includes/philo_bonus.h"

static int check_args(int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		++i;
	}
	return (1);
}

static int try_init_semaphores(t_table *table_info)
{
	table_info->forks_sem = sem_open("forks", O_CREAT, 0644, table_info->num_of_philos);
	if (table_info->forks_sem == SEM_FAILED)
		return (FALSE);
	table_info->death_sem = sem_open("death", O_CREAT, 0644, 1);
	if (table_info->death_sem == SEM_FAILED)
		return (FALSE);
	table_info->msg_sem = sem_open("message", O_CREAT, 0644, 1);
	if (table_info->msg_sem == SEM_FAILED)
		return (FALSE);
	return (TRUE);
}

static int try_init_philosophers(t_table *table_info)
{
	size_t	i;

	i = 0;
	table_info->philos = (t_philo **)malloc(table_info->num_of_philos * sizeof(t_philo *));
	if (!table_info->philos)
		return (FALSE);
	while (i < table_info->num_of_philos)
	{
		table_info->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!table_info->philos[i])
			return (FALSE);
		table_info->philos[i]->eating_sem = sem_open("eating", O_CREAT, 0644, 1);
		if (table_info->philos[i]->eating_sem == SEM_FAILED)
			return (FALSE);
		table_info->philos[i]->id = i;
		table_info->philos[i]->number_of_ate = 0;
		table_info->philos[i]->table_info = table_info;
		++i;
	}
	return (TRUE);
}

int	try_parse_args(int argc, char *argv[], t_table *table_info)
{
	if (!table_info)
		return (FALSE);
	if (argc != 5 && argc != 6)
		return (1);
	if (!check_args(argc, argv))
		return (1);
	table_info->num_of_philos = ft_atoi(argv[1]);
	table_info->time_to_die = ft_atoi(argv[2]);
	table_info->time_to_eat = ft_atoi(argv[3]);
	table_info->time_to_sleep = ft_atoi(argv[4]);
	table_info->notepme = -1;
	if (argc == 6)
		table_info->notepme = ft_atoi(argv[5]);
	if (!try_init_semaphores(table_info))
		return (FALSE);
	if (!try_init_philosophers(table_info))
		return (FALSE);
	return (TRUE);
}