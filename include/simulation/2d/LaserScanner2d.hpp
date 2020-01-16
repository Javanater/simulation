//
// Created by Madison on 8/30/2016.
//

#ifndef PROJECTS_LASERSCANNER2D_HPP
#define PROJECTS_LASERSCANNER2D_HPP

#include <simulation/SimulationObject.hpp>
#include <simulation/Intersectee.hpp>
#include "Robot2d.hpp"
#include <math/geometry/Vector.h>
#include <math/geometry/LineSegment.hpp>

namespace flabs
{
	class LaserScanner2d : public virtual SimulationObject,
		public virtual Intersectee
	{
		private:
			double maxRange;
			double fieldOfView;
			uint32_t beamCount;
			Robot2d& robot;

		public:
			static const char* TYPE;

			LaserScanner2d(double maxRange,
				double fieldOfView, uint32_t beamCount, Robot2d& robot);

			virtual void update(double elapsedSeconds, double secondsSinceStart,
				const IntersectionCalculator<2>& calculator);

			Vector2d getPosition();

			double getOrientation();
	};
}

#endif //PROJECTS_LASERSCANNER2D_HPP
