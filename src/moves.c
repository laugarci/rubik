#include "rubik.h"

void	move_F(t_cube *c)
{
	char *tmp;
	
	tmp = malloc(sizeof(char) * SIZE);
	if (!tmp)
		return ;
	
	rotate_face_clockwise(c->face[F]);
	print_cube(c);
	for (int i = 0; i < SIZE; i++)
		tmp[i] = c->face[U][(SIZE - 1) * SIZE + i];

	for (int i = 0; i < SIZE; i++)
		c->face[U][(SIZE - 1) * SIZE + i] = c->face[L][(SIZE - 1 - i) * SIZE + (SIZE - 1)];

	for (int i = 0; i < SIZE; i++)
		c->face[L][i * SIZE + (SIZE - 1)] = c->face[D][i];

	for (int i = 0; i < SIZE; i++)
		c->face[D][i] = c->face[R][(SIZE - 1 - i) * SIZE];

	for (int i = 0; i < SIZE; i++)
		c->face[R][i * SIZE] = tmp[i];

	free(tmp);
}

void	move_U(t_cube *c)
{
	(void)c;
}

void	move_D(t_cube *c)
{
	(void)c;
}

void	move_R(t_cube *c)
{
	(void)c;
}

void	move_L(t_cube *c)
{
	(void)c;
}

void	move_B(t_cube *c)
{
	(void)c;
}
