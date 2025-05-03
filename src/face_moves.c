
#include "rubik.h"

void rotate_face_clockwise(char *face)
{
	char *tmp;
	
	tmp = malloc(sizeof(char) * (SIZE * SIZE));
	if (!tmp)
		return;

	for (int i = 0; i < (SIZE * SIZE); i++)
		tmp[i] = face[i];

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			int src = row * SIZE + col;
			int dst = col * SIZE + (SIZE - row - 1);
			face[dst] = tmp[src];
		}
	}

	free(tmp);
}

void rotate_face_counterclockwise(char *face)
{
	char *tmp = malloc(sizeof(char) * (SIZE * SIZE));
	if (!tmp)
		return;

	for (int i = 0; i < (SIZE * SIZE); i++)
		tmp[i] = face[i];

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			int src = row * SIZE + col;
			int dst = (SIZE - col - 1) * SIZE + row;
			face[dst] = tmp[src];
		}
	}

	free(tmp);
}

void rotate_face_180(char *face)
{
	int j;
	char tmp;

	j = 0;
	for (int i = 0; i < (SIZE * SIZE / 2); i++)
	{
		j = SIZE * SIZE - 1 - i;
		tmp = face[i];
		face[i] = face[j];
		face[j] = tmp;
	}
}
