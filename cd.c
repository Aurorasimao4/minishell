/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:35:25 by asimao            #+#    #+#             */
/*   Updated: 2024/11/10 17:30:32 by asimao           ###   ########.fr       */
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

/*void Updated_env(char *str, char *nbr, char **envp)
{
    char *env_var;
    size_t len;
    int i = 0;
    int found = 0;

    // Criação da nova variável de ambiente no formato "NOME=VALOR"
    len = strlen(str) + strlen(nbr) + 2; // Inclui espaço para '=' e '\0'
    env_var = (char *)calloc(len, sizeof(char));
    if (!env_var)
        return;
    snprintf(env_var, len, "%s=%s", str, nbr);

    // Loop para procurar pela variável no envp
    while (envp[i] != NULL)
    {
        // Verifica se a entrada atual é a variável desejada
        if (strncmp(envp[i], str, strlen(str)) == 0 && envp[i][strlen(str)] == '=')
        {
            free(envp[i]);
            envp[i] = env_var;
            found = 1;
            break;
        }
        i++;
    }

    // Se a variável não foi encontrada, adiciona ao final de envp
    if (!found)
    {
        envp[i] = env_var;
        envp[i + 1] = NULL; // Marca o novo fim do array
    }
    else
    {
        free(env_var); // Libera env_var se não foi usado
    }
}*/

int cd_exec(char **args, char **envp)
{
    char *file;
    char cwd[1024];
    

    if (!args[1] || (args[1][0] == '~' && args[1][1] == '\0'))
        file = get_value_env("HOME", envp);
    else if(args[1][0] == '-' && args[1][1] == '\0')
    {
        file = get_value_env("OLDPWD", envp);
        if(file)
            ft_putendl_fd(file, STDOUT_FILENO);
    }
    else
        file = args[1];
    if(!file || chdir(file) != 0)
    {
        error_cd(args[1]);
        return(1);
    }
    
    getcwd(cwd, sizeof(cwd));
    //Updated_env("OLDPWD", get_value_env("PWD", envp), envp);
    getcwd(cwd, sizeof(cwd));
   // Updated_env("PWD", cwd, envp);
    ft_pwd();

    return(0);
}