#include "../ft_printf.h"

void	ft_printspace(int size, t_flags *flags)
{
	while (size > 0)
	{
		ft_putchar(' ', flags);
		size--;
	}
}

void	ft_printzero(int size, t_flags *flags)
{
	while (size > 0)
	{
		ft_putchar('0', flags);
		size--;
	}
}

void	ft_putstr(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		ft_putchar(s[i], flags);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_put_lnbr_base(unsigned long nbr, char *base, t_flags *flags)
{
	int					i;
	int					ret;
	long				size;
	unsigned int		nbr_l;
	int					convertion[100];

	i = 0;
	size = 0;
	nbr_l = nbr;
	while (base[size])
		size++;
	while (nbr_l > 0)
	{
		convertion[i++] = nbr_l % size;
		nbr_l = nbr_l / size;
	}
	ret = i;
	while (i-- > 0)
		ft_putchar(base[convertion[i]], flags);
	if ((nbr == 0 && flags->dot == 0)
		|| (nbr == 0 && flags->dot == 1 && flags->prec != 0))
		ft_putchar('0', flags);
	return (ret);
}
