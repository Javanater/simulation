/*
 * Map2d.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: Madison
 */

#include <simulation/2d/Map2d.hpp>
#include <limits>

using namespace std;

namespace flabs
{
	const char* Map2d::TYPE = "com::fortenberryLabs::simulation::Map2d";

	Map2d::Map2d() : SimulationObject(TYPE)
	{
	}

	Map2d::~Map2d()
	{
	}

	void Map2d::addWall(LineSegment2d wall)
	{
		walls.push_back(wall);
	}

	IntersectionType Map2d::distance(const void* rayP, double& result) const
	{
		const Ray2d& ray = *((const Ray2d*) rayP);
		result = numeric_limits<double>::infinity();
		IntersectionType intersectionType = NONE;
		double           currentDistance;
		IntersectionType currentIntersectionType;

		for (const LineSegment2d& wall : walls)
		{
			currentIntersectionType = ray.distance(wall, currentDistance);

			if (currentIntersectionType != NONE && currentDistance < result)
			{
				result           = currentDistance;
				intersectionType = currentIntersectionType;
			}
		}

		return intersectionType;
	}

	std::list<LineSegment2d>& Map2d::getWalls()
	{
		return walls;
	}

	void Map2d::addWall(std::initializer_list<LineSegment2d> walls)
	{
		for (const LineSegment2d& wall : walls)
			this->walls.push_back(wall);
	}
}
