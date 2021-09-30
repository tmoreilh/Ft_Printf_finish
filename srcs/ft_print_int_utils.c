#include "../ft_printf.h"

void	print_int_small_len_small_prec(long j, t_flags *flags)
{
	if (j == 0 && flags->prec == 0)
		ft_printspace(flags->width, flags);
	else if (j == 0 && flags->prec != 0 && flags->pad == 0)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->pad == 1 && flags->prec < 0 && flags->width > flags->len
		&& j < 0)
	{
		ft_putchar('-', flags);
		ft_printzero(flags->width - flags->len - flags->minus, flags);
		flags->exception = 2;
		return ;
	}		
	else if (flags->width > flags->len && flags->minus == 0
		&& flags->pad == 1 && flags->prec != 0)
		ft_printzero(flags->width - flags->len, flags);
	else if (flags->width > flags->len)
		ft_printspace(flags->width - flags->len - flags->minus, flags);
	else if (flags->width > flags->len && flags->prec >= 0)
		ft_printspace(flags->width, flags);
}

void	print_int_small_len(long j, t_flags *flags)
{
	flags->precmin = flags->prec + flags->minus;
	if ((flags->pad == 1) && (flags->dot == 0))
	{
		if (flags->pad == 1 && j < 0)
			ft_putchar('-', flags);
		ft_printzero(flags->width - (flags->precmin + flags->len), flags);
	}
	else if (flags->width < flags->prec)
		ft_printspace(flags->width - flags->precmin - flags->len, flags);
	else if ((flags->width > flags->prec) && (flags->dot > flags->prec))
		print_int_small_len_small_prec(j, flags);
	else if ((flags->width > flags->prec) && (flags->prec < flags->len))
		ft_printspace(flags->width - flags->minus - flags->len, flags);
	else
		ft_printspace(flags->width - flags->minus - flags->prec, flags);
	if (flags->exception != 2)
		flags->exception = 1;
}

void	print_int_left_prec_check(long j, t_flags *flags)
{
	if (j < 0)
	{
		ft_putchar('-', flags);
		flags->minus = 1;
	}
	flags->precmin = flags->prec + flags->minus;
	if (flags->prec > flags->len)
		ft_printzero(flags->prec - flags->len, flags);
	if (!(flags->dot == 1 && flags->prec == 0 && j == 0))
		ft_putnbr(j, flags);
}
