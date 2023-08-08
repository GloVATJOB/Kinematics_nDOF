#pragma once
#include <vector>

//���� �������������� ���
enum class kinematicPair
{
	INDEFINED,
	SPHERICAL,
	ROTATIONAL,
	TRANSLATIONAL
};

//��� ��������
enum class axisRotation
{
	INDEFINED,
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

class Link
{
public:
	Link();

	void setSystemStartNextLink(const double X, const double Y, const double Z);
	void setKinematicPair(kinematicPair _kinematicPair);
	void setAxisRotation(axisRotation _axisRotation);
	void setLink�onfiguration(std::vector<std::vector<double>> _link�onfiguration);

private:
	void filling_mhct();
	void calculationRotationMatrix();

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

	//������� �������������� ���������� ���������
	//Homogeneous coordinate transformation matrix (mhct)
	std::vector<std::vector<double>> _mhct;

	//������� �������������� ��������� ���� �������� �������
	//Relative position matrix of two neighboring links
	std::vector<std::vector<double>> _relativePosition;

	//������� �������� � ��������� ������������
	//Rotation matrix in three-dimensional space
	std::vector<std::vector<double>> _rotationMatrix;

	//���� �������� �����
	//Angle of rotation of the link
	double _angleRotation;
};

