#include "Link.h"

Link::Link() :
	_kinematicPair{ kinematicPair::INDEFINED },
	_axisRotation{ axisRotation::INDEFINED },
	_angleRotation{ 0 },
	_systemStartNextLink(3, 0),
	_mhct(4, std::vector<double>(4, 0)),
	_link—onfiguration(4, std::vector<double>(4, 0)),
	_relativePosition(4, std::vector<double>(4, 0)),
	_rotationMatrix(4, std::vector<double>(4, 0)) 
{}

void Link::setSystemStartNextLink(const double X, const double Y, const double Z)
{
	_systemStartNextLink[0] = X;
	_systemStartNextLink[1] = Y;
	_systemStartNextLink[2] = Z;
	filling_mhct();
}

void Link::setKinematicPair(kinematicPair _kinematicPair)
{
	this->_kinematicPair = _kinematicPair;
}

void Link::setAxisRotation(axisRotation _axisRotation)
{
	this->_axisRotation = _axisRotation;
}

void Link::setLink—onfiguration(std::vector<std::vector<double>> _rotationMatrixM)
{
	this->_link—onfiguration = _rotationMatrixM;
	filling_mhct();
}

void Link::filling_mhct()
{
	for (int i = 0; i < _systemStartNextLink.size(); i++)
		_mhct[i][3] = _systemStartNextLink[i];

	for (int i = 0; i < _link—onfiguration.size(); i++)
		for (int j = 0; j < _link—onfiguration[i].size(); j++)
			_mhct[i][j] = _link—onfiguration[i][j];
}

void Link::calculationRotationMatrix()
{
	double alphaX = 0;
	double betaY = 0;
	double gamaZ = 0;

	if (axisRotation::AXIS_X == _axisRotation)
		alphaX = _angleRotation * (3.1415926535 / 180);

	if (axisRotation::AXIS_Y == _axisRotation)
		betaY = _angleRotation * (3.1415926535 / 180);

	if (axisRotation::AXIS_Z == _axisRotation)
		gamaZ = _angleRotation * (3.1415926535 / 180);

	_rotationMatrix[0][0] = cos(betaY) * cos(gamaZ);
	_rotationMatrix[1][0] = (sin(alphaX) * sin(betaY) * cos(gamaZ)) + (sin(gamaZ) * cos(alphaX));
	_rotationMatrix[2][0] = (sin(alphaX) * sin(gamaZ)) - (sin(betaY) * cos(alphaX) * cos(gamaZ));

	_rotationMatrix[0][1] = -sin(gamaZ) * cos(betaY);
	_rotationMatrix[1][1] = (-sin(alphaX) * sin(betaY) * sin(gamaZ)) + (cos(alphaX) * cos(gamaZ));
	_rotationMatrix[2][1] = (sin(alphaX) * cos(gamaZ)) + (sin(betaY) * sin(gamaZ) * cos(alphaX));

	_rotationMatrix[0][2] = sin(betaY);
	_rotationMatrix[1][2] = -sin(alphaX) * cos(betaY);
	_rotationMatrix[2][2] = cos(alphaX) * cos(betaY);
}
