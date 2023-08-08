#include <iostream>
#include "Manipulator.h"

int main()
{
	setlocale(LC_ALL, "ru");

	Manipulator scara;

	scara.setCountLink(3);

	scara.getLink(0).setKinematicPair(kinematicPair::ROTATIONAL);
	scara.getLink(1).setKinematicPair(kinematicPair::TRANSLATIONAL);
	scara.getLink(2).setKinematicPair(kinematicPair::SPHERICAL);

	scara.getLink(0).setAxisRotation(axisRotation::AXIS_Y);
	scara.getLink(1).setAxisRotation(axisRotation::AXIS_Y);
	scara.getLink(2).setAxisRotation(axisRotation::AXIS_Y);

	scara.getLink(0).setSystemStartNextLink(0, 0, 40);
	scara.getLink(1).setSystemStartNextLink(20, 0, 400);
	scara.getLink(2).setSystemStartNextLink(300, 0, -60);


	system("pause");
	return 1;
}
