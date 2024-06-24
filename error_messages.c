/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   error_messages.c						   :+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: ycantin <ycantin@student.42.fr>			+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2024/05/04 10:14:06 by ycantin		   #+#  #+#		  */
/*   Updated: 2024/05/08 11:51:07 by ycantin		  ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	error_msg(void)
{
	printf ("invalid set of arguments.\n");
	printf ("try as follows: <file> <cmd> <cmd> <file>\n");
	exit (EXIT_FAILURE);
}

void	free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free (array);
}
