#include "Link.h"

Link::Link() :
	_kinematicPair{ kinematicPair::INDEFINED },
	_axisRotation{ axisRotation::INDEFINED },
	_angleRotation{ 0 },
	_systemStartNextLink(3, 0),
	_mhct(4, std::vector<double>(4, 0)),
	_link—onfiguration(4, std::vector<double>(4, 0)),
	_relativePosition(4, std::vector<double>(4, 0))
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
	definitionPair(_kinematicPair);
}

void Link::setAxisRotation(axisRotation _axisRotation)
{
	this->_axisRotation = _axisRotation;
	definitionRotationMatrix(_axisRotation);
}

void Link::setLink—onfiguration(std::vector<std::vector<double>> _rotationMatrixM)
{
	this->_link—onfiguration = _rotationMatrixM;
	filling_mhct();
}

void Link::setAngleRotation(double _angleRotation)
{
	this->_angleRotation = _angleRotation;
}

void Link::calculationRelativePosition()
{
	(this->*calculationRotationMatrix)(_angleRotation);
	multMatrix4x4(_mhct, getRotationMatrix(), _relativePosition);
}

std::vector<std::vector<double>>& Link::getRelativePosition()
{
	calculationRelativePosition();
	return _relativePosition;
}

void Link::filling_mhct()
{
	for (int i = 0; i < _systemStartNextLink.size(); i++)
		_mhct[i][3] = _systemStartNextLink[i];

	for (int i = 0; i < _link—onfiguration.size(); i++)
		for (int j = 0; j < _link—onfiguration[i].size(); j++)
			_mhct[i][j] = _link—onfiguration[i][j];
	_mhct[3][3] = 1;
}
