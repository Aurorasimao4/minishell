/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:37:37 by asimao            #+#    #+#             */
/*   Updated: 2024/11/13 12:24:43 by asimao           ###   ########.fr       */
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

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while(s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return(s2[i] - s1[i]);
}

void    term_init(char **envp)
{
    char    *input;
    char    **args;

    while(1)
    {
        input = readline("\033[1;35mroot@aurora\033[m:~$ ");
        args = ft_split(input, ' ');
        if (quote_check(input) == 0)
        {
            if(ft_strncmp(args[0], "pwd", 3) == 0)
                ft_pwd();
            else if(ft_strcmp(args[0], "echo") == 0)
                ft_echo(args);
           else if(ft_strcmp(args[0], "cd") == 0)
                cd_exec(args, envp);
            else
                error_command(args[0]);
        }
        add_history(input);
        free(input);
    }
}