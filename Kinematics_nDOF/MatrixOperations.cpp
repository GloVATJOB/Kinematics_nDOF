#include "MatrixOperations.h"

#define SIZE_MATRIX 4

void multMatrix4x4(std::vector<std::vector<double>>& aMatrix, 
	std::vector<std::vector<double>>& bMatrix, 
	std::vector<std::vector<double>>& product)
{
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < SIZE_MATRIX; k++)
                product[i][j] += aMatrix[i][k] * bMatrix[k][j];
        }
    }
}

std::vector<std::vector<double>> multMatrix4x4(std::vector<std::vector<double>>& aMatrix, 
    std::vector<std::vector<double>>& bMatrix) 
{
    std::vector<std::vector<double>> product(4, std::vector<double>(4));
    for (int i = 0; i < SIZE_MATRIX; i++)
    {
        for (int j = 0; j < SIZE_MATRIX; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < SIZE_MATRIX; k++)
                product[i][j] += aMatrix[i][k] * bMatrix[k][j];
        }
    }
    return product;
}
