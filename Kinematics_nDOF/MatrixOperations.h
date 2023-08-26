#pragma once

#include <vector>

#define SIZE_MATRIX4x4 4

void multMatrix4x4(std::vector<std::vector<double>>& aMatrix, 
	std::vector<std::vector<double>>& bMatrix, 
	std::vector<std::vector<double>>& product);

std::vector<std::vector<double>> multMatrix4x4(std::vector<std::vector<double>>& aMatrix,
	std::vector<std::vector<double>>& bMatrix);

void multMatrix4x4(const double aMatrix[SIZE_MATRIX4x4][SIZE_MATRIX4x4],
	const double bMatrix[SIZE_MATRIX4x4][SIZE_MATRIX4x4],
	double product[SIZE_MATRIX4x4][SIZE_MATRIX4x4]);