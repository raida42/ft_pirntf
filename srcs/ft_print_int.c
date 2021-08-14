/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 18:59:49 by raida             #+#    #+#             */
/*   Updated: 2021/07/08 22:33:20 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_check_right_int(t_print *tab, int len)
{
	int	width;
	int	prc;

	if (!tab->dash)
		return ;
	width = tab->wdt;
	prc = tab->prc;
	if (tab->sp || tab->sign)
		width--;
	while (len < width && prc < width--)
		tab->tlen += write(1, " ", 1);
}

void	ft_check_left_int_dash(t_print *tab, int len)
{
	int	prc;

	prc = tab->prc;
	if (tab->sp)
		tab->tlen += write(1, " ", 1);
	if (tab->sign)
	{
		if (tab->sign < 0)
			tab->tlen += write(1, "-", 1);
		if (0 < tab->sign)
			tab->tlen += write(1, "+", 1);
	}
	while (0 <= prc && len < prc--)
		tab->tlen += write(1, "0", 1);
}

void	ft_check_left_int_nodash(t_print *tab, int len)
{
	int	width;
	int	prc;

	width = tab->wdt;
	prc = tab->prc;
	if (tab->sp || tab->sign)
		width--;
	if (tab->sp)
		tab->tlen += write(1, " ", 1);
	while (!tab->zero && len < width && prc < width--)
		tab->tlen += write(1, " ", 1);
	if (tab->sign)
	{
		if (tab->sign < 0)
			tab->tlen += write(1, "-", 1);
		if (0 < tab->sign)
			tab->tlen += write(1, "+", 1);
	}
	while ((tab->zero && len < width--) || (0 <= prc && len < prc--))
		tab->tlen += write(1, "0", 1);
}

void	ft_check_left_int(t_print *tab, size_t len)
{
	if (tab->prc != -1)
		tab->zero = 0;
	if (tab->sign)
		tab->sp = 0;
	if (!tab->dash)
		ft_check_left_int_nodash(tab, len);
	if (tab->dash)
		ft_check_left_int_dash(tab, len);
}

void	ft_print_int(t_print *tab)
{
	int		di;
	char	*put;
	char	*tmp;
	size_t	len;

	di = va_arg(tab->args, int);
	if (di == 0 && tab->prc == 0)
	{
		while ((tab->wdt)--)
			tab->tlen += write(1, " ", 1);
		return ;
	}
	if (di < 0)
	{
		tab->sign = -1;
		di *= -1;
	}
	put = ft_itoa(di);
	len = ft_strlen(put);
	ft_check_left_int(tab, len);
	tmp = put;
	while (*put)
		tab->tlen += write(1, &(*put++), 1);
	free(tmp);
	ft_check_right_int(tab, len);
}
