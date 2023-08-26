#pragma once

#include <vector>

#include"Link.h"
#include "MatrixOperations.h"

//#define _TEST_

#ifdef _TEST_
#include<iostream>
#endif // _TEST_

class Manipulator
{
public:
	Manipulator();

	void setCountLink(const unsigned short int _countLink);
	void setAngleRotation(const std::vector<double> _angles);

	Link& getLink(const unsigned short int numberLink);

	void calculationTCP();

	//void getTCP();

private:
	//Количество звеньев
	//Count Link
	unsigned short int _countLink;

	//Звенья манипулятора
	//Manipulator links
	std::vector<Link> _links;

	//Matrix of transformation of homogeneous coordinates from system Sn -> S0
	double _hct[4][4]{};
};