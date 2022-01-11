#include "../includes/philo.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long int	tmp_result;
	long long int	result;
	int				negative;

	result = 0;
	negative = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		tmp_result = result;
		result = result * 10 + (*str - '0');
		if ((tmp_result != (result - (*str - '0')) / 10) && negative == 1)
			return (-1);
		else if ((tmp_result != (result - (*str - '0')) / 10) && negative == -1)
			return (0);
		str++;
	}	
	return ((int)(negative * result));
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_isnumber(const char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
	{
		++str;
		if (!(*str) || (*str && !ft_isdigit(*str)))
			return (0);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}