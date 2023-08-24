#pragma once

#include <vector>

void multMatrix4x4(std::vector<std::vector<double>>& aMatrix, 
	std::vector<std::vector<double>>& bMatrix, 
	std::vector<std::vector<double>>& product);

std::vector<std::vector<double>> multMatrix4x4(std::vector<std::vector<double>>& aMatrix,
	std::vector<std::vector<double>>& bMatrix);