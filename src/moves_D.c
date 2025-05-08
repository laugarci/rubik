#include "rubik.h"

void move_D(t_cube *c)
{
	char tmp[SIZE];
	int last = SIZE - 1;

	// Guardar fila inferior de F
	for (int i = 0; i < SIZE; i++)
		tmp[i] = c->face[F][last * SIZE + i];

	// F ← L
	for (int i = 0; i < SIZE; i++)
		c->face[F][last * SIZE + i] = c->face[L][last * SIZE + i];

	// L ← B
	for (int i = 0; i < SIZE; i++)
		c->face[L][last * SIZE + i] = c->face[B][last * SIZE + i];

	// B ← R
	for (int i = 0; i < SIZE; i++)
		c->face[B][last * SIZE + i] = c->face[R][last * SIZE + i];

	// R ← tmp (original F)
	for (int i = 0; i < SIZE; i++)
		c->face[R][last * SIZE + i] = tmp[i];

}

void move_D_prime(t_cube *c)
{
	(void)c;	
}

void	move_D2(t_cube *c)
{
	(void)c;	
}
