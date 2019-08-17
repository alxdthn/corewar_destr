/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 21:40:21 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/17 20:35:55 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destr.h"
#include "params.h"

int		main(void)
{
	int		fd;
	char	head[SIZE];
	char	*cmd;

	fd = open("destr.cor", O_CREAT | O_TRUNC | O_RDWR, S_IWRITE | S_IREAD);
	bzero(&head, SIZE);
	set_magic(head);
	set_name(head);
	set_comment(head);
	cmd = set_cmd(head, fd);
	write(fd, head, SIZE);
	write(fd, cmd, head[139]);
	free(cmd);
	close(fd);
	printf("DONE!\n");
}
