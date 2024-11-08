/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:37:37 by asimao            #+#    #+#             */
/*   Updated: 2024/11/08 10:15:01 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"



void    ft_pwd()
{
    if(getcwd(NULL, 0) != NULL)
        printf("%s\n", getcwd(NULL, 0));
    else
        perror("getcwd");
}

void    term_init()
{
    char    *input;
    char    **args;
    
    while(1)
    {
        input = readline("\033[1;35mroot@aurora\033[m:~$ ");
        args = ft_split(input, ' ');
        if(ft_strncmp(args[0], "pwd", 3) == 0)
            ft_pwd();
        add_history(input);
        free(input);
    }
}