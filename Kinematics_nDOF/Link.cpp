#include "Link.h"

Link::Link() : 
	_kinematicPair{ kinematicPair::INDEFINED },
	_axisRotation{ axisRotation::INDEFINED },
	_systemStartNextLink(3, 0),
	_rotationMatrixM(4, std::vector<double>(4, 0)),
	_mhct(4, std::vector<double>(4, 0))
{
}

void Link::setSystemStartNextLink(const double X, const double Y, const double Z)
{
	_systemStartNextLink[0] = X;
	_systemStartNextLink[1] = Y;
	_systemStartNextLink[2] = Z;
}

void Link::setKinematicPair(kinematicPair _kinematicPair)
{
	this->_kinematicPair = _kinematicPair;
}

void Link::setAxisRotation(axisRotation _axisRotation)
{
	this->_axisRotation = _axisRotation;
}
