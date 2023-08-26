#include "Manipulator.h"

Manipulator::Manipulator() :
	_countLink{ 0 },
	_links(_countLink) 
{
}

void Manipulator::setCountLink(const unsigned short int _countLink)
{
	this->_countLink = _countLink + 1;
	_links.resize(this->_countLink);
}

void Manipulator::setAngleRotation(const std::vector<double> _angles)
{
	for (int i = 0; i < _countLink - 1; i++)
		_links[i].setAngleRotation(_angles[i]);
}

Link& Manipulator::getLink(const unsigned short int numberLink)
{
	return _links[numberLink];
}

void Manipulator::calculationTCP()
{
    double result[4][4] = {};
    for (int i = 0; i < 4; ++i) 
    {
        result[i][i] = 1.0;
    }

    double temp[4][4] = {};
    for (int i = 0; i < _countLink; i++)
    {
        multMatrix4x4(result, _links[i].getRelativePosition(), temp);
        std::memcpy(result, temp, sizeof(double) * 4 * 4);
    }
    std::memcpy(_hct, result, sizeof(double) * 4 * 4);
}

