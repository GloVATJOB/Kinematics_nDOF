#include "RotationMatrix.h"

RotationMatrix::RotationMatrix() :
	_rotationMatrix(4, std::vector<double>(4, 0)),
	_pair {1}
{}

void RotationMatrix::definitionRotationMatrix(axisRotation axis)
{
	if (axisRotation::AXIS_X == axis)
		this->calculationRotationMatrix = &RotationMatrix::calculationRotationMatrixX;

	if (axisRotation::AXIS_Y == axis)
		this->calculationRotationMatrix = &RotationMatrix::calculationRotationMatrixY;

	if (axisRotation::AXIS_Z == axis)
		this->calculationRotationMatrix = &RotationMatrix::calculationRotationMatrixZ;
}

void RotationMatrix::definitionPair(kinematicPair pair)
{
	if (kinematicPair::ROTATIONAL == pair || kinematicPair::SPHERICAL == pair)
		_pair = 1;

	if (kinematicPair::TRANSLATIONAL == pair)
		_pair = 0;
}

std::vector<std::vector<double>>& RotationMatrix::getRotationMatrix()
{
	return _rotationMatrix;
}

void RotationMatrix::calculationRotationMatrixX(double _angleRotation)
{
	_rotationMatrix[0][0] = 1;
	_rotationMatrix[0][3] = (static_cast<short int>(1) - _pair) * _angleRotation;
	_rotationMatrix[1][1] = cos(_angleRotation * _pair);
	_rotationMatrix[1][2] = -sin(_angleRotation * _pair);
	_rotationMatrix[2][1] = sin(_angleRotation * _pair);
	_rotationMatrix[2][2] = cos(_angleRotation * _pair);
	_rotationMatrix[3][3] = 1;
}

void RotationMatrix::calculationRotationMatrixY(double _angleRotation)
{
	_rotationMatrix[0][0] = cos(_angleRotation * _pair);
	_rotationMatrix[0][2] = sin(_angleRotation * _pair);
	_rotationMatrix[1][1] = 1;
	_rotationMatrix[1][3] = (static_cast<short int>(1) - _pair) * _angleRotation;
	_rotationMatrix[2][0] = -sin(_angleRotation * _pair);
	_rotationMatrix[2][2] = cos(_angleRotation * _pair);
	_rotationMatrix[3][3] = 1;
}

void RotationMatrix::calculationRotationMatrixZ(double _angleRotation)
{
	_rotationMatrix[0][0] = cos(_angleRotation * _pair);
	_rotationMatrix[0][1] = -sin(_angleRotation * _pair);
	_rotationMatrix[1][0] = sin(_angleRotation * _pair);
	_rotationMatrix[1][1] = cos(_angleRotation * _pair);
	_rotationMatrix[2][2] = 1;
	_rotationMatrix[2][3] = (static_cast<short int>(1) - _pair) * _angleRotation;
	_rotationMatrix[3][3] = 1;
}
