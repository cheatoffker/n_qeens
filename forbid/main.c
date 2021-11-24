#include "operations.h"

int main(void)
{
	int 				n_size = 8;
			
	t_matrix	matrix1;
	matrix1 = matrix_create(n_size);
	
	forbid_moves(0,0, matrix1);
	print_matrix(matrix1);
	free_matrix(matrix1);
	return (0);
}
