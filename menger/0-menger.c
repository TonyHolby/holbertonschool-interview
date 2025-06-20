#include "menger.h"
#include <math.h>

/**
 * menger - Draws a 2D Menger Sponge.
 * @level: the level of the Menger Sponge to draw.
 */

void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			int i = x, j = y;

			while (i > 0 || j > 0)
			{
				if (i % 3 == 1 && j % 3 == 1)
				{
					printf(" ");
					break;
				}
				i /= 3;
				j /= 3;
			}

			if (i == 0 && j == 0)
				printf("#");
		}
		printf("\n");
	}
}
