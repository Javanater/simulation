/*
 * Intersectable.h
 *
 *  Created on: Mar 30, 2016
 *      Author: Madison
 */

#ifndef SIMULATION_INTERSECTABLE_H_
#define SIMULATION_INTERSECTABLE_H_

#include <Math/geometry/GeometryCalculator.h>

namespace flabs
{
	class Intersectable
	{
		public:
			Intersectable();

			virtual ~Intersectable();

			/**
			 * Takes a pointer to a Ray casted as a void*. It is the
			 * implementation's duty to ensure proper casting is
			 * performed. Returns numeric_limits<double>:: if no
			 * intersection is found. Returns the shortest distance
			 * to this object along the given ray if an intersection
			 * is found.
			 */
			virtual IntersectionType
			distance(const void* rayP, double& result) const = 0;
	};
}

#endif
