#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

/**
 * is_unstable - Checks if the grid is unstable
 * @new_grid: 3x3 sandpile grid
 * Return: 1 if unstable, 0 if stable
 */
static int is_unstable(int new_grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (new_grid[i][j] > 3)
				return (1);
	return (0);
}

/**
 * compute_cell - Topples the sandpile
 * @new_grid: 3x3 grid to be toppled
 */
static void compute_cell(int new_grid[3][3])
{
	int i, j;
	int copy[3][3] = {0};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (new_grid[i][j] > 3)
			{
				copy[i][j] -= 4;
				if (i > 0)
					copy[i - 1][j]++;
				if (i < 2)
					copy[i + 1][j]++;
				if (j > 0)
					copy[i][j - 1]++;
				if (j < 2)
					copy[i][j + 1]++;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			new_grid[i][j] += copy[i][j];
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
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
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 sandpile (will hold result)
 * @grid2: Second 3x3 sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		grid1[i][j] += grid2[i][j];

	/* Stabilize grid1 */
	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		compute_cell(grid1);
	}
}
