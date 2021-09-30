#include "../ft_printf.h"

void	print_unsignedint(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left = 1;
	}
	if (flags->prec < 0)
	{
		flags->prec = 0;
		flags->dot = 0;
	}
	if (flags->left == 0)
		print_unsignedint_right(flags);
	else if (flags->left == 1)
		print_unsignedint_left(flags);
}

void	print_unsignedint_small_len(int j, t_flags *flags)
{
	if ((flags->pad == 1) && (flags->dot == 0))
		ft_printzero(flags->width - (flags->prec + flags->len), flags);
	else if (flags->width < flags->prec)
		ft_printspace(flags->width - flags->prec - flags->len, flags);
	else if ((flags->width > flags->prec) && (flags->prec < flags->len)
		&& (j != 0))
		ft_printspace(flags->width - flags->len, flags);
	else if (j == 0 && flags->dot == 0)
		ft_printspace(flags->width - flags->len, flags);
	else if ((flags->width > flags->len && flags->exception == 1) || j == 0)
		ft_printspace(flags->width - flags->prec, flags);
	else if (flags->exception == 1 && flags->width > flags->len)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->width > flags->prec)
		ft_printspace(flags->width - flags->prec, flags);
}

void	print_unsignedint_prec_handler(unsigned int j, t_flags *flags)
{
	flags->len = nbrlen(j);
	if (flags->prec == 0 && flags->dot == 1)
		flags->exception = 1;
	if (flags->prec > flags->len)
		ft_printzero(flags->prec - flags->len, flags);
}

void	print_unsignedint_right(t_flags *flags)
{
	unsigned int	j;

	j = va_arg(flags->args, unsigned int);
	flags->len = nbrlen(j);
	if (flags->prec == 0 && flags->dot == 1)
		flags->exception = 1;
	if ((flags->width > flags->len) && (flags->width != flags->prec))
		print_unsignedint_small_len(j, flags);
	if (flags->width == flags->len && j == 0 && flags->exception == 1)
		ft_printspace(flags->width, flags);
	if (flags->prec - flags->len > 0)
		ft_printzero(flags->prec - flags->len, flags);
	if (!(flags->dot == 1 && flags->prec == 0) || j != 0)
		ft_putnbr(j, flags);
}

void	print_unsignedint_left(t_flags *flags)
{
	unsigned int	j;

	j = va_arg(flags->args, unsigned int);
	print_unsignedint_prec_handler(j, flags);
	if (!(flags->dot == 1 && flags->prec == 0) || j != 0)
		ft_putnbr(j, flags);
	if (flags->width == flags->len && j == 0 && flags->exception == 1)
		ft_printspace(flags->width, flags);
	if (flags->width < flags->prec)
		ft_printspace(flags->width - flags->prec - flags->len, flags);
	else if ((flags->width > flags->prec) && (flags->prec < flags->len)
		&& j != 0)
		ft_printspace(flags->width - flags->len, flags);
	else if (j == 0 && flags->dot == 0)
		ft_printspace(flags->width - flags->len, flags);
	else if ((flags->width > flags->len && j == 0) && !(flags->exception == 1))
		ft_printspace(flags->width - flags->prec, flags);
	else if (flags->exception == 1 && flags->width > flags->len && j == 0)
		ft_printspace(flags->width, flags);
	else if (flags->exception == 1 && flags->width > flags->len)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->width > flags->prec && j != 0)
		ft_printspace(flags->width - flags->prec, flags);
}
