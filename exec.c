#include "pipex.h"

/* Función que recibe un archivo y un comando. Busca
la ruta del cmd para poder ejecutarlo en el archivo con
execve. */
void	exec_cmd_to_file(char *file, char *cmd)
{
	char	**splitted_paths;
	char	**cmd_paths;
	char	*cmd_dir;
	char	**matrix_for_exec;

	splitted_paths = split_paths(LINUX_PATH);
	cmd_paths = concat_paths(splitted_paths, cmd);
	cmd_dir = get_path(cmd_paths);
	matrix_for_exec = create_matrix(3);
	matrix_for_exec[0] = cmd;
	matrix_for_exec[1] = file;
	if (execve(cmd_dir, matrix_for_exec, NULL) == -1) // execve reemplaza el proceso, no es necesario liberar exceptuando en caso de error
	{
		free(cmd_dir);
		free_matrix(cmd_paths);
		free_matrix(splitted_paths);
		free_matrix(matrix_for_exec);
		perror("Error executing first command");
		exit(EXIT_FAILURE);
	}
}

/* Ejecuta el comando touch, le hemos pasado una macro de forma arbitraria
para localizar touch */
void	*exec_touch(const char *file)
{
	char	**touch_matrix;

	touch_matrix = create_matrix(3);
	if (!touch_matrix)
		return (NULL);
	touch_matrix[0] = "touch";
	touch_matrix[1] = (char *)file;
	if (execve(TOUCH_PATH, touch_matrix, NULL) == -1)
	{
		free_matrix(touch_matrix);
		perror("Error creating a file");
		exit(EXIT_FAILURE);
	}
	return (NULL);
}
