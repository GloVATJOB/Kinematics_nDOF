#pragma once
#include <vector>

//Виды кинематических пар
enum class kinematicPair
{
	SPHERICAL,
	ROTATIONAL,
	TRANSLATIONAL,
	INDEFINED
};

//Ось вращения
enum class axisRotation
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z,
	INDEFINED
};

class Link
{
public:
	//Все функции в данном разделе временное решение, в скоре будет изменнно!!!
	//All functions in this section are a temporary solution, will be changed soon!!!!
	void crMi();

public:
	Link();
	void setSystemStartNextLink(const double X, const double Y, const double Z);
	void setKinematicPair(kinematicPair _kinematicPair);


private:
	void setAxisRotation();

private:
	//матрица поворота Mi {3x3}
	//rotation matrix Mi {3x3}
	std::vector<std::vector<double>> rotationMatrixM;

	//координаты начала системы следующего звена S -> S' {3}
	//coordinates of the system origin of the next link S->S' {3}
	//[0]=X [1]=Y [2]=Z
	std::vector<double> systemStartNextLink;

	//Кинематическая пара
	//Kinematic pair
	kinematicPair _kinematicPair = kinematicPair::INDEFINED;

	//Ось вращения
	//Rotational axis
	axisRotation _axisRotation = axisRotation::INDEFINED;

	//Матрица преобразования однородных координат
	//Homogeneous coordinate transformation matrix (mhct)
	std::vector<std::vector<double>> _mhct;
};

