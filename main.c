/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ycantin <ycantin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/30 19:13:51 by ycantin		   #+#	#+#			 */
/*   Updated: 2024/06/24 07:27:05 by ycantin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

void	clean_pipes(int fd[2])
{
	close(fd[WRITE]);
	close(fd[READ]);
}

int	main(int argc, char **argv, char **envp)
{
	t_utilities	u;

	if (argc != 5)
		error_msg();
	if (!argv[2][0] || !argv[3][0])
		return (1);
	if (pipe(u.fd) < 0)
		error("error piping");
	u.process_id = fork();
	if (u.process_id == -1)
		error("error forking");
	if (u.process_id == 0)
		first_process(u, argv, envp);
	u.process_id2 = fork();
	if (u.process_id2 == -1)
		error("error forking");
	if (u.process_id2 == 0)
		last_process(u, envp, argv, 3);
	clean_pipes(u.fd);
	waitpid(u.process_id, NULL, 0);
	waitpid(u.process_id2, NULL, 0);
	exit(EXIT_SUCCESS);
}
