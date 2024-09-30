/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:39:37 by narrospi          #+#    #+#             */
/*   Updated: 2024/09/28 11:39:46 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	handle_format(va_list args, const char character)
{
	int		count;

	count = 0;
	if (character == 'c')
		count += printchar(va_arg(args, int));
	else if (character == 'd' || character == 'i')
		count += print_decimal(va_arg(args, int));
	else if (character == 's')
		count += print_str(va_arg(args, char *));
	else if (character == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (character == 'x')
		count += handle_hex(va_arg(args, unsigned int), 0);
	else if (character == 'X')
		count += handle_hex(va_arg(args, unsigned int), 1);
	else if (character == 'p')
		count = print_pointer(va_arg(args, unsigned long));
	else if (character == '%')
		{
			write (1, "%", 1);
			count ++;
		}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += handle_format(args, str[i + 1]);
			i++;
		}			
		else
			count += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}