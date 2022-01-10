#include "../../includes/libft.h"

void	ft_putnwstr_fd(wint_t *wstr, int n, int fd)
{
	int	i;

	if (!wstr || n < 1 || fd < 0)
		return ;
	i = 0;
	while (i < n && wstr[i])
		ft_putwchar_fd(wstr[i++], fd);
}
