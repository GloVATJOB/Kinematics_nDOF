#include "Link.h"

Link::Link() :
	_kinematicPair(kinematicPair::INDEFINED),
	_axisRotation(axisRotation::INDEFINED),
	_angleRotation(0) 
{}

void Link::setKinematicPair(const kinematicPair _kinematicPair)
{
	this->_kinematicPair = _kinematicPair;
	definitionPair(_kinematicPair);
}

void Link::setAxisRotation(const axisRotation _axisRotation)
{
	this->_axisRotation = _axisRotation;
	definitionRotationMatrix(_axisRotation);
}

void Link::setStart—oordinates(const double X, const double Y, const double Z)
{
	_start—oordinates[0] = X;
	_start—oordinates[1] = Y;
	_start—oordinates[2] = Z;

	for (int i = 0; i < 3; i++)
		_mhct[i][3] = _start—oordinates[i];
}

void Link::setLinkConfiguration(const std::vector<std::vector<double>> _linkConfiguration)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			this->_linkConfiguration[i][j] = _linkConfiguration[i][j];
			_mhct[i][j] = this->_linkConfiguration[i][j];
		}
}

const double(&Link::getRelativePosition())[4][4]
{
	return _relativePosition;
}

void Link::setAngleRotation(const double _angleRotation)
{
	this->_angleRotation = _angleRotation * M_PI / 180;
	(this->*RotationMatrix::calculationRotationMatrix)(_angleRotation);
	calculationRelativePosition();
}

void Link::calculationRelativePosition()
{
	multMatrix4x4(_mhct, getRotationMatrix(), _relativePosition);
}