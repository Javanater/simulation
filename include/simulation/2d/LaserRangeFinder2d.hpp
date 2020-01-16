//
// Created by Madison on 8/25/2016.
//

#ifndef PROJECTS_LASERRANGEFINDER2D_HPP
#define PROJECTS_LASERRANGEFINDER2D_HPP

#include <simulation/SimulationObject.hpp>
#include <simulation/Intersectee.hpp>
#include "Robot2d.hpp"
#include <math/geometry/Vector.h>
#include <math/geometry/LineSegment.hpp>

namespace flabs
{
	class LaserRangeFinder2d : public virtual SimulationObject,
		public virtual Intersectee
	{
		private:
			double maxRange;
			Robot2d& robot;
			Vector2d offset;
			double   angleOffset;
			double   range;

		public:
			static const char* TYPE;

			LaserRangeFinder2d(double maxRange, Robot2d& robot,
				const Vector2d offset = {0, 0}, double angleOffset = 0);

			virtual void update(double elapsedSeconds, double secondsSinceStart,
				const IntersectionCalculator<2>& calculator);

			Vector2d getPosition();

			double getOrientation();

			double getRange();
	};
}

#endif //PROJECTS_LASERRANGEFINDER2D_HPP
