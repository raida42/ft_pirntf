/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:58:56 by raida             #+#    #+#             */
/*   Updated: 2021/07/10 14:14:03 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_reset_tab(t_print *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->sp = 0;
	tab->shrp = 0;
	tab->wdt = 0;
	tab->prc = -1;
	tab->sign = 0;
}

void	ft_initialize_tab(t_print *tab)
{
	tab->dash = 0;
	tab->zero = 0;
	tab->sp = 0;
	tab->shrp = 0;
	tab->wdt = 0;
	tab->prc = -1;
	tab->sign = 0;
	tab->tlen = 0;
}

int	ft_check_fmt(t_print *tab, const char *fmt)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i = ft_eval_fmt(tab, fmt, i + 1);
			if (i == -1)
				return (-1);
			if (i == 0 || !fmt[i])
				break ;
		}
		else
			ret += write(1, &fmt[i], 1);
		i++;
	}
	ret += tab->tlen;
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	t_print	tab;
	int		ret;

	ft_initialize_tab(&tab);
	va_start(tab.args, fmt);
	ret = ft_check_fmt(&tab, fmt);
	va_end(tab.args);
	return (ret);
}
