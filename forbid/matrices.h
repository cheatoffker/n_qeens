#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

int** matrix_declare(int matrix_size)
{
	int** matrix =  (int**)malloc(sizeof(int*) * matrix_size);
	if (matrix == NULL)
		exit(1);
	for(int i = 0; i < matrix_size; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * matrix_size);
		if (matrix[i] == NULL)
			exit(1);
	}
	return (matrix);
}

void init_matrix(t_matrix m)
{
	for (int x = 0; x < m.size; x++)
		for (int y = 0; y < m.size; y++)
			m.fields[x][y] = 0;
}

t_matrix matrix_create(int matrix_size)
{
	t_matrix matrix;
	matrix.fields = matrix_declare(matrix_size);
	matrix.size = matrix_size;
	init_matrix(matrix);
	return matrix;
}

void free_matrix(t_matrix m)
{
	for (int i=0; i < m.size; i++)
		{
		free(m.fields[i]);
		m.fields[i] = NULL;
		}
	free(m.fields);
	m.fields = NULL;
}

void print_matrix(t_matrix m)
{
    for (int x = 0; x < m.size; x++)
    {
        for (int y = 0; y < m.size; y++)
            printf(" %2d ", m.fields[x][y]);
        printf("\n");
    }
    printf("\n");
}

void print_solution(t_matrix m)
{
    for (int x = 0; x < m.size; x++)
    {
        for (int y = 0; y < m.size; y++)
        {
        	if(m.fields[x][y] > 0)
        		printf(" %d ", m.fields[x][y]);
        	else
        		printf(" %d ", 0);
        }
        printf("\n");
    }
    printf("\n");
}