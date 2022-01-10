#include "../../includes/libft.h"

size_t	ft_wstrlenz(wint_t *wstr)
{
	if (!wstr || *wstr == L'\0')
		return (0);
	return (ft_wchar_len(*wstr) + ft_wstrlenz(wstr + 1));
}
