#include "../ft_printf.h"

int	ft_lnbr_len(unsigned long nbr, char *base)
{
	int				i;
	long			size;
	unsigned long	nbr_l;
	int				convertion[100];

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
	if (nbr == 0)
		i = 1;
	return (i);
}

int	ft_put_lnbr_base_long(unsigned long nbr, char *base, t_flags *flags)
{
	int						i;
	int						ret;
	long					size;
	unsigned long long		nbr_l;
	int						convertion[100];

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
