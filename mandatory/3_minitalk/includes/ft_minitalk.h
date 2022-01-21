/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienrossignol <adrienrossignol@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:18:17 by adrossig          #+#    #+#             */
/*   Updated: 2022/01/21 15:39:51 by adrienrossi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# define CHAR_BIT 8
# define SNDING_MSG "Sending message"
# define SENT_SUCCESS "Message sent!"
# define PID_ERR "Invalid PID\nUsage: ./client [PID] [MSG]\n"
# define ERR_ARG "Invalid arguments\nUsage: ./client [PID] [MSG]\n"
# define SRV_PIDERR "Server PID is invalid or server is not running"
# define NO_MSG "Please input a message to send\nUsage: ./client [PID] [MSG]"

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	error(char *str);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_putendl(char *s);

#endif
