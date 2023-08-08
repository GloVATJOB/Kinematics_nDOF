#pragma once

#include <vector>

#include"Link.h"


class Manipulator
{
public:
	Manipulator();

	void setCountLink(const unsigned short int _countLink);

	Link& getLink(const unsigned short int numberLink);

private:
	//Количество звеньев
	//Count Link
	unsigned short int _countLink;

	//Звенья манипулятора
	//Manipulator links
	std::vector<Link> _links;

};

