/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:16:53 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/13 21:01:35 by pmila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <libft.h>

typedef struct			s_flags
{
	int zero;
	int minus;
	int plus;
	int grill;
	int dote;
	int space;
	int min_width;
	int cut;
	int h;
	int hh;
	int l;
	int ll;
	int cap_l;
}						t_flags;

typedef struct			s_ldouble
{
	unsigned long	mant;
	char			sign;
	char			pos_p;
	int				exp;
	unsigned int	exp_2;
}						t_ld;

typedef union			u_un
{
	long double	num;
	char		ar[sizeof(long double)];
}						t_un;

int						ft_printf(const char *format, ...);
int						ft_fprintf(char *file, const char *format, ...);
char					read_flags(const char *f, va_list *argv, int i);
int						clear_flags(void);
int						put_persent_and_space(int i);
int						check_double_percents(const char *format, int i);
void					choose_spec(char spec, va_list *argv);
void					ft_putcharf(char c);
void					ft_putcharsf(char c, int n);
void					ft_putstrf(const char *s);
int						print_xxo(unsigned long long int nbr, char ns);
int						print_di(long long int nbr);
int						print_u(unsigned long long int nbr);
void					print_t(char **arr);
void					print_y(char ***arr);
int						print_s(char *str, int flag);
int						print_c(char c);
long long int			convert_d(va_list *argv);
unsigned long long int	convert_u(va_list *argv);
long double				convert_f(va_list *argv);
void					print_lf(long double num);
void					add_cut(char **snbr);
void					infin_mult(char **m1, char *m2);
void					handle_integer(char **result, int i, char *str);
int						round_last(char *str, int k);
void					check_round(char **str, int j);
int						is_num_valid(t_ld *l_info, char **str);
void					handle_decoded(t_ld *l_info, char **str,
						int *final_degr);
void					print_f(char **str, t_un g_u);
void					add_cut(char **snbr);

t_flags					*g_flags;
int						g_iter;
int						g_giter;
int						g_fd;
#endif
