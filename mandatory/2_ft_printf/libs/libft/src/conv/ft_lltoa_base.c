#include "../../includes/libft.h"

static int	ft_countll(unsigned long nb, int len, int neg)
{
	int		i;

	if (nb == 0)
		return (1);
	if (neg == -1 && len == 10)
		i = 1;
	else
		i = 0;
	while (nb)
	{
		nb /= len;
		i++;
	}
	return (i);
}

char	*ft_lltoa_base(long long nb, const char *base)
{
	char		*str;
	int			i;
	int			neg;
	int			len;
	long long	x;

	x = (long long)nb;
	len = ft_strlen(base);
	if (nb < 0)
		neg = -1;
	else
		neg = 1;
	i = ft_countll(x, len, neg);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	while (i--)
	{
		str[i] = base[ft_abs(x % len)];
		x /= len;
	}
	if (neg < 0 && len == 10)
		str[0] = '-';
	return (str);
}
