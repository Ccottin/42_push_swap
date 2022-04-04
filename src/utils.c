#include "../include/push_swap.h"

long int	ft_atoi(char *str)
{
	int		i;
	long int	res;
	int		sign;

	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	res = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	*ft_calloc(int size)
{
	int	i;
	void	*ptr;
	char	*str;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	str = ptr;
	i = 0;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (ptr);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return (i);
}
