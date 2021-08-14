/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 23:09:27 by raida             #+#    #+#             */
/*   Updated: 2021/07/08 22:31:32 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

void	ft_print_percent(t_print *tab)
{
	int	width;

	width = tab->wdt;
	if (!tab->dash && tab->zero)
		while (width-- > 1)
			tab->tlen += write(1, "0", 1);
	if (!tab->dash && !tab->zero)
		while (width-- > 1)
			tab->tlen += write(1, " ", 1);
	tab->tlen += write(1, "%", 1);
	if (tab->dash)
		while (width-- > 1)
			tab->tlen += write(1, " ", 1);
}
