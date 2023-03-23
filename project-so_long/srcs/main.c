#include "so_long.h"
#include <stdlib.h>
#define	WIDTH 1920
#define HEIGHT 1080

int parse_map(char **map)
{}

int	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp = malloc(sizeof(char) * 100);

	i = 0;
	j = 0;
	if (argc != 2)
		return 0;
	while (argv[1][i] != '.')
		i++;
	while (argv[1][i])
	{
		temp[j] = argv[1][i];
		j++;
		i++;
	}
	if (strcmp(temp, ".ber"))
		return 0;
	return 1;
}

int32_t	main(int argc, char **argv)
{
	if (!check_args(argc, argv)){
		printf("%s", "Arguments error");
		return 0;
	}
	t_game	*game;
	parse_map()

 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "So_Long", true);
	if (!mlx)
		return 0;

	mlx_image_t* img = mlx_new_image(mlx, 40, 40);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		return 0;

	cat = mlx_load_png("/Users/felixjr/Desktop/42/project-so_long/images/cat.png");
	if (!cat)
		printf("%s", "fallo");

	img = mlx_texture_to_image(mlx, cat);
	mlx_image_to_window(mlx, img, 700, 766/2);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS); 
}
