#pragma once

#include <vector>

//Виды кинематических пар
enum class kinematicPair
{
	INDEFINED,
	SPHERICAL,
	ROTATIONAL,
	TRANSLATIONAL
};

//Ось вращения
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
	void (RotationMatrix::* calculationRotationMatrix)(const double& _angleRotation) { nullptr };
	void definitionRotationMatrix(const axisRotation& axis);
	void definitionPair(const kinematicPair& pair);

	const double(&getRotationMatrix())[4][4];

private:
	void calculationRotationMatrixX(const double& _angleRotation);
	void calculationRotationMatrixY(const double& _angleRotation);
	void calculationRotationMatrixZ(const double& _angleRotation);
	void calculationRotationMatrixD1(const double& _angleRotation);

private:
	//1 - kinematic pair - rotational
	//0 - kinematic pair - translational
	long long _pair;

	//Rotation matrix in three-dimensional space
	double _rotationMatrix[4][4]{};
};

