#include "MatrixOperations.h"



void multMatrix4x4(std::vector<std::vector<double>>& aMatrix, 
	std::vector<std::vector<double>>& bMatrix, 
	std::vector<std::vector<double>>& product)
{
    for (int i = 0; i < SIZE_MATRIX4x4; i++)
    {
        for (int j = 0; j < SIZE_MATRIX4x4; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < SIZE_MATRIX4x4; k++)
                product[i][j] += aMatrix[i][k] * bMatrix[k][j];
        }
    }
}

std::vector<std::vector<double>> multMatrix4x4(std::vector<std::vector<double>>& aMatrix, 
    std::vector<std::vector<double>>& bMatrix) 
{
    std::vector<std::vector<double>> product(4, std::vector<double>(4));
    for (int i = 0; i < SIZE_MATRIX4x4; i++)
    {
        for (int j = 0; j < SIZE_MATRIX4x4; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < SIZE_MATRIX4x4; k++)
                product[i][j] += aMatrix[i][k] * bMatrix[k][j];
        }
    }
    return product;
}

void multMatrix4x4(const double aMatrix[SIZE_MATRIX4x4][SIZE_MATRIX4x4],
    const double bMatrix[SIZE_MATRIX4x4][SIZE_MATRIX4x4],
    double product[SIZE_MATRIX4x4][SIZE_MATRIX4x4])
{
    for (int i = 0; i < SIZE_MATRIX4x4; i++)
    {
        for (int j = 0; j < SIZE_MATRIX4x4; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < SIZE_MATRIX4x4; k++)
                product[i][j] += aMatrix[i][k] * bMatrix[k][j];
        }
    }
}
