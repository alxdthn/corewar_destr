/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 05:21:07 by nalexand          #+#    #+#             */
/*   Updated: 2019/08/17 20:51:47 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# define REG_OFSET		1
# define IND_OFSET		2
# define DIR_OFSET		op->t_dir_size


typedef struct			s_op
{
	char			 	*op_name;
	char			 	arg_count;
	char			 	args[3];
	char			 	op_code;
	int				 	cycle;
	char			 	*description;
	char			 	arg_type;
	char			 	t_dir_size;
	char			 	carry;
}					 	t_op;

t_op					g_op_tab[17];

typedef union			u_arg_byte
{
	char				byte;
	struct
	{
		unsigned char	a4 : 2;
		unsigned char	a3 : 2;
		unsigned char	a2 : 2;
		unsigned char	a1 : 2;
	}					arg;
}						t_arg_byte;

int						get_arg_type(char arg_byte);
int						get_arg_ofset(int arg_type, t_op *op);
char					*set_cmd(char *head, int fd);
void					set_comment(char *buf);
void					set_name(char *buf);
void					set_magic(char *buf);
t_op					*get_cmd(char *cmd);
int						get_function_size(char arg_byte, t_op *op);
long					ft_reverse_bytes(long bytes, size_t size);

#endif
