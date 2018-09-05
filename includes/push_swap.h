/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 07:29:03 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/06 07:29:06 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_
# include "stack.h"
# include "get_next_line.h"
# define MAX_INT 2147483647
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			v;
	int			c;
	int			offset;
}				t_flags;

typedef struct	s_rank
{
	int			val;
	int			pos_a;
	int			pos_b;
	int			dir_a;
	int			dir_b;
	int			mov_a;
	int			mov_b;
}				t_rank;

void			swap_a(t_stack *a);
void			swap_b(t_stack *b);
void			swap_s(t_stack *a, t_stack *b);
void			push_a(t_stack *a, t_stack *b);
void			push_b(t_stack *a, t_stack *b);
void			rotate_a(t_stack *a);
void			rotate_b(t_stack *b);
void			rotate_r(t_stack *a, t_stack *b);
void			revrotate_a(t_stack *a);
void			revrotate_b(t_stack *b);
void			revrotate_r(t_stack *a, t_stack *b);
void			print_stacks(t_stack *a, t_stack *b, char *str);
void			print_stacks_clr(t_stack *a, t_stack *b, char *str);
void			print_single(char const *colour, t_list *head, int value);
void			print_rest(t_list *head_a, t_list *head_b, t_list *aterm, t_list *bterm);
int				rotate_print(t_list *head_a, t_list *head_b, char *str);
int				is_valid(int ac, char *av[]);
int				is_sorted(t_list *head);
int				is_sorted_desc(t_list *head);
void			set_swap_colour(char colour[4][8], char *str);
void			set_rotate_colour(char colour[4][8], char *str);
t_list			*stack_min(t_stack *s);
t_list			*stack_minnext(t_stack *s, t_list *min);
t_list			*stack_maxnext(t_stack *s, t_list *max);
t_list			*stack_max(t_stack *s);
void			swapnfree(char **var, char *new_val);
char			*algo3(t_stack *a, t_stack *b);
char			*algo5(t_stack *a, t_stack *b);
char			*algo5_help(t_stack *a, t_stack *b);
int				char_count(const char *s, char c);
void			contains_flags(int ac, char **av, t_flags *flags);
void			flag_check(t_flags *flag);
void			test_2_sizeof3(char **ret, t_stack *a);
void			free_split(char **arr);
int				get_position(t_stack *b, t_list *elem);
void			apply_rota(t_stack *a, char **ret, int search, int dir);
void			apply_rotb(t_stack *b, char **ret, t_rank *rank, int count);
void			apply_rotr(t_stack *a, t_stack *b, t_rank *rank, char **ret);
void			apply_revrotr(t_stack *a, t_stack *b, t_rank *rank, char **ret);
void			final_rotates(t_stack *b, char **ret);
void			r_p_help2(t_list *head_a, t_list *head_b, char colour[4][8]);
#endif
