#include "../ft_printf.h"

void	print_string(t_flags *flags)
{
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left = 1;
	}	
	if (flags->left == 0)
		print_string_right(flags);
	else if (flags->left == 1)
		print_string_left(flags);
}

void	print_string_prec_handler(int i, char *str, t_flags *flags)
{
	if (flags->dot == 1)
	{
		if (flags->prec < 0)
		{
			while (flags->len > i && str[i])
				ft_putchar(str[i++], flags);
		}
		else
		{
			while (flags->prec > i && str[i])
				ft_putchar(str[i++], flags);
		}
	}
	else
	{
		while (str[i])
			ft_putchar(str[i++], flags);
	}
	if (flags->width > flags->len && flags->len == 1
		&& flags->prec > flags->width && flags->exception == 0)
	{
		ft_printspace(flags->width - flags->len, flags);
		flags->exception = 1;
	}
}

int	print_string_zerolen(t_flags *flags)
{
	if (flags->len == 0)
	{
		ft_printspace(flags->width, flags);
		return (1);
	}
	return (0);
}

void	print_string_right(t_flags *flags)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(flags->args, char *);
	if (str == NULL)
		str = "(null)";
	flags->len = ft_strlen(str);
	if (print_string_zerolen(flags) == 1)
		return ;
	if (flags->dot == 0)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->width >= flags->prec && flags->prec >= flags->len)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->len > flags->prec && flags->width > flags->prec
		&& flags->prec >= 0)
		ft_printspace(flags->width - flags->prec, flags);
	else if (flags->width > flags->len && flags->len >= flags->prec)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->width > flags->len && flags->prec > flags->width)
	{
		ft_printspace(flags->width - flags->len, flags);
		flags->exception = 1;
	}
	print_string_prec_handler(i, str, flags);
}

void	print_string_left(t_flags *flags)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(flags->args, char *);
	if (str == NULL)
		str = "(null)";
	flags->len = ft_strlen(str);
	if (flags->width < 0)
		flags->width = flags->width * -1;
	if (print_string_zerolen(flags) == 1)
		return ;
	print_string_prec_handler(i, str, flags);
	if (flags->dot == 0)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->width >= flags->prec && flags->prec >= flags->len)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->len > flags->prec && flags->prec < 0)
		ft_printspace(flags->width - flags->len, flags);
	else if (flags->len > flags->prec && flags->width > flags->prec)
		ft_printspace(flags->width - flags->prec, flags);
	else if (flags->width > flags->len && flags->prec > flags->width
		&& flags->exception == 0)
		ft_printspace(flags->width - flags->len, flags);
}
