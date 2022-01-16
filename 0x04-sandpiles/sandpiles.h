#ifndef SANDPILES
#define SANDPILES

#include <stdio.h>
#include <stdlib.h>
void Target_cases(int target_case[3][3], int grid1[3][3]);
int to_topple_more(int target_case[3][3], int *tople);
static void print_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif
