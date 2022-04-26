#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_nbr {
	int		nb;
	int		ord;
	char		*bin;
	struct s_nbr	*next;
}			t_nbr;

typedef struct s_algo {
	int	nb_move;
	char	*move;
}		t_algo;

typedef struct s_data {
	int	total;
	t_nbr	*stack_a;
	t_nbr	*stack_b;
	t_algo	temp;
}		t_data;


int	check_arg(char **av, int m);
int	ft_strlen(char *str);
char	*stock_move(t_data *data, char *move);
char	**ft_split(char *s, char c);
t_nbr	*ft_lstnew(int nb);
void	end(t_data *data);
void	freeable(char **tab);
void	c_error(t_data *data);
void	free_all(t_data *data);
void	ft_add_back(t_nbr **stack, t_nbr *elem);
void	ft_add_front(t_nbr **stack, t_nbr *elem);
void	ft_lstclear(t_nbr **stack);
long int	ft_atoi(char *str);
void	*ft_calloc(int size);
void	push_swap(t_data *data, char **av, int ac);
void	ft_init(t_data *data, char **av, int ac);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data, int x);
void	sb(t_data *data, int x);
void	ss(t_data *data);
void	ra(t_data *data, int x);
void	rb(t_data *data, int x);
void	rr(t_data *data);
void	rra(t_data *data, int x);
void	rrb(t_data *data, int x);
void	rrr(t_data *data);
void	radix_sort(t_data *data);
void	quick_sort(t_data *data);
void	bubble_sort(t_data *data);
#endif
