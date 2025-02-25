/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prichugh <prichugh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 12:16:54 by prichugh          #+#    #+#             */
/*   Updated: 2024/07/07 12:16:54 by prichugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_s;

typedef struct s_top_and_bot
{
	int	top_a;
	int	top_b;
	int	bot_a;
	int	bot_b;
}	t_distance;

int		validate_int_range(char *nbr, int *values);
int		int_range(char *split_args);
void	initialize_stack(char **args, t_s **stack_a, int argc);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_args(char **args);
int		main(int argc, char *argv[]);
void	error_msg(void);
t_s		*set_new_node(long content);
int		top_or_bottom_cont(int top_a, int bot_a, int top_b, int bot_b);
void	append(t_s **stack, t_s *new_node);
void	sa(t_s **stack);
void	sb(t_s **stack);
void	ss(t_s **stack_a, t_s **stack_b);
void	pb(t_s **stack_a, t_s **stack_b);
void	pb_cont(t_s *top_a, t_s *top_b, t_s **stack_b);
void	pa(t_s **stack_a, t_s **stack_b);
void	pa_cont(t_s *top_b, t_s *top_a, t_s **stack_b);
void	ra(t_s **stack_a);
void	rb(t_s **stack_b);
void	rr(t_s **stack_a, t_s **stack_b);
void	rra(t_s **stack_a);
void	rrb(t_s **stack_b);
void	rrr(t_s **stack_a, t_s **stack_b);
int		is_max(t_s *node, t_s *stack);
int		is_min(t_s *node, t_s *stack);
t_s		*max_node(t_s *stack);
t_s		*min_node(t_s *stack);
int		count_nodes(t_s *stack);
int		node_index(t_s *node, t_s *stack);
int		node_index_reverse(t_s *node, t_s *stack);
t_s		*find_correct_spot(t_s *node, t_s *stack);
t_s		*find_correct_spot_in_a(t_s *node, t_s *stack);
int		top_or_bottom(t_s *curr, t_s *stack_a, t_s *corr, t_s *stack_b);
int		top_or_bottom_per_stack(t_s *node, t_s *stack);
int		number_of_moves(t_s *current, t_s *stack_a, t_s *correct, t_s *stack_b);
int		number_of_moves_cont(t_distance *d, int torb);
t_s		*find_cheapest_to_push(t_s *stack_a, t_s *stack_b);
int		moves_per_stack(t_s *node, t_s *stack);
void	move_cheapest(t_s *chpst, t_s **st_a, t_s *cor, t_s **st_b);
void	move_cheapest_cont2(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b);
void	move_cheapest_cont3(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b);
void	move_cheapest_cont4(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b);
void	move_cheapest_cont5(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b);
void	move_cheapest_cont6(t_s *ch, t_s **st_a, t_s *cor, t_s **st_b);
void	sort_three_numbers(t_s **stack);
void	sort_stack_algorithm_cont(t_s **stack_a, t_s **stack_b);
void	sort_stack_algorithm(t_s **stack_a, t_s **stack_b);
int		is_duplicate(t_s *new_node, t_s **stack);
int		is_digit(char c);
int		is_numeric(const char *str);
int		ft_atoi2(const char *str, char **arg, t_s *stack, int argc);
void	free_stack(t_s *stack);
void	rotate_min_to_top(t_s **stack);
char	**get_args(int argc, char *argv[]);
int		check_sorted(t_s *stack_a);
int		duplicate(char **args);
int		ft_strcmp(char *s1, char *s2);

#endif
