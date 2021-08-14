/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:05:16 by raida             #+#    #+#             */
/*   Updated: 2021/07/10 17:16:42 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_eval_flag(t_print *tab, const char *fmt, int i, char c)
{
	if (c == '-')
		tab->dash = 1;
	if (c == '0')
		tab->zero = 1;
	if (c == '#')
		tab->shrp = 1;
	if (c == ' ')
		tab->sp = 1;
	if (c == '+')
		tab->sign = 1;
	i++;
	while (fmt[i] == c)
		i++;
	return (i);
}

int	ft_eval_width(t_print *tab, const char *fmt, int i)
{
	if (tab->wdt && (ft_isdigit(fmt[i]) || fmt[i] == '*'))
		tab->wdt = 0;
	while (ft_isdigit(fmt[i]))
	{
		tab->wdt = tab->wdt * 10 + (fmt[i] - '0');
		i++;
	}
	if (fmt[i] == '*')
	{
		tab->wdt = va_arg(tab->args, int);
		if (tab->wdt <= -INT_MAX || INT_MAX <= tab->wdt)
			return (-1);
		if (tab->wdt < 0)
		{
			tab->dash = 1;
			tab->wdt *= -1;
			tab->zero = 0;
		}
		i++;
	}
	return (i);
}

int	ft_eval_precision(t_print *tab, const char *fmt, int i)
{
	int	flag;

	i++;
	flag = i;
	tab->prc = 0;
	while (ft_isdigit(fmt[i]))
	{
		tab->prc = tab->prc * 10 + (fmt[i] - '0');
		i++;
	}
	if (fmt[i] == '*' && flag == i)
	{
		tab->prc = va_arg(tab->args, int);
		if (tab->prc < 0)
			tab->prc = -1;
		i++;
	}
	return (i);
}
