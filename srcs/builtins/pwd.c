/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:07:08 by urycherd          #+#    #+#             */
/*   Updated: 2022/09/25 18:13:11 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h" 

int	ft_pwd(void) // перед вызовом надо проверять, что аргументов нет
{
	char	cwd[MAX_PATH];

	if (getcwd(cwd, MAX_PATH))
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	return (1);
}