/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:53:24 by mbarutel          #+#    #+#             */
/*   Updated: 2023/01/07 17:11:02 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int reverse(int x)
{
    long sign;
    long rev;

    rev = 0;
    sign = 1;
    if (x < 0)
    {
        sign = -1;
        x = x * (long)-1;
    }
    while (x > 0)
    {
        if ((rev * 10 + x % 10) > 2147483647 || (rev * 10 + x % 10) < -2147483648)
            return (0);
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    return (rev * sign);    
}

int main(void)
{
    int x;

    x = 123;
    printf("%d\n", reverse(x));
    x = -123;
    printf("%d\n", reverse(x));
    x = 120;
    printf("%d\n", reverse(x));
    x = 6666666;
    printf("%d\n", reverse(x));
    x = 1534236469;
    printf("%d\n", reverse(x));
    return (0);
}