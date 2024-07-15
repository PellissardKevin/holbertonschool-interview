#include "slide_line.h"

/**
 * slide_and_merge_left - Slides and merges array elements to the left
 * @line: Pointer to the array of integers
 * @size: Size of the array
 */
void slide_and_merge_left(int *line, size_t size)
{
    size_t i, j;

    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (j != i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            j++;
        }
    }

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (j != i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            j++;
        }
    }
}

/**
 * slide_and_merge_right - Slides and merges array elements to the right
 * @line: Pointer to the array of integers
 * @size: Size of the array
 */
void slide_and_merge_right(int *line, size_t size)
{
    int i, j;

    for (i = size - 1, j = size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
        {
            if (j != i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            j--;
        }
    }

    for (i = size - 1; i > 0; i--)
    {
        if (line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }

    for (i = size - 1, j = size - 1; i >= 0; i--)
    {
        if (line[i] != 0)
        {
            if (j != i)
            {
                line[j] = line[i];
                line[i] = 0;
            }
            j--;
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to the array of integers
 * @size: Size of the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_LEFT)
    {
        slide_and_merge_left(line, size);
    }
    else if (direction == SLIDE_RIGHT)
    {
        slide_and_merge_right(line, size);
    }
    else
    {
        return (0);
    }

    return (1);
}
