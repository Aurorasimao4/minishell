/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:09:22 by asimao            #+#    #+#             */
/*   Updated: 2024/11/08 13:07:32 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    char_error_syntx(char char_error)
{
    ft_putstr_fd("syntax error", STDERR_FILENO);
    ft_putstr_fd(" \'", STDERR_FILENO);
    ft_putchar_fd(char_error, STDERR_FILENO);
    ft_putstr_fd("\'\n", STDERR_FILENO);
}

void    str_error_syntax()
{
    ft_putstr_fd("syntax error", STDERR_FILENO);
    ft_putstr_fd(" \'", STDERR_FILENO);
    //ft_putchar_fd(str_erro, STDERR_FILENO);
    ft_putstr_fd("\'\n", STDERR_FILENO);
}

void    error_redir(char *filename)
{
    ft_putstr_fd("lesh: ", STDERR_FILENO);
    ft_putstr_fd(filename, STDERR_FILENO);
    ft_putstr_fd(": ", STDERR_FILENO);
    //ft_putchar_fd(strerror, STDERR_FILENO);
    ft_putstr_fd(strerror(errno), STDERR_FILENO);
    ft_putstr_fd("\n", STDERR_FILENO);
}