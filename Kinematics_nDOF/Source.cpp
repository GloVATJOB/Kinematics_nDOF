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

	scara.getLink(1).setStart—oordinates(0, 0, 80);
	scara.getLink(2).setStart—oordinates(0, 0, 70);
	scara.getLink(3).setStart—oordinates(50, 0, 0);
	scara.getLink(4).setStart—oordinates(30, 0, 0);

	scara.getLink(0).setAxisRotation(axisRotation::AXIS_Y);
	scara.getLink(1).setAxisRotation(axisRotation::AXIS_Z);
	scara.getLink(2).setAxisRotation(axisRotation::AXIS_Z);
	scara.getLink(3).setAxisRotation(axisRotation::AXIS_X);

	for (int i = 0; i < 5; i++)
		scara.getLink(i).setLinkConfiguration({{ 1,0,0 }, { 0,1,0 }, { 0,0,1 }});

	scara.setAngleRotation({ 0,0,0,0 });

	scara.calculationTCP();

	system("pause");
	return 1;
}