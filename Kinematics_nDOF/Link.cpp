#include "Link.h"

void Link::crMi()
{
	for (int i = 0; i < rotationMatrixM.size(); i++)
		for (int j = 0; j < rotationMatrixM[i].size(); j++)
			rotationMatrixM[i][j] = 0;

	for (int i = 0; i < rotationMatrixM.size(); i++)
		rotationMatrixM[i][i] = 1;

	for (int i = 0; i < rotationMatrixM.size(); i++)
		for (int j = 0; j < rotationMatrixM[i].size(); j++)
			_mhct[i][j] = rotationMatrixM[i][j];
}

Link::Link()
{
	rotationMatrixM.resize(3);
	for (int i = 0; i < rotationMatrixM.size(); i++)
		rotationMatrixM[i].resize(3);

	systemStartNextLink.resize(3);

	_mhct.resize(4);
	for (int i = 0; i < _mhct.size(); i++)
		_mhct[i].resize(4);


	crMi();
}

void Link::setSystemStartNextLink(const double X, const double Y, const double Z)
{
	systemStartNextLink[0] = X;
	systemStartNextLink[1] = Y;
	systemStartNextLink[2] = Z;

	for (int i = 0; i < systemStartNextLink.size(); i++)
		_mhct[i][3] = systemStartNextLink[i];
}

void Link::setKinematicPair(kinematicPair _kinematicPair)
{
	this->_kinematicPair = _kinematicPair;
}

void Link::setAxisRotation()
{
}
