//
// Created by Madison on 8/25/2016.
//

#include "LaserRangeFinder2d.hpp"
#include <cmath>
#include <Math/geometry/Ray.hpp>
#include <limits>

using namespace std;

namespace flabs
{
	const char* LaserRangeFinder2d::TYPE =
				  "com::fortenberryLabs::simulation::LaserRangeFinder2d";

	LaserRangeFinder2d::LaserRangeFinder2d(double maxRange, Robot2d& robot,
		const Vector2d offset, double angleOffset) : SimulationObject(TYPE),
		maxRange(maxRange), robot(robot), offset(offset),
		angleOffset(angleOffset), range(maxRange)
	{
	}

	void
	LaserRangeFinder2d::update(double elapsedSeconds, double secondsSinceStart,
		const IntersectionCalculator<2>& calculator)
	{
		double orientation = getOrientation();
		Ray2d  ray(getPosition(), {cos(orientation), sin(orientation)});
		range = calculator.distance(ray);
	}

	Vector2d LaserRangeFinder2d::getPosition()
	{
		Vector2d position = robot.getPosition();
		position[0] += offset[0] * cos(robot.getOrientation());
		position[1] += offset[1] * sin(robot.getOrientation());
		return position;
	}

	double LaserRangeFinder2d::getOrientation()
	{
		return robot.getOrientation() + angleOffset;
	}

	double LaserRangeFinder2d::getRange()
	{
		return range;
	}
}
