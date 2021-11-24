#include "matrices.h"

void forbid_moves(int pos_x, int pos_y, t_matrix m)
{
	for(int i = 0; i < m.size; i++)
		for(int j = 0; j < m.size; j++)
			if (
				((i == pos_x) || (j == pos_y) || ((pos_x - i) * ( pos_x - i) - (pos_y - j) * (pos_y - j) == 0) )		&& 			(m.fields[i][j] == -1))
				m.fields[i][j] = 0;
}

int move_is_valid(int pos_x, int pos_y, t_matrix m)
{
	if (m.fields[pos_x][pos_y] == -1) 
		return (1);
	return (0);
}

void solve(t_matrix m, int pos_x, int pos_x)
{
	
}