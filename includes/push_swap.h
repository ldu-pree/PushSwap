/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:55:17 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/08/19 14:55:18 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
/*
# define COLOUR_RED "\e[31m"
# define COLOUR_GREEN "\e[32m"
# define COLOUR_ORANGE "\e[33m"
# define COLOUR_BLUE "\e[34m"
# define COLOUR_MAGENTA "\e[35m"
# define COLOUR_CYAN "\e[36m"
# define COLOUR_GREY "\e[90m"
# define COLOUR_YELLOW "\e[93m"
# define COLOUR_END "\e[0m"
*/

typedef struct      s_stack
{
    int             value;
    struct s_stack  *next;
}                   t_stack;

// do_push.c

void        push_a(t_stack **head_b, t_stack **head_a);
void        push_b(t_stack **head_b, t_stack **head_a);

// do_swap.c

void        ft_swap(t_stack **head);
void        swap_a(t_stack **head);
void        swap_b(t_stack **head);
void        swap_both(t_stack **head_a, t_stack **head_b);

// do_rotate.c

void	    ft_rotate(t_stack **head);
void	    rotate_a(t_stack **head);
void    	rotate_b(t_stack **head);
void	    rotate_both(t_stack **head_a, t_stack **head_b);

// do_reverse_rotate.c

void	    ft_rev_rotate(t_stack **head);
void	    rev_rotate_a(t_stack **head);
void	    rev_rotate_b(t_stack **head);
void	    rev_rotate_both(t_stack **head_a, t_stack **head_b);

// error.c

void	    ft_error(void);
int		    check_num(int argc, char **argv);
int		    bigger_int(int argc, char **argv);
int		    check_dup(int argc, char **argv);



// checker_instruct.c

int		    correct_phrase(char *op);
void	    do_cmd(int cmd, t_stack **a, t_stack **b);

// checker_flags.c

int		    check_visual(char **argv);
void	    del_argv(int argc, char **argv);

// checker_commands.c

void	    do_pa(t_stack **head_b, t_stack **head_a);
void	    do_pb(t_stack **head_b, t_stack **head_a);
void	    do_ss_ch(t_stack **head_b, t_stack **head_a);
void	    do_rr(t_stack **head_a, t_stack **head_b);
void	    do_rrr(t_stack **head_a, t_stack **head_b);

// utilities.c

void	    clean(t_stack *head);
t_stack	    *stnew(int num);
void	    stiter(t_stack *stack, void (*f)(t_stack *elem));
void	    print_a(t_stack **a, int num);
void	    print_b(t_stack **b, int num);
void	    print_all(t_stack **a, t_stack **b);

// position.c

int	        get_num(t_stack *head, int index);
int	        get_check_pos(t_stack *head, int num, int index);
int	        negative(int head, int num);
int	        positive(int head, int num);
int	        get_closest(t_stack *head, int num);

// move_position.c

int		    f_steps_ab(t_stack *head, int num, int *type);
void	    f_move_to_a(t_stack **a, t_stack **b, int num);
void	    do_ss(t_stack **a, t_stack **b, int count, int type);
void	    f_move_stack_a(t_stack **head, int type, int count);
int		    get_pos_in_a(t_stack *head, int num);

// move_position_2.c

void	    f_move_stack_b(t_stack **head, int type, int count);
int		    f_mix_steps(int sa, int sb);
void	    do_ab_steps(t_stack **a, t_stack **b, int num);
int	    	b_mix_steps(t_stack *head_a, t_stack *head_b);
void    	f_move_ab(t_stack **a, t_stack **b);

// solver.c

int		    get_steps(t_stack *head, int num);
int	    	get_steps_ab(t_stack *head, int num, int *type);
int	    	f_ab_steps(t_stack *a, t_stack *b, int num);
int	    	mix_steps(t_stack *head_a, t_stack *head_b);
void	    solve(t_stack **head_a, t_stack **head_b);

//solver_2.c

int		    get_min(t_stack *a);
int	    	get_steps_begin(t_stack *head, int index, int *type);
void    	beginning(t_stack **a);
int	    	is_sorted(t_stack *head);
void    	solve_mini(t_stack **a);

// represent_stack.c

void	    print_stack(t_stack *stack, t_stack *stack_b);
int		    len_stack(t_stack *head);
t_stack	    *create_stack_from_arg(int argc, char **argv, int flag);
t_stack	    *load_stack(int argc, char **argv);
t_stack	    *create_stack(int argc, char **argv, int type);

// checker_main.c

int         read_cmd(t_stack **a, t_stack **b, char **cmd);
void	    if_three(int argc, char **argv);
void	    check_in(int argc, char **argv, int *flag);
void    	sorted_check(t_stack *a, t_stack *b);

//

#endif