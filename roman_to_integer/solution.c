/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:48:01 by mbarutel          #+#    #+#             */
/*   Updated: 2023/01/07 11:58:39 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int roman_val(char ch)
{
    if (ch == 'I')
        return (1);
    if (ch == 'V')
        return (5);
    if (ch == 'X')
        return (10);
    if (ch == 'L')
        return (50);
    if (ch == 'C')
        return (100);
    if (ch == 'D')
        return (500);
    if (ch == 'M')
        return (1000);
    return (0);
}

char *syntax_check(char *numerals, char ch)
{
    while (*numerals)
    {
        if (*numerals == ch)
            return (numerals);
        numerals++;
    }
    return (0);
}

int subtraction(char match, char roman)
{
    return (roman_val(match) - roman_val(roman));
}

int romanToInt(char *s)
{
    int  i;
    int  k;
    int  ret;
    int  skip;
    char *match;
    char *numerals = "IVXLCDM";

    k = -1;
    ret = 0;
    match = 0;
    while (s[++k])
    {
        skip = 0;
        match = syntax_check(numerals, s[k]);
        if (!match)
            return (0);
        i = 0;
        while (s[k + 1] && match[++i] && i <= 2 && !skip)
        {   
            if (match[i] == s[k + 1])
            {
                ret += subtraction(match[i], s[k]);
                skip++;
            }
        }
        if (skip)
        {
            k++;    
            continue;
        }
        ret += roman_val(s[k]);
    }
    return (ret);
}

int main(void)
{
//  printf("value %d\n", romanToInt("III"));
//  printf("value %d\n", romanToInt("LVIII"));
    printf("value %d\n", romanToInt("MCMXCIV"));
    return (0);
}