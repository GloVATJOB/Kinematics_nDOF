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

class RotationMatrix
{
protected:
	RotationMatrix();
	void (RotationMatrix::*calculationRotationMatrix)(const double& _angleRotation) { nullptr };
	void definitionRotationMatrix(const axisRotation& axis);
	void definitionPair(const kinematicPair& pair);

	std::vector<std::vector<double>>& getRotationMatrix();

private:
	void calculationRotationMatrixX(const double& _angleRotation);
	void calculationRotationMatrixY(const double& _angleRotation);
	void calculationRotationMatrixZ(const double& _angleRotation);

private:
	//1 - �������������� ���� � ������������
	//0 - �������������� ���� � ��������������
	//1 - kinematic pair - rotational
	//0 - kinematic pair - translational
	short int _pair;

	//������� �������� � ��������� ������������
	//Rotation matrix in three-dimensional space
	std::vector<std::vector<double>> _rotationMatrix;
};

