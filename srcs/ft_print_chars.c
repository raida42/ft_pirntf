/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:36:52 by raida             #+#    #+#             */
/*   Updated: 2021/07/09 19:13:00 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_check_left_chars(t_print *tab, int len)
{
	int	width;

	width = tab->wdt;
	if (len < width && !tab->zero)
		while (len < width--)
			tab->tlen += write(1, " ", 1);
	if (len < width && tab->zero)
		while (len < width--)
			tab->tlen += write(1, "0", 1);
}

void	ft_check_right_chars(t_print *tab, int len)
{
	int	width;

	width = tab->wdt;
	if (len < width)
		while (len < width--)
			tab->tlen += write(1, " ", 1);
}

void	ft_print_char(t_print *tab)
{
	unsigned char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !tab->dash)
		ft_check_left_chars(tab, 1);
	tab->tlen += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_check_right_chars(tab, 1);
}

void	ft_print_string(t_print *tab)
{
	char	*str;
	size_t	slen;
	size_t	plen;

	str = va_arg(tab->args, char *);
	if (!str)
		str = "(null)";
	slen = ft_strlen(str);
	plen = tab->prc;
	if (0 <= plen && plen <= slen)
		slen = plen;
	if (tab->wdt && !tab->dash)
		ft_check_left_chars(tab, slen);
	while (*str && plen--)
		tab->tlen += write(1, &(*str++), 1);
	if (tab->wdt && tab->dash)
		ft_check_right_chars(tab, slen);
}
