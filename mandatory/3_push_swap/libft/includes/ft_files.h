/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:11:00 by adrossig          #+#    #+#             */
/*   Updated: 2020/09/15 11:13:42 by adrossig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

# include "libft.h"

char			*ft_files_input(int fd);
char			ft_read_files(char *files);
int				ft_open_files(char *files, char right);

#endif
