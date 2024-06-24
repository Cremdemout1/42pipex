/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ycantin <ycantin@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/04/18 17:20:37 by ycantin		   #+#	#+#			 */
/*   Updated: 2024/06/24 07:45:42 by ycantin		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# define WRITE 1
# define READ 0

typedef struct s_utils
{
	int		infile;
	int		outfile;
	char	*separated_cmd;
	int		cmd_index;
	int		fd[2];
	int		process_id;
	int		process_id2;
	int		i;
}			t_utilities;

typedef struct s_vars
{
	int		word_count;
	int		i;
	int		start;
	int		str_index;
	char	**dest;
}			t_vars;

void		error(char *message);
void		clean_pipes(int fd[2]);
void		assign_fd(int fd[2], int curr_argc, int outfile);
void		error_msg(void);
void		free_str_array(char **array);
char		*find_path(char *cmd, char **envp);
void		cmd_exec(char **envp, char **argv, int cmd_index);
void		close_all(int fd[2], int infile, int outfile);
void		first_process(t_utilities u, char **argv, char **envp);
void		next_process(t_utilities u, char **argv, char **envp, int i);
void		last_process(t_utilities u, char **envp, char **argv, int i);

int			ft_strncmp(const char *s1, char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
int			ft_count_words(const char *str, char c);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif