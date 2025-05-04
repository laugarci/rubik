#include "rubik.h"

void	move_F(t_cube *c)
{
	char *tmp;
	
	tmp = malloc(sizeof(char) * SIZE);
	if (!tmp)
		return ;
	
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

void move_F_prime(t_cube *c)
{
	char *tmp;

	tmp = malloc(sizeof(char) * SIZE);
	for (int i = 0; i < SIZE; i++)
		tmp[i] = c->face[U][(SIZE - 1) * SIZE + i];

	for (int i = 0; i < SIZE; i++)
		c->face[U][(SIZE - 1) * SIZE + i] = c->face[R][i * SIZE];

	for (int i = 0; i < SIZE; i++)
		c->face[R][i * SIZE] = c->face[D][i];

	for (int i = 0; i < SIZE; i++)
		c->face[D][i] = c->face[L][i * SIZE + (SIZE - 1)];

	for (int i = 0; i < SIZE; i++)
		c->face[L][(SIZE - 1 - i) * SIZE + (SIZE - 1)] = tmp[i];
	free(tmp);
}

void move_F2(t_cube *c)
{
	char *tmp1;
	char *tmp2;

	tmp1 = malloc(sizeof(char) * SIZE);
	tmp2 = malloc(sizeof(char) * SIZE);
	for (int i = 0; i < SIZE; i++) {
		tmp1[i] = c->face[U][(SIZE - 1) * SIZE + i];
		tmp2[i] = c->face[D][i];
	}

	for (int i = 0; i < SIZE; i++)
		c->face[U][(SIZE - 1) * SIZE + i] = tmp2[SIZE - 1 - i];

	for (int i = 0; i < SIZE; i++)
		c->face[D][i] = tmp1[SIZE - 1 - i];

	for (int i = 0; i < SIZE; i++) {
		char temp = c->face[L][i * SIZE + (SIZE - 1)];
		c->face[L][i * SIZE + (SIZE - 1)] = c->face[R][(SIZE - 1 - i) * SIZE];
		c->face[R][(SIZE - 1 - i) * SIZE] = temp;
	}

	free(tmp1);
	free(tmp2);
}

