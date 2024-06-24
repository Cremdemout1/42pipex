/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   processes.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ycantin <ycantin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/06 17:16:35 by ycantin		   #+#	#+#			 */
/*   Updated: 2024/06/24 07:37:36 by ycantin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

void	first_process(t_utilities u, char **argv, char **envp)
{
	u.infile = open(argv[1], O_RDONLY);
	if (u.infile == -1)
	{
		clean_pipes(u.fd);
		error("error opening input file");
	}
	if (dup2(u.infile, STDIN_FILENO) < 0)
	{
		close(u.infile);
		clean_pipes(u.fd);
		error("error setting read end in infile");
	}
	close(u.infile);
	if (dup2(u.fd[WRITE], STDOUT_FILENO) < 0)
	{
		clean_pipes(u.fd);
		error("error setting write end of pipe1");
	}
	clean_pipes(u.fd);
	cmd_exec(envp, argv, 2);
}

void	last_process(t_utilities u, char **envp, char **argv, int i)
{
	u.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (u.outfile == -1)
	{
		clean_pipes(u.fd);
		error("error opening output file");
	}
	if (dup2(u.fd[READ], STDIN_FILENO) == -1)
	{
		close(u.outfile);
		clean_pipes(u.fd);
		error("error reading last pipe");
	}
	if (dup2(u.outfile, STDOUT_FILENO) == -1)
	{
		close(u.outfile);
		clean_pipes(u.fd);
		error("error outputting into outfile");
	}
	clean_pipes(u.fd);
	close(u.outfile);
	cmd_exec(envp, argv, i);
}
