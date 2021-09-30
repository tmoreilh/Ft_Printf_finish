#include "../ft_printf.h"

void	print_percent(t_flags *flags)
{
	if (flags->left == 0)
	{
		if (flags->pad == 0)
			ft_printspace(flags->width - 1, flags);
		if (flags->pad == 1)
			ft_printzero(flags->width - 1, flags);
		ft_putchar('%', flags);
	}
	else
	{
		ft_putchar('%', flags);
		ft_printspace(flags->width - 1, flags);
	}
}
