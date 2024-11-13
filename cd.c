/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:35:25 by asimao            #+#    #+#             */
/*   Updated: 2024/11/13 11:00:49 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *get_value_env(char *str, char **envp)
{
    int i;
    size_t len;
    
    i = 0;
    len = ft_strlen(str);
    
   
    while(envp[i])
    {
        if (ft_strncmp(envp[i], str, len) == 0 && envp[i][len] == '=')
            return (envp[i] + len + 1);
        i++;
    }
    return (NULL);
}

int cd_exec(char **args, char **envp)
{
    char *file;
    char cwd[1024];
    

    if (!args[1] || (args[1][0] == '~' && args[1][1] == '\0'))
        file = get_value_env("HOME", envp);
    else
        file = args[1];
    if(!file || chdir(file) != 0)
    {
        error_cd(args[1]);
        return(1);
    }
    getcwd(cwd, sizeof(cwd));
    getcwd(cwd, sizeof(cwd));
    
    return(0);
}