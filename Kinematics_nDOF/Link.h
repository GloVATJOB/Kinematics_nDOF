#pragma once

#include <vector>

#include "RotationMatrix.h"
#include "MatrixOperations.h"

class Link : private RotationMatrix
{
public:
	Link();

	void setSystemStartNextLink(const double X, const double Y, const double Z);
	void setKinematicPair(kinematicPair _kinematicPair);
	void setAxisRotation(axisRotation _axisRotation);
	void setLinkСonfiguration(std::vector<std::vector<double>> _linkСonfiguration);
	void setAngleRotation(double _angleRotation);

	void calculationRelativePosition();

	std::vector<std::vector<double>>& getRelativePosition();

private:
	void filling_mhct();

private:
	//Кинематическая пара
	//Kinematic pair
	kinematicPair _kinematicPair;

	//Ось вращения
	//Rotational axis
	axisRotation _axisRotation;

	//координаты начала системы следующего звена S -> S' {3}
	//coordinates of the system origin of the next link S->S' {3}
	//[0]=X [1]=Y [2]=Z
	std::vector<double> _systemStartNextLink;

	//конфигурация звена системы Mi {3x3}
	//system link configuration Mi {3x3}
	std::vector<std::vector<double>> _linkСonfiguration;

	//Матрица преобразования однородных координат S -> S'
	//Homogeneous coordinate transformation matrix (mhct) S -> S'
	std::vector<std::vector<double>> _mhct;

	//Матрица относительного положения двух соседних звеньев
	//Relative position matrix of two neighboring links
	std::vector<std::vector<double>> _relativePosition;

	//Угол поворота звена
	//Angle of rotation of the link
	double _angleRotation;
};

