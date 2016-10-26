/*
 * Map2d.h
 *
 *  Created on: Mar 29, 2016
 *      Author: Madison
 */

#ifndef SIMULATION_2D_MAP2D_H_
#define SIMULATION_2D_MAP2D_H_

#include <list>
#include <limits>
#include <Math/geometry/LineSegment.h>
#include <Math/geometry/Ray.h>
#include "Simulation/SimulationObject.h"
#include "Simulation/Intersectable.h"

namespace flabs
{
	class Map2d : public virtual SimulationObject, public virtual Intersectable
	{
		private:
			std::list<LineSegment2d> walls;

		public:
			static const char* TYPE;

			Map2d();

			virtual ~Map2d();

			void addWall(LineSegment2d wall);

			void addWall(std::initializer_list<LineSegment2d> walls);

			std::list<LineSegment2d>& getWalls();

			virtual IntersectionType
			distance(const void* rayP, double& result) const;
	};
}

#endif
