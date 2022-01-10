#include "../../includes/libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	unsigned long long	div;
	int					len;
	char				*res;

	div = n;
	if (n == 0)
		len = 1;
	else
		len = 0;
	while (div != 0)
	{
		div = div / 10;
		len++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
