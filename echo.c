/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:33:07 by asimao            #+#    #+#             */
/*   Updated: 2024/11/10 15:33:27 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(char **args) 
{
    int new_line = 1;
    int i = 1;
    
    if (args[i] && ft_strncmp(args[1], "-n", 2) == 0) {
        new_line = 0;
        i++;
    }
    while (args[i]) {
        int j = 0;
        while (args[i][j]) {
            if (args[i][j] == '\'' || args[i][j] == '"') {
                j++;
            }
            else
            {
                ft_putchar_fd(args[i][j], 1);
            j++;
            }
            
        }
        
        if (args[i + 1]) {
            ft_putchar_fd(' ', 1);
        }
        i++;
    }
   if (new_line) {
        ft_putchar_fd('\n', 1);
    }
}