#include "Manipulator.h"

Manipulator::Manipulator() :
	_countLink{ 0 },
	_links(_countLink),
	_hct(4, std::vector<double>(4, 0)),
	_mhct_0N(4, std::vector<double>(4, 0))
{
	for (int i = 0; i < 4; i++)
		_mhct_0N[i][i] = 1;
}

void Manipulator::setCountLink(const unsigned short int _countLink)
{
	this->_countLink = _countLink;
	_links.resize(this->_countLink);
}

void Manipulator::setAngleRotation(const std::vector<double> angles)
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
	_hct = _links[0].getRelativePosition();
	for (int i = 1; i < _countLink; i++)
		_hct = multMatrix4x4(_hct, _links[i].getRelativePosition());
}

#ifdef _TEST_
void Manipulator::printHCT()
{
	for (int i = 0; i < _hct.size(); i++)
	{
		for (int j = 0; j < _hct[i].size(); j++)
			std::cout << _hct[i][j] << "\t";
		std::cout << "\n";
	}
}
#endif // _TEST_

