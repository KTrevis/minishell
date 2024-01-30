/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:28 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/01 10:57:10 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

int		ft_putchar_len(char c);
int		ft_putstr_len(char *str);
int		ft_putnbr_len(int n, unsigned int *len);
int		ft_putaddr_len(void *ptr);
int		ft_puthexa_unsigned_len(uintptr_t n, char c);
int		ft_putnbr_unsigned_len(unsigned int n);
int		ft_printf(const char *str, ...);
char	ft_uppercase_char(char c);
char	*ft_uppercase_str(char *str);

#endif
