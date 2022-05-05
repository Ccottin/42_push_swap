/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:20:41 by ccottin           #+#    #+#             */
/*   Updated: 2022/05/05 18:20:43 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_nbr {
	int				nb;
	int				ord;
	int				tp_ord;
	char			*bin;
	struct s_nbr	*next;
}			t_nbr;

typedef struct s_algo {
	int		nb_move;
	char	*move;
}		t_algo;

typedef struct s_data {
	int		total;
	char	**tab;
	t_nbr	*stack_a;
	t_nbr	*stack_b;
	t_algo	temp;
	t_algo	bubble;
	t_algo	radix;
	t_algo	truc;
	t_algo	small;
}		t_data;

/*____utils____*/
long int	ft_atoi(char *str);
int			ft_strlen(char *str);
int			ft_strncmp(char *s1, char *s2);
void		*ft_calloc(int size);
char		**ft_split(char *s, char c);
char		*ft_strdup(char *s);

/*____init_____*/
void		push_swap(t_data *data, char **av, int ac);
void		ft_init(t_data *data, char **av, int ac);
void		init_stack_a(t_data *data, char **av, int ac);

/*_____end_____*/
void		end(t_data *data);
void		freeable(char **tab);
void		c_error(t_data *data);
void		free_all(t_data *data);
void		free_bean(t_nbr *stack);
void		error(int err, t_nbr *stack_a);

/*_____lst_____*/
t_nbr		*ft_lstnew(int nb);
int			ft_lstlen(t_nbr *list);
void		ft_lstclear(t_nbr **stack);
void		ft_add_back(t_nbr **stack, t_nbr *elem);
void		ft_add_front(t_nbr **stack, t_nbr *elem);

/*__algo_utils__*/
char		*stock_move(t_data *data, char *move);
t_nbr		*find_small(t_nbr *stack, int small);
void		get_bin(t_data *data);
void		get_temp_ord(t_nbr *stack);
int			check_sorted(t_nbr *stack);
int			find_biggest(t_nbr *stack);
int			find_smallest(t_nbr *stack);
int			check_arg(char **av, int m);
int			check_sorted_2(t_nbr *stack);
int			count_move(t_nbr *stack, int rank);
int			ultimate_check_sorted(t_data *data);

/*_____cmd_____*/
void		pa(t_data *data);
void		pb(t_data *data);
void		sa(t_data *data, int x);
void		sb(t_data *data, int x);
void		ss(t_data *data);
void		ra(t_data *data, int x);
void		rb(t_data *data, int x);
void		rr(t_data *data);
void		rra(t_data *data, int x);
void		rrb(t_data *data, int x);
void		rrr(t_data *data);

/*_____algo____*/
void		truc(t_data *data);
void		sort_3(t_data *data);
void		sort_4(t_data *data);
void		sort_5(t_data *data);
void		sort_6(t_data *data);
void		radix_sort(t_data *data);
void		bubble_sort(t_data *data);

/*_____truc____*/
void		check_ss(t_data *data);
void		phase_six(t_data *data);
void		put_biggest(t_data *data);
int			sorted(t_nbr *stack);
int			get_last(t_nbr *stack);
int			get_s_last(t_nbr *stack);
int			do_rb(t_data *data, int big);
int			do_rrb(t_data *data, int big);
int			do_ra(t_data *data, int small);
int			do_rra(t_data *data, int small);
int			check_still_nb(t_nbr *stack, int max);

#endif
