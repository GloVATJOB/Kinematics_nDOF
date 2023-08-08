#include "Manipulator.h"

Manipulator::Manipulator() :
	_countLink{ 0 },
	_links(_countLink)
{
}

void Manipulator::setCountLink(const unsigned short int _countLink)
{
	this->_countLink = _countLink;
	_links.resize(this->_countLink);
}

Link& Manipulator::getLink(const unsigned short int numberLink)
{
	return _links[numberLink];
}



