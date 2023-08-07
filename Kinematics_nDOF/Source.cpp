#include <iostream>
#include "Link.h"


int main()
{
	Link l1;

	l1.setSystemStartNextLink(10, 20, 30);
	l1.setKinematicPair(kinematicPair::ROTATIONAL);

	system("pause");
	return 1;
}