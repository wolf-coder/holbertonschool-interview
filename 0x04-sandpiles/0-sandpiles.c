#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
 * Target_cases - modify target_case; a 3x3 binary valued grid with:
 * 1 -> case to topple, and 0 -> not to topple.
 * @target_case: 3x3 grid.
 * @grid1: 3x3 grid.
 */
void Target_cases(int target_case[3][3], int grid1[3][3])
{
	int i, j;


	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (grid1[i][j] > 3)
				target_case[i][j] = 1;
			else
				target_case[i][j] = 0;
		}
	}
}
/**
 * to_topple_more - check whether target_case[3][3] requieres
 * extra toppling.
 * @target_case: 3x3 binary valued grid.
 * @tople: binary value.
 * Return: 1 or 0.
 */
int to_topple_more(int target_case[3][3], int *tople)
{
	int i, j;
	*tople = 0;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
			if (target_case[i][j])
			{
				*tople = 1;
				break;
			}
	}
	return (*tople);
}
/**
 * sandpiles_sum - function that computes the sum of two sandpiles.
 * @grid1: a 3x3 grid.
 * @grid2: a 3x3 grid.
 * Return: 1 or 0.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, topple_more = 1, target_case[3][3] = {0};
	/* Making grid1 = grid1 + grid2 */
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
			grid1[i][j] += grid2[i][j];
	}
	Target_cases(target_case, grid1);
	while (to_topple_more(target_case, &topple_more))
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				if (target_case[i][j])
				{
					/*FOCAL TOPPLING*/
					grid1[i][j] -= 4;
					/*left toppling*/
					if (j != 0)
						grid1[i][j - 1] += 1;
					/*up toppling*/
					if (i != 0)
						grid1[i - 1][j] += 1;
					/*right toppling*/
					if (j != 2)
						grid1[i][j + 1] += 1;
					/*buttom toppling*/
					if (i != 2)
						grid1[i + 1][j] += 1;
				}
			}
		}
		Target_cases(target_case, grid1);
	}
}
