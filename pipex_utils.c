/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex_utils.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ycantin <ycantin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/05 16:58:16 by ycantin		   #+#	#+#			 */
/*   Updated: 2024/06/24 07:39:54 by ycantin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**path_array;
	char	*path;
	char	*partial;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path_array = ft_split(envp[i], ':');
	i = 0;
	while (path_array[i])
	{
		partial = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(partial, cmd);
		free (partial);
		if (access(path, F_OK) == 0)
			return (free_str_array(path_array), path);
		free (path);
		i++;
	}
	free_str_array(path_array);
	return (0);
}

void	cmd_exec(char **envp, char **argv, int cmd_index) //cmd_index == argc
{
	char	**splitted_cmd;
	char	*path;

	splitted_cmd = ft_split(argv[cmd_index], ' ');
	path = find_path(splitted_cmd[0], envp);
	if (!path)
	{
		free_str_array (splitted_cmd);
		error ("command not found");
	}
	if (execve (path, splitted_cmd, envp) < 0)
		error("problem executing command");
}

// int main(int argc, char **argv, char **envp)
// {
//	 char *cmd = "wc";
//	 char *found_path;

//	 printf("Testing find_path function:\n");
//	 found_path = find_path(cmd, envp);
//	 if (found_path)
//		 printf("Path for %s: %s\n", cmd, found_path);
//	 else
//		 printf("Path for %s not found\n", cmd);

//	 printf("\nTesting child_process function:\n");
//	 child_process(envp, argv, 1); // Assuming argv[1] contains a valid command
//	 free(found_path);
//	 exit(1);
//	 return 0;
// }