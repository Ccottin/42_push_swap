#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_nbr {
	int		nb;
	int		ord;
	int		tp_ord;
	char		*bin;
	struct s_nbr	*next;
}			t_nbr;

typedef struct s_algo {
	int	nb_move;
	char	*move;
}		t_algo;

typedef struct s_data {
	int	total;
	char	**tab;
	t_nbr	*stack_a;
	t_nbr	*stack_b;
	t_algo	temp;
	t_algo	bubble;
	t_algo	radix;
	t_algo	truc;
	t_algo	small;
}		t_data;


int	ft_strlen(char *str);
int	ft_lstlen(t_nbr *list);
int	check_sorted(t_nbr *stack);
int	check_sorted_2(t_nbr *stack);
int	ultimate_check_sorted(t_data *data);
int	check_arg(char **av, int m);
long int	ft_atoi(char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
char	*stock_move(t_data *data, char *move);
t_nbr	*ft_lstnew(int nb);
void	end(t_data *data);
void	freeable(char **tab);
void	c_error(t_data *data);
void	free_all(t_data *data);
void	free_bean(t_nbr *stack);
void	ft_add_back(t_nbr **stack, t_nbr *elem);
void	ft_add_front(t_nbr **stack, t_nbr *elem);
void	ft_lstclear(t_nbr **stack);
void	*ft_calloc(int size);
void	push_swap(t_data *data, char **av, int ac);
void	ft_init(t_data *data, char **av, int ac);
void	init_stack_a(t_data *data, char **av, int ac);
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
void	bubble_sort(t_data *data);
void	truc(t_data *data);
int	find_biggest(t_nbr *stack);
int	find_smallest(t_nbr *stack);
int	count_move(t_nbr *stack, int rank);
void	sort_3(t_data *data);
void	sort_4(t_data *data);
void	sort_5(t_data *data);
void	sort_6(t_data *data);
void	get_temp_ord(t_nbr *stack);

#endif
