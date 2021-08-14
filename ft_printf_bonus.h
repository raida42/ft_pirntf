/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:38:09 by raida             #+#    #+#             */
/*   Updated: 2021/07/10 17:44:14 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_print
{
	int		dash;
	int		zero;
	int		sp;
	int		shrp;
	int		wdt;
	int		prc;
	int		sign;
	int		tlen;
	va_list	args;
}		t_print;

int		ft_printf(const char *fmt, ...);
int		ft_eval_fmt(t_print *tab, const char *fmt, int i);

int		ft_eval_modifier(t_print *tab, const char *fmt, int i);
int		ft_eval_specifier(t_print *tab, const char *fmt, int i);
int		ft_eval_flag(t_print *tab, const char *fmt, int i, char c);
int		ft_eval_flags(t_print *tab, const char *fmt, int i);
int		ft_eval_width(t_print *tab, const char *fmt, int i);
int		ft_eval_precision(t_print *tab, const char *fmt, int i);

void	ft_print_char(t_print *tab);
void	ft_print_string(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_unsigned_int(t_print *tab);
void	ft_print_pointer(t_print *tab);
void	ft_print_hexa_int(t_print *tab, char c);
void	ft_print_percent(t_print *tab);
void	ft_initialize_tab(t_print *tab);
void	ft_reset_tab(t_print *tab);

int		ft_isdigit(int c);
int		ft_strchr(const char *str, char c);
char	*ft_itoa(unsigned int n);
size_t	ft_strlen(const char *s);

void	ft_check_left_chars(t_print *tab, int len);
void	ft_check_right_chars(t_print *tab, int len);

#endif