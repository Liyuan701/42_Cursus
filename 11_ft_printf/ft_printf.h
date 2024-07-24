/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifan <lifan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:07:02 by lifan             #+#    #+#             */
/*   Updated: 2023/12/02 18:17:52 by lifan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>

void	ft_pointer(size_t pointer, int *count);
void	ft_nb(int nb, int *count);
void	ft_hex(unsigned int nb, int *count, char c);
void	ft_unint(unsigned int nb, int *count);
void	ft_string(char *arg, int *count);
void	ft_char(char c, int *count);
void	ft_two(char c, int *count);
void	ft_case(va_list *arg, int *count, char fm);
char	*ft_setbase(char c);
int		ft_printf(const char *fm, ...);
int		ft_is(char fm);

#endif
