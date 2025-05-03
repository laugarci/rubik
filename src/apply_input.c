
#include "rubik.h"

void rotate_face(t_cube *cube, int face_index, int is_prime, int is_double)
{
	if (is_prime)
		rotate_face_counterclockwise(cube->face[face_index]);
	else if (is_double)
		rotate_face_180(cube->face[face_index]);
	else
		rotate_face_clockwise(cube->face[face_index]);
}

void apply_adjacent(t_cube *cube, char face, int is_prime, int is_double)
{
	if (face == 'F')
	{
		if (is_prime)
			for (int i = 0; i < 3; i++)
				move_F(cube);  //implementar move_f_prime
		else if (is_double)
			for (int i = 0; i < 2; i++) //implementar move_f2
				move_F(cube);
		else
			move_F(cube);
	}
	// TODO: añadir U, R, D, L, B
}

void move(t_cube *cube, char *mov)
{
	int index;
	int is_prime;
	int is_double;
	
	is_prime = 0;
	is_double = 0;
	index = get_face_index(mov[0]);
	if (index == -1)
		return;
	//si is_prime vale 1 giramos en antihorario, si is_double vale 1 giramos en 180
	get_modifiers(mov, &is_prime, &is_double);

	//giramos la cara
	rotate_face(cube, index, is_prime, is_double);

	//giramos las adyacentes a la cara
	apply_adjacent(cube, mov[0], is_prime, is_double);
}

int next_move(char *str, int *i, char *move)
{
	int j = 0;

	while (str[*i] == ' ')
		(*i)++;

	if (!str[*i])
		return 0;

	move[j++] = str[(*i)++];

	if (str[*i] == '\'' || str[*i] == '2')
		move[j++] = str[(*i)++];

	move[j] = '\0';
	return 1;
}

void apply_moves(t_cube *cube, char *input)
{
	int i;
	char mov[4];

	i = 0;
	while (next_move(input, &i, mov))
		move(cube, mov);
}

