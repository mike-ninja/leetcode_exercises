/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:47:05 by mbarutel          #+#    #+#             */
/*   Updated: 2023/02/28 21:52:09 by mbarutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

bool open_char(char ch)
{
    if (ch == '(')
        return (true);
    if (ch == '{')
        return (true);
    if (ch == '[')
        return (true);
    return (false);
}

bool isValid(char *s)
{
    int     i;
    char    brack;

    i = -1;
    brack = 0;
    while (s[++i])
    {
        if (open_char(s[i]))
        {
            if (!brack)
                brack = s[i];
            else
                if (!isValid(&s[i]))
                    return (false);
        }
        else
        {
            if (brack == '(' && s[i] != ')')
                return (false);
            if (brack == '{' && s[i] != '}')
                return (false);
            if (brack == '[' && s[i] != ']')
                return (false);
            brack = 0;
        }
    }
    return (true);
}

int main()
{
    char *str;

    str = "([)]";
    printf("str -> [%s] | result -> %d\n", str, isValid(str));
    str = "({[]})";
    printf("str -> [%s] | result -> %d\n", str, isValid(str));
    str = "()";
    printf("str -> [%s] | result -> %d\n", str, isValid(str));
    str = "(";
    printf("str -> [%s] | result -> %d\n", str, isValid(str));
    return (0);
}