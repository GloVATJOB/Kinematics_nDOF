#include "Manipulator.h"

Manipulator::Manipulator() :
	_countLink{ 0 },
	_links(_countLink),
	_hct(4, std::vector<double>(4, 0))
{
}

void Manipulator::setCountLink(const unsigned short int _countLink)
{
	this->_countLink = _countLink;
	_links.resize(this->_countLink);
}

void Manipulator::setAngleRotation(std::vector<double> angles)
{
	for (int i = 0; i < _countLink; i++)
		_links[i].setAngleRotation(angles[i]);
}

Link& Manipulator::getLink(const unsigned short int numberLink)
{
	return _links[numberLink];
}

void Manipulator::calculationHCT()
{
	std::vector<std::vector<double>> A01 = _links[0].getRelativePosition();
	std::vector<std::vector<double>> A12 = _links[1].getRelativePosition();
	std::vector<std::vector<double>> A23 = _links[2].getRelativePosition();
	std::vector<std::vector<double>> A34 = _links[3].getRelativePosition();
	std::vector<std::vector<double>> A01x12(4, std::vector<double>(4));
	std::vector<std::vector<double>> A23x34(4, std::vector<double>(4));
	multMatrix4x4(_links[0].getRelativePosition(), _links[1].getRelativePosition(), A01x12);
	multMatrix4x4(_links[2].getRelativePosition(), _links[3].getRelativePosition(), A23x34);
}



