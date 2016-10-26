//
// Created by Madison on 8/25/2016.
//

#include "Wheels.hpp"
#include <cmath>

using namespace std;

namespace flabs
{
	const char* Wheels::TYPE = "com::fortenberryLabs::simulation::Wheels";

	Wheels::Wheels(flabs::Robot2d& robot,
		double distanceBetweenWheels) : SimulationObject(Wheels::TYPE),
		robot(robot), distanceBetweenWheels(distanceBetweenWheels)
	{
	}

	void Wheels::setSpeed(double leftSpeed, double rightSpeed)
	{
		this->leftSpeed  = leftSpeed;
		this->rightSpeed = rightSpeed;
	}

	void Wheels::update(double elapsedSeconds, double secondsSinceStart)
	{
		double leftDistance  = leftSpeed * elapsedSeconds;
		double rightDistance = rightSpeed * elapsedSeconds;
		double deltaTheta    =
				   (rightDistance - leftDistance) / distanceBetweenWheels;
		double deltaX, deltaY;
		if (deltaTheta != 0)
		{
			double turnRadius =
					   leftDistance / deltaTheta + distanceBetweenWheels / 2;
			deltaX = turnRadius * (cos(deltaTheta) - 1);
			deltaY = turnRadius * sin(deltaTheta);
		}
		else
		{
			deltaX = 0;
			deltaY = leftDistance;
		}
		robot.getPosition()[0] += deltaX * sin(robot.getOrientation()) +
			deltaY * cos(robot.getOrientation());
		robot.getPosition()[1] += deltaX * cos(robot.getOrientation()) +
			deltaY * sin(robot.getOrientation());
		robot.getOrientation() += deltaTheta;
	}
}
