#include "operations.h"

int main(void)
{
	int 				n_size = 8;
	t_matrix	matrix1;
	
	matrix1 = matrix_create(n_size);
	solve(matrix1);
	free_matrix(matrix1);
	return (0);
}
