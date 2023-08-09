#pragma once

#include <vector>

#include"Link.h"
#include "MatrixOperations.h"


class Manipulator
{
public:
	Manipulator();

	void setCountLink(const unsigned short int _countLink);
	void setAngleRotation(std::vector<double> angles);

	Link& getLink(const unsigned short int numberLink);
	void calculationHCT();

private:
	//���������� �������
	//Count Link
	unsigned short int _countLink;

	//������ ������������
	//Manipulator links
	std::vector<Link> _links;

	//������� �������������� ���������� ��������� �� ������� Sn -> S0
	//Matrix of transformation of homogeneous coordinates from system Sn -> S0
	std::vector<std::vector<double>> _hct;
};

