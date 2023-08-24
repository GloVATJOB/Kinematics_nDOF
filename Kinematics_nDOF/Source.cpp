#include <iostream>
#include "Manipulator.h"


int main()
{
	setlocale(LC_ALL, "ru");

	Manipulator scara;

	scara.setCountLink(4);

	scara.getLink(0).setKinematicPair(kinematicPair::ROTATIONAL);
	scara.getLink(1).setKinematicPair(kinematicPair::SPHERICAL);
	scara.getLink(2).setKinematicPair(kinematicPair::SPHERICAL);
	scara.getLink(3).setKinematicPair(kinematicPair::ROTATIONAL);

	scara.getLink(0).setAxisRotation(axisRotation::AXIS_Y);
	scara.getLink(1).setAxisRotation(axisRotation::AXIS_Z);
	scara.getLink(2).setAxisRotation(axisRotation::AXIS_Z);
	scara.getLink(3).setAxisRotation(axisRotation::AXIS_X);

	scara.getLink(0).setSystemStartNextLink(0, 0, 80);
	scara.getLink(1).setSystemStartNextLink(0, 0, 70);
	scara.getLink(2).setSystemStartNextLink(50, 0, 0);
	scara.getLink(3).setSystemStartNextLink(30, 0, 0);

	for (int i = 0; i < 4; i++)
		scara.getLink(i).setLinkÑonfiguration({ {1,0,0}, {0,1,0}, {0,0,1} });

	scara.setAngleRotation({ 0,0,0,0 });

	scara.calculationHCT();

	scara.printHCT();

	system("pause");
	return 1;
}