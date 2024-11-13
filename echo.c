/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:33:07 by asimao            #+#    #+#             */
/*   Updated: 2024/11/13 12:59:57 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int quote_check(const char *str)
{
    int i =0;
    int j = 0;
    int k = 0;
    while(str[i])
    {
        if (str[i] == '"')
        {
            i++;
            j++;
            if (str[i] == '"')
                j++;
            while (str[i] && str[i] != '"')
            {
                i++;
                if (str[i] == '"')
                {
                    j++;
                    break ;
                }
            }
        }
        else if (str[i] == '\'')
        {
            i++;
            k++;
            if (str[i] == '\'')
                k++;
            while (str[i] && str[i] != '\'')
            {
                i++;
                if (str[i] == '\'')
                {
                    k++;
                    break ;
                }
            }
        }
        i++;
     }
    if(j % 2 != 0 || k % 2 != 0)
    {
        fprintf(stderr, "Error: Quotes were not correctly closed.\n");
        return (1);
    }
    return (0);
}

void ft_echo(char **args) 
{
    int new_line = 1;
    int i = 1;

    if (args[i] && ft_strncmp(args[1], "-n", 2) == 0)
    {
        new_line = 0;
        i++;
    }
    while (args[i]) 
    {
        int j = 0;
        
        while (args[i][j]) 
        {
            
            if (args[i][j] == '"') 
            {
                j++;
                while (args[i][j] && args[i][j] != '"')
                    ft_putchar_fd(args[i][j++], 1);
                if (args[i][j] == '"') // Avança para ignorar a segunda aspa
                    j++;
            }
            else if (args[i][j] == 39) // Trata aspas simples
            {
                j++;
                while (args[i][j] && args[i][j] != 39)
                    ft_putchar_fd(args[i][j++], 1);
                if (args[i][j] == 39) // Avança para ignorar a segunda aspa
                    j++;
            }
            else
                ft_putchar_fd(args[i][j++], 1);
        }
        if (args[i + 1])
            ft_putchar_fd(' ', 1);
        i++;
    }
    if (new_line)
        ft_putchar_fd('\n', 1);
}

