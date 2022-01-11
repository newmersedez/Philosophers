#include "../includes/philo_bonus.h"

static int check_args(int argc, char *argv[])
{
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		++i;
	}
	return (1);
}

int	try_parse_args(int argc, char *argv[], t_table *table_info)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (!check_args(argc, argv))
		return (1);
	table_info->nop = ft_atoi(argv[1]);
	table_info->ttd = ft_atoi(argv[2]);
	table_info->tte = ft_atoi(argv[3]);
	table_info->tts = ft_atoi(argv[4]);
	table_info->optional_arg = FALSE;
	if (argc == 6)
	{
		table_info->notepme = ft_atoi(argv[5]);
		table_info->optional_arg = TRUE;
	}
	return (0);
}