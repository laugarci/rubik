
#include "rubik.h"

void move_U(t_cube *c)
{
	char *tmp = malloc(sizeof(char) * SIZE);
	if (!tmp)
		return ;

	for (int i = 0; i < SIZE; i++)
		tmp[i] = c->face[F][i];
	tmp[SIZE] = '\0';

	for (int i = 0; i < SIZE; i++)
		c->face[F][i] = c->face[R][i];

	for (int i = 0; i < SIZE; i++)
		c->face[R][i] = c->face[B][SIZE - 1 - i];

	for (int i = 0; i < SIZE; i++)
		c->face[B][i] = c->face[L][SIZE - 1 - i];

	for (int i = 0; i < SIZE; i++)
		c->face[L][i] = tmp[i];

	free(tmp);
}

void move_U_prime(t_cube *c)
{
	(void)c;	
}

void	move_U2(t_cube *c)
{
	(void)c;	
}
