#include "./minilibx-linux/mlx.h"
#include <stdio.h>

int main()
{
	void *mlx;
	void *win;
	void *img;
	int width, height;

	mlx = mlx_init();
	if (!mlx)
	{
		fprintf(stderr, "Erro: mlx_init() falhou\n");
		return (1);
	}

	win = mlx_new_window(mlx, 800, 600, "Teste MLX");
	if (!win)
	{
		fprintf(stderr, "Erro: mlx_new_window() falhou\n");
		return (1);
	}

	img = mlx_xpm_file_to_image(mlx, "./assets/sprite/sprite1.xpm", &width, &height);
	if (!img)
	{
		fprintf(stderr, "Erro: mlx_xpm_file_to_image() falhou ao carregar sprite1.xpm\n");
		return (1);
	}

	fprintf(stdout, "Imagem carregada com sucesso! %d x %d\n", width, height);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);

	return (0);
}
