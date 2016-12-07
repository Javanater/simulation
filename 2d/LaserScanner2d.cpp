//
// Created by Madison on 8/30/2016.
//

#include "LaserScanner2d.hpp"
#include <Math/geometry/Ray.hpp>

using namespace std;

namespace flabs
{
	const char* LaserScanner2d::TYPE =
				  "flabs::LaserScanner2d";

	LaserScanner2d::LaserScanner2d(double maxRange, double fieldOfView,
		uint32_t beamCount, flabs::Robot2d& robot) : SimulationObject(TYPE),
		maxRange(maxRange), fieldOfView(fieldOfView), beamCount(beamCount),
		robot(robot)
	{
	}

	void LaserScanner2d::update(double elapsedSeconds, double secondsSinceStart,
		const IntersectionCalculator<2>& calculator)
	{
//		double orientation = getOrientation();
//		Ray2d  ray(getPosition(), {cos(orientation), sin(orientation)});
//		range = maxRange;
//		for (Intersectable* intersectable : intersectables)
//		{
//			double distance;
//			if (intersectable->distance(&ray, distance) == INTERSECT)
//				if (distance < range)
//					range = distance;
//		}
	}

	Vector2d LaserScanner2d::getPosition()
	{
		return flabs::Vector2d();
	}

	double LaserScanner2d::getOrientation()
	{
		return 0;
	}
}
