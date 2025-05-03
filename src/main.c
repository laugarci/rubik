#include "rubik.h"

//F - cara frontal
//U - cara superior
//D - cara inferior
//B - cara trasera
//L - cara izquierda
//R - cara derecha
//
//Si nada mas - giro de 90° en sentido horario (derecha)
//si ' giro de 90° en sentido antihorario (izquierda)
//2 giro de 180°

void init_cube(t_cube *cube)
{
	const char colors[NUM_FACES] = { WHITE, RED, GREEN, YELLOW, ORANGE, BLUE };

	cube->face = malloc(sizeof(char *) * NUM_FACES);
	if (!cube->face)
		return;

	for (int f = 0; f < NUM_FACES; f++)
	{
		cube->face[f] = malloc(sizeof(char) * (SIZE * SIZE));
		if (!cube->face[f])
			return;
		for (int i = 0; i < (SIZE * SIZE); i++)
			cube->face[f][i] = colors[f];
	}
}

int checker(const char *input)
{
	const char *valid;
	int i;

	i = 0;
	valid = "FRUBLD";
	while (input[i])
	{
		if (input[i] == ' ')
		{
			i++;
			continue;
		}
		if (!strchr(valid, input[i]))
			return (0);
		i++;
		if (input[i] == '\'' || input[i] == '2')
			i++;
		if (isalnum(input[i]) && !strchr(valid, input[i]) && input[i] != ' ')
			return (0);
	}
	return (1);
}


int main(int ac, char **av)
{
	t_cube cube;
	if (ac != 2)
		return (1);


	if (!checker(av[1]))
	{
		printf("Error: input no válida\n");
		return (1);
	}

	init_cube(&cube);
	print_cube(&cube);
	apply_moves(&cube, av[1]);
	print_cube(&cube);
	ft_free(&cube);
	return (0);
}

