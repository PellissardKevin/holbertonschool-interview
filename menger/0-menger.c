#include "menger.h"

/**
 * fill_sponge - Recursively fills the Menger Sponge
 * @sponge: The 2D array representing the sponge
 * @x: The current x-coordinate
 * @y: The current y-coordinate
 * @level: The current level of recursion
 */
void fill_sponge(char **sponge, int x, int y, int level)
{
	int i, j, sub_size;

	if (level == 0)
	{
		sponge[x][y] = '#';
	}
	else
	{
		sub_size = pow(3, level - 1);
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				if (i != 1 || j != 1)
				{
					fill_sponge(sponge, x + i * sub_size, y + j * sub_size, level - 1);
				}
			}
		}
	}
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: The level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, i, j;
	char **sponge;

	if (level < 0)
	{
		return;
	}

	size = pow(3, level);

	sponge = malloc(size * sizeof(char *));
	for (i = 0; i < size; ++i)
	{
		sponge[i] = malloc(size * sizeof(char));
	}

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			sponge[i][j] = ' ';
		}
	}

	fill_sponge(sponge, 0, 0, level);

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			putchar(sponge[i][j]);
		}
		putchar('\n');
	}

	for (i = 0; i < size; ++i)
	{
		free(sponge[i]);
	}
	free(sponge);
}
