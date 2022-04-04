#include "../include/push_swap.h"

char	*stock_move(t_data *data, char *move)
{
	int	i;
	int	j;
	char	*ret;

	ret = ft_calloc(ft_strlen(data->temp.move) + ft_strlen(move) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	if (data->temp.move != NULL)
	{
		while (data->temp.move[i])
		{
			ret[i] = data->temp.move[i];
			i++;
		}
	}
	j = 0;
	while (move[j])
	{
		ret[i] = move[j];
		j++;
		i++;
	}
	if (data->temp.move != NULL)
		free(data->temp.move);
	return (ret);
}
