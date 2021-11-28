#include "matrices.h"

void forbid_moves(int pos_x, int pos_y, t_matrix m)
{
	for(int i = 0; i < m.size; i++)
		for(int j = 0; j < m.size; j++)
			if (
				((i == pos_x) || (j == pos_y) || ((pos_x - i) * ( pos_x - i) - (pos_y - j) * (pos_y - j) == 0) ) && (m.fields[i][j] <= 0))
				m.fields[i][j]--;
}

void unforbid_moves(int pos_x, int pos_y, t_matrix m)
{
	for(int i = 0; i < m.size; i++)
		for(int j = 0; j < m.size; j++)
			if (
				((i == pos_x) || (j == pos_y) || ((pos_x - i) * ( pos_x - i) - (pos_y - j) * (pos_y - j) == 0) ) && (m.fields[i][j] < 0))
				m.fields[i][j]++;
}

int move_is_valid(int pos_x, int pos_y, t_matrix m)
{
	if (m.fields[pos_x][pos_y] == 0) 
		return (1);
	return (0);
}

void propagate(int pos_x, int pos_y, int queen_num, t_matrix m)
{
	m.fields[pos_x][pos_y] = queen_num;
	forbid_moves(pos_x, pos_y, m);	
}

void backtrack(int pos_x, int pos_y, int queen_num, t_matrix m)
{
	unforbid_moves(pos_x, pos_y, m);
	m.fields[pos_x][pos_y] = 0;
}

int solve_next_move(t_matrix m, int queen_num)
{
	if (queen_num > m.size)
		return (1);
	for(int pos_x = 0; pos_x < m.size; pos_x++)
	{
		for(int pos_y = 0; pos_y < m.size; pos_y++)
		{
			if (move_is_valid(pos_x, pos_y, m)  == 1)
			{
				propagate(pos_x, pos_y, queen_num, m);
				//print_matrix(m);
				if (solve_next_move(m, queen_num + 1) == 1)
					return (1);
				else
					backtrack(pos_x, pos_y, queen_num, m);
					//print_matrix(m);
			}
		}
	}
	return (0);
}

int solve(t_matrix m)
{
	int		queen_num = 1;
	int 		start_x = 0;
	int 		start_y = 6;
		
	propagate(start_x, start_y, queen_num, m);
	printf("starting position\nx is %i\ny is %i\n", start_x, start_y);

	if (solve_next_move(m, queen_num + 1) == 1)
	{
		printf("solution found from this position\n");
		print_solution(m);
		return (1);
	}
	else
	{
		printf("no solution found from this position\n");
		return (0);
	}
}