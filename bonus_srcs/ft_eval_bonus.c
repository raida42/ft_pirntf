/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:30:40 by raida             #+#    #+#             */
/*   Updated: 2021/07/10 17:43:24 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_print_unique(t_print *tab, const char *fmt, int i)
{
	while (ft_strchr("-# +0*.'hjlqtzL", fmt[i]) || ft_isdigit(fmt[i]))
	{
		if (ft_strchr("-0*.", fmt[i]) || ft_isdigit(fmt[i]))
		{
			i = ft_eval_flags(tab, fmt, i);
			continue ;
		}
		i++;
	}
	if (fmt[i])
	{
		if (!tab->dash && tab->wdt)
			ft_check_left_chars(tab, 1);
		tab->tlen += write(1, &fmt[i++], 1);
		if (tab->dash && tab->wdt)
			ft_check_right_chars(tab, 1);
		while (fmt[i])
			tab->tlen += write(1, &fmt[i++], 1);
	}
	return (i);
}

int	ft_eval_specifier(t_print *tab, const char *fmt, int i)
{
	if (i == -1)
		return (i);
	if (fmt[i] == 'c')
		ft_print_char(tab);
	if (fmt[i] == 's')
		ft_print_string(tab);
	if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_int(tab);
	if (fmt[i] == 'u')
		ft_print_unsigned_int(tab);
	if (fmt[i] == 'p')
		ft_print_pointer(tab);
	if (fmt[i] == 'x' || fmt[i] == 'X')
		ft_print_hexa_int(tab, fmt[i]);
	if (fmt[i] == '%')
		ft_print_percent(tab);
	if (!ft_strchr("csdiupxX%", fmt[i]))
	{
		i = ft_print_unique(tab, fmt, i);
		if (tab->tlen == 0)
			return (0);
	}
	return (i);
}

int	ft_eval_flags(t_print *tab, const char *fmt, int i)
{
	while (ft_strchr("-# +0*.", fmt[i]) || ft_isdigit(fmt[i]))
	{
		if (fmt[i] == '-')
			i = ft_eval_flag(tab, fmt, i, fmt[i]);
		if (fmt[i] == '#')
			i = ft_eval_flag(tab, fmt, i, fmt[i]);
		if (fmt[i] == ' ')
			i = ft_eval_flag(tab, fmt, i, fmt[i]);
		if (fmt[i] == '+')
			i = ft_eval_flag(tab, fmt, i, fmt[i]);
		if (fmt[i] == '0')
			i = ft_eval_flag(tab, fmt, i, fmt[i]);
		if (ft_isdigit(fmt[i]) || fmt[i] == '*')
			i = ft_eval_width(tab, fmt, i);
		if (fmt[i] == '.')
			i = ft_eval_precision(tab, fmt, i);
		if (i == -1)
			return (-1);
	}
	return (i);
}

int	ft_eval_fmt(t_print *tab, const char *fmt, int i)
{
	i = ft_eval_flags(tab, fmt, i);
	i = ft_eval_specifier(tab, fmt, i);
	ft_reset_tab(tab);
	return (i);
}
