#pragma once
#include <vector>

//Виды кинематических пар
enum class kinematicPair
{
	INDEFINED,
	SPHERICAL,
	ROTATIONAL,
	TRANSLATIONAL
};

//Ось вращения
enum class axisRotation
{
	INDEFINED,
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

class Link
{
public:
	Link();

	void setSystemStartNextLink(const double X, const double Y, const double Z);
	void setKinematicPair(kinematicPair _kinematicPair);
	void setAxisRotation(axisRotation _axisRotation);

private:
	//Кинематическая пара
	//Kinematic pair
	kinematicPair _kinematicPair;

	//Ось вращения
	//Rotational axis
	axisRotation _axisRotation = axisRotation::INDEFINED;

	//координаты начала системы следующего звена S -> S' {3}
	//coordinates of the system origin of the next link S->S' {3}
	//[0]=X [1]=Y [2]=Z
	std::vector<double> _systemStartNextLink;

	//матрица поворота Mi {3x3}
	//rotation matrix Mi {3x3}
	std::vector<std::vector<double>> _rotationMatrixM;

	//Матрица преобразования однородных координат
	//Homogeneous coordinate transformation matrix (mhct)
	std::vector<std::vector<double>> _mhct;
};

