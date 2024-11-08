/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimao <asimao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:40:42 by asimao            #+#    #+#             */
/*   Updated: 2024/11/08 13:08:00 by asimao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H 
# define MINISHELL_H

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <readline/history.h>
#include "libft/libft.h"



void    term_init();
void    char_error_syntx(char char_error);
void    str_error_syntax();
void    error_redir(char *filename);
void	error_cd(char *filename);
void    error_redir(char *filename);

#endif