/*
 * Algorithm.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: Madison
 */

#include <simulation/Algorithm.hpp>

using namespace std;

namespace flabs
{
	Algorithm::Algorithm()
	{
	}

	Algorithm::~Algorithm()
	{
	}

	set<SimulationObject*>& Algorithm::getSimulationObjects()
	{
		return simulationObjects;
	}

	set<Updateable*>& Algorithm::getUpdateables()
	{
		return updateables;
	}

	void Algorithm::update(double elapsedSeconds, double secondsSinceStart)
	{
		for (auto i = updateables.begin(); i != updateables.end(); ++i)
			(*i)->update(elapsedSeconds, secondsSinceStart);

		for (auto i = intersectees.begin(); i != intersectees.end(); ++i)
			(*i)->update(elapsedSeconds, secondsSinceStart,
				intersectionCalculator);
	}
}
