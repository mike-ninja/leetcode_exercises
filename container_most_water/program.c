/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:07:57 by mbarutel          #+#    #+#             */
/*   Updated: 2023/03/03 19:40:43 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int maxArea(int *height, int heightSize)
{
    int i;
    int k;
    int max_area;

    i = 0;
    max_area = 0;
    k = heightSize - 1;
    while (i != k)
    {
        if (height[i] < height[k])
        {
            if (height[i] * (k - i) > max_area)
                max_area = height[i] * (k - i);
            i++;
        }
        else
        {
            if (height[k] * (k - i) > max_area)
                max_area = height[k] * (k - i);
            k--;
        }
    }
    printf("i %d k %d\n", i, k);
    return (max_area);
}

int main(void)
{
    int ptr[9] = {1,8,6,2,5,4,8,3,7};
    printf("result -> %d\n", maxArea(ptr, 9));
    return (0); 
}