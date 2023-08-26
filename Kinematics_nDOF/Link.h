#pragma once

#include <vector>

#include <corecrt_math_defines.h>

#include "RotationMatrix.h"
#include "MatrixOperations.h"

class Link : private RotationMatrix
{
public:
	Link();
	
	void setAngleRotation(const double _angleRotation);
	void setAxisRotation(const axisRotation _axisRotation);
	void setKinematicPair(const kinematicPair _kinematicPair);
	void setStart—oordinates(const double X, const double Y, const double Z);
	void setLinkConfiguration(const std::vector<std::vector<double>> _linkConfiguration);

	const double(&getRelativePosition())[4][4];

private:
	void calculationRelativePosition();

private:
	kinematicPair _kinematicPair;
	axisRotation _axisRotation;

	//coordinates of the beginning of the link relative to the previous link
	//[0]=X [1]=Y [2]=Z
	double _start—oordinates[3]{ 0,0,0 };

	//system link configuration Mi {3x3}
	double _linkConfiguration[3][3]{};

	//Angle of rotation of the link
	double _angleRotation;

	//Homogeneous coordinate transformation matrix (mhct) S -> S'
	double _mhct[4][4]{};

	//Relative position matrix of two neighboring links
	double _relativePosition[4][4]{};
};