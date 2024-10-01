/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narrospi <narrospi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:55:54 by narrospi          #+#    #+#             */
/*   Updated: 2024/10/01 11:07:47 by narrospi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_hex_ptr(unsigned long num)
{
	if (num >= 16)
		print_hex_ptr(num / 16);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

int	print_pointer(unsigned long ptr)
{
	int	count;

	count = 0;
	write(1, "0x", 2);
	if (ptr == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	print_hex_ptr(ptr);
	while (ptr)
	{
		count++;
		ptr /= 16;
	}
	return (count + 2);
}
