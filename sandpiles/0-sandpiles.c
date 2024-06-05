#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Checks if the grid is unstable
 * @grid: 3x3 grid
 * Return: 1 if unstable, 0 otherwise
 */
int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple - Topples an unstable sandpile
 * @grid: 3x3 grid
 */
void topple(int grid[3][3])
{
	int i, j;
	int temp_grid[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp_grid[i][j] -= 4;
				if (i > 0)
					temp_grid[i - 1][j]++;
				if (i < 2)
					temp_grid[i + 1][j]++;
				if (j > 0)
					temp_grid[i][j - 1]++;
				if (j < 2)
					temp_grid[i][j + 1]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp_grid[i][j];
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Stabilize the resulting grid */
	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
