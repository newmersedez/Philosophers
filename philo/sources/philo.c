#include "../includes/philo.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_table table_info;

    if (try_parse_args(argc, argv, &table_info) != 0)
	{
		printf("ti daun\n");
		return (1);
	}
	return (0);
}
