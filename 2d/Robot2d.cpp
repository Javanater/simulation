/*
 * Robot2d.cpp
 *
 *  Created on: Mar 28, 2016
 *      Author: Madison
 */

#include "Robot2d.hpp"

namespace flabs
{
	const char* Robot2d::TYPE = "com::fortenberryLabs::simulation::Robot2d";

	Robot2d::Robot2d() :
			SimulationObject(TYPE), Updateable(), orientation(0)
	{
	}

	Robot2d::~Robot2d()
	{
	}

	Vector2d& Robot2d::getPosition()
	{
		return position;
	}

	double& Robot2d::getOrientation()
	{
		return orientation;
	}

	void Robot2d::update(double elapsedSeconds, double secondsSinceStart)
	{
	}
}
