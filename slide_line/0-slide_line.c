#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: A pointer to an array of integers containing size elements
 * @size: The number of elements in the array of integers
 * @direction: The direction on which the integers are slided and merged
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != j)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }

        for (i = 0; i < size - 1; i++)
        {
            if (line[i] != 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != j)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size, j = size - 1; i > 0; i--)
        {
            if (line[i - 1] != 0)
            {
                if ((i - 1) != j)
                {
                    line[j] = line[i - 1];
                    line[i - 1] = 0;
                }
                j--;
            }
        }

        for (i = size - 1; i > 0; i--)
        {
            if (line[i] != 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }

        for (i = size, j = size - 1; i > 0; i--)
        {
            if (line[i - 1] != 0)
            {
                if ((i - 1) != j)
                {
                    line[j] = line[i - 1];
                    line[i - 1] = 0;
                }
                j--;
            }
        }
    }

    return (1);
}
