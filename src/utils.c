#include "rubik.h"

//recibe una letra y devuelve el numero de la cara a la que corresponde
int get_face_index(char face)
{
	const char *faces = "URFDLB";
	for (int i = 0; i < NUM_FACES; i++)
	{
		if (faces[i] == face)
			return i;
	}
	return -1;
}

void get_modifiers(char *mov, int *is_prime, int *is_double)
{
	*is_prime = (mov[1] == '\'');
	*is_double = (mov[1] == '2');
}

void print_cube(const t_cube *cube)
{
	const char *face_names[NUM_FACES] = { "U", "R", "F", "D", "L", "B" };

	printf("----- Cubo -----\n\n");

	printf("[ ");
	for (int f = 0; f < NUM_FACES; f++)
		printf("%s ",face_names[f]);
	printf("]\n\n");

	for (int row = 0; row < SIZE; row++)
	{
		for (int f = 0; f < NUM_FACES; f++)
		{
			for (int col = 0; col < SIZE; col++)
			{
				int idx = row * SIZE + col;
				printf("%c ", cube->face[f][idx]);
			}
			printf("  ");
		}
		printf("\n");
	}
	printf("\n");
}


void ft_free(t_cube *cube)
{
	for (int f = 0; f < NUM_FACES; f++)
		free(cube->face[f]);
	free(cube->face);
}
