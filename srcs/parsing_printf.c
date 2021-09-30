#include "../ft_printf.h"

void	parse_init(t_flags *flags)
{
	flags->width = 0;
	flags->left = 0;
	flags->pad = 0;
	flags->dot = 0;
	flags->prec = 0;
	flags->len = 0;
	flags->minus = 0;
	flags->precmin = 0;
	flags->exception = 0;
	flags->ret = 0;
}

int	flag_reset(const char *str, t_flags *flags)
{
	int	j;

	j = 1;
	flags->width = 0;
	flags->left = 0;
	flags->pad = 0;
	flags->dot = 0;
	flags->prec = 0;
	flags->len = 0;
	flags->minus = 0;
	flags->precmin = 0;
	flags->exception = 0;
	while (str[j])
	{
		if (ft_charchr(str[j], "cspdiuxX%"))
			return (0);
		j++;
	}
	return (-1);
}

int	parse_indic(const char *str, int i, t_flags *flags)
{
	while (str[i] && !ft_charchr(str[i], "cspdiuxX.*123456789%"))
	{
		if (str[i] == '0')
			flags->pad = 1;
		if (str[i] == '-')
		{
			flags->left = 1;
			flags->pad = 0;
		}
		i++;
	}
	return (i);
}

int	parse_width(const char *str, int i, t_flags *flags)
{
	int	res;

	res = 0;
	if (str[i] == '*')
	{
		flags->width = va_arg(flags->args, int);
		i++;
		return (i);
	}
	while (!ft_charchr(str[i], "cspdiuxX.%"))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res < 0)
		res = res * -1;
	flags->width = res;
	return (i);
}

int	parse_prec(const char *str, int i, t_flags *flags)
{
	int	res;

	if (str[i] == '.')
	{
		flags->dot = 1;
		i++;
		res = 0;
		if (str[i] == '*')
		{
			flags->prec = va_arg(flags->args, int);
			i++;
			return (i);
		}
		while (!ft_charchr(str[i], "cspdiuxX%"))
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
		flags->prec = res;
	}
	if (flags->dot == 1)
		flags->pad = 0;
	return (i);
}
