
#include "rubik.h"

void move_U(t_cube *c)
{
	char tmp[SIZE];

	for (int i = 0; i < SIZE; i++)
		tmp[i] = c->face[F][i];

	for (int i = 0; i < SIZE; i++)
		c->face[F][i] = c->face[L][i];

	for (int i = 0; i < SIZE; i++)
		c->face[L][i] = c->face[B][i];

	for (int i = 0; i < SIZE; i++)
		c->face[B][i] = c->face[R][i];

	for (int i = 0; i < SIZE; i++)
		c->face[R][i] = tmp[i];
}

void	move_U_prime(t_cube *c)
{
	(void)c;
}

void	move_U2(t_cube *c)
{
	(void)c;	
}
