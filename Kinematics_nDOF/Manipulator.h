#pragma once

#include <vector>

#include"Link.h"
#include "MatrixOperations.h"

#define _TEST_

#ifdef _TEST_
#include<iostream>
#endif // _TEST_


class Manipulator
{
public:
	Manipulator();

	void setCountLink(const unsigned short int _countLink);
	void setAngleRotation(const std::vector<double> angles);

	Link& getLink(const unsigned short int numberLink);
	void calculationHCT();

private:
	//Количество звеньев
	//Count Link
	unsigned short int _countLink;

	//Звенья манипулятора
	//Manipulator links
	std::vector<Link> _links;

	//Матрица преобразования однородных координат из системы Sn -> S0
	//Matrix of transformation of homogeneous coordinates from system Sn -> S0
	std::vector<std::vector<double>> _hct;

	//
	std::vector<std::vector<double>> _mhct_0N;

#ifdef _TEST_
public:
	void printHCT();
#endif // _TEST_
};