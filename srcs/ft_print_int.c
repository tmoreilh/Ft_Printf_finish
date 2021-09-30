#include "../ft_printf.h"

void	print_int(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left = 1;
	}
	if (flags->left == 0)
		print_int_right(flags);
	else if (flags->left == 1)
		print_int_left(flags);
}

void	print_int_right(t_flags *flags)
{
	long	j;

	j = va_arg(flags->args, int);
	flags->len = nbrlen(j);
	if (j < 0)
		flags->minus = 1;
	if ((flags->width >= flags->len) && (flags->width != flags->prec))
		print_int_small_len(j, flags);
	if (j < 0 && flags->pad == 0 && flags->exception != 2)
		ft_putchar('-', flags);
	if ((flags->pad == 1) && (flags->dot == 1) && (j < 0)
		&& (flags->width >= flags->len) && flags->exception != 2)
	{
		ft_putchar('-', flags);
		if (flags->width > flags->len && flags->minus == 0 && flags->prec != 0)
			ft_printzero(flags->width - flags->len, flags);
		flags->exception = 1;
	}
	if (flags->pad == 1 && j < 0 && flags->exception == 0)
		ft_putchar('-', flags);
	if (flags->prec - flags->len > 0)
		ft_printzero(flags->prec - flags->len, flags);
	if (!(flags->dot == 1 && flags->prec == 0 && j == 0))
		ft_putnbr(j, flags);
}

void	print_int_left(t_flags *flags)
{
	long	j;

	j = va_arg(flags->args, int);
	flags->len = nbrlen(j);
	print_int_left_prec_check(j, flags);
	if (flags->width < flags->prec)
		ft_printspace(flags->width - flags->precmin - flags->len, flags);
	else if ((flags->width > flags->prec) && (flags->dot > flags->prec))
	{
		if (j == 0 && flags->prec == 0)
			ft_printspace(flags->width, flags);
		else if (j == 0 && flags->prec != 0)
			ft_printspace(flags->width - flags->len, flags);
		else if (flags->width > flags->len)
			ft_printspace(flags->width - flags->len - flags->minus, flags);
		else if (flags->width > flags->len && flags->prec >= 0)
			ft_printspace(flags->width, flags);
	}
	else if ((flags->width > flags->prec) && (flags->prec < flags->len))
		ft_printspace(flags->width - flags->minus - flags->len, flags);
	else
		ft_printspace(flags->width - flags->minus - flags->prec, flags);
}
