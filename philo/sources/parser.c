#include "../includes/philosophers.h"

static int	isnumber(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_arguments_correctness(int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (!isnumber(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_program_arguments(int argc, char *argv[], t_info *info)
{
	if (argc != 5 && argc != 6)
		return (0);
	(void)info;
	if (!check_arguments_correctness(argc, argv))
		return (0);
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	return (1);
}
