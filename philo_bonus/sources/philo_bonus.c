#include "../includes/philo_bonus.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_table table_info;

    if (try_parse_args(argc, argv, &table_info) != 0)
	{
		start_philosophers(&table_info);
		// deallocate_memory(&table_info);
	}
	return (0);
}
