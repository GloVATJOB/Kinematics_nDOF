#pragma once

#include <vector>

#include "RotationMatrix.h"
#include "MatrixOperations.h"

class Link : private RotationMatrix
{
public:
	Link();

	void setSystemStartNextLink(const double X, const double Y, const double Z);
	void setKinematicPair(kinematicPair _kinematicPair);
	void setAxisRotation(axisRotation _axisRotation);
	void setLink�onfiguration(std::vector<std::vector<double>> _link�onfiguration);
	void setAngleRotation(double _angleRotation);

	void calculationRelativePosition();

	std::vector<std::vector<double>>& getRelativePosition();

private:
	void filling_mhct();

private:
	//�������������� ����
	//Kinematic pair
	kinematicPair _kinematicPair;

	//��� ��������
	//Rotational axis
	axisRotation _axisRotation;

	//���������� ������ ������� ���������� ����� S -> S' {3}
	//coordinates of the system origin of the next link S->S' {3}
	//[0]=X [1]=Y [2]=Z
	std::vector<double> _systemStartNextLink;

	//������������ ����� ������� Mi {3x3}
	//system link configuration Mi {3x3}
	std::vector<std::vector<double>> _link�onfiguration;

	//������� �������������� ���������� ��������� S -> S'
	//Homogeneous coordinate transformation matrix (mhct) S -> S'
	std::vector<std::vector<double>> _mhct;

	//������� �������������� ��������� ���� �������� �������
	//Relative position matrix of two neighboring links
	std::vector<std::vector<double>> _relativePosition;

	//���� �������� �����
	//Angle of rotation of the link
	double _angleRotation;
};

