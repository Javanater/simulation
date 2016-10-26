/*
 * Intersectee.h
 *
 *  Created on: Mar 30, 2016
 *      Author: Madison
 */

#ifndef SIMULATION_INTERSECTEE_H_
#define SIMULATION_INTERSECTEE_H_

#include <set>
#include "Intersectable.h"
#include "IntersectionCalculator.hpp"

namespace flabs
{
	class Intersectee
	{
		public:
			Intersectee();
			virtual ~Intersectee();
			virtual void update(double elapsedSeconds, double secondsSinceStart,
			    const IntersectionCalculator<2>& calculator) = 0;
	};
}

#endif
