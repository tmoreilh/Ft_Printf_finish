#include "../ft_printf.h"

int	print_type(const char *str, int i, t_flags *flags)
{
	if (str[i] == 'd' || str[i] == 'i')
		print_int(flags);
	else if (str[i] == 'u')
		print_unsignedint(flags);
	else if (str[i] == 'c')
		print_char(flags);
	else if (str[i] == '%')
		print_percent(flags);
	else if (str[i] == 's')
		print_string(flags);
	else if (str[i] == 'p')
		print_pointer(flags);
	else if (str[i] == 'x')
		print_minihexa(flags);
	else if (str[i] == 'X')
		print_maxihexa(flags);
	else
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i], flags);
			i++;
		}
	}
	return (i + 1);
}
