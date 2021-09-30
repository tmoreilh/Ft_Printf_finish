#include "../ft_printf.h"

int	ft_charchr(char c, char *haystack)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->ret++;
}

int	nbrlen(long n)
{
	if (n < 0)
		return (nbrlen(-n));
	else if (n / 10 > 0)
		return (1 + nbrlen(n / 10));
	else
		return (1);
}

void	ft_putnbr(long n, t_flags *flags)
{
	if (n < 0 && n > -2147483648)
		n = -n;
	if (n < 10 && n > -2147483648)
		ft_putchar(n + 48, flags);
	else if (n >= 10)
	{
		ft_putnbr(n / 10, flags);
		ft_putnbr(n % 10, flags);
	}
	else
	{
		write(1, "2147483648", 10);
		flags->ret = flags->ret + 10;
	}
}
