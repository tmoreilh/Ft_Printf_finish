#include "../ft_printf.h"

void	print_pointer(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left = 1;
	}
	if (flags->left == 0)
		print_pointer_right(flags);
	else if (flags->left == 1)
		print_pointer_left(flags);
}

void	print_pointer_right(t_flags *flags)
{
	unsigned long long	i;

	i = va_arg(flags->args, unsigned long);
	flags->len = ft_lnbr_len(i, "0123456789abcdef");
	if (flags->dot == 1 && i == 0)
		flags->len = 0;
	if (flags->width > flags->len)
		ft_printspace(flags->width - (flags->len + 2), flags);
	ft_putchar('0', flags);
	ft_putchar('x', flags);
	ft_put_lnbr_base_long(i, "0123456789abcdef", flags);
}

void	print_pointer_left(t_flags *flags)
{
	unsigned long	i;

	i = va_arg(flags->args, unsigned long);
	flags->len = ft_lnbr_len(i, "0123456789abcdef");
	if (i == 0)
		flags->len = 1;
	ft_putchar('0', flags);
	ft_putchar('x', flags);
	if (i == 0)
		ft_putchar('0', flags);
	else
		ft_put_lnbr_base_long(i, "0123456789abcdef", flags);
	if (flags->width > flags->len)
		ft_printspace(flags->width - (flags->len + 2), flags);
}
