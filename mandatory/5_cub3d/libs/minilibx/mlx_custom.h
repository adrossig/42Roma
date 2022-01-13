#ifndef MLX_CUSTOM_H
# define MLX_CUSTOM_H

#include <mlx.h>
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

/*
** It takes mlx_ptr, but it doesn't use it.
** This function can only get Main Screen,
** you should be careful when you use multiple monitors...
*/

#endif
