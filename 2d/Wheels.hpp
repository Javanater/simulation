//
// Created by Madison on 8/25/2016.
//

#ifndef PROJECTS_WHEELS_HPP
#define PROJECTS_WHEELS_HPP

#include "Simulation/SimulationObject.hpp"
#include "Simulation/Updateable.hpp"
#include "Simulation/2d/Robot2d.hpp"

namespace flabs
{
	class Wheels : public virtual SimulationObject, public virtual Updateable
	{
		private:
			Robot2d& robot;
			double distanceBetweenWheels;
			double leftSpeed;
			double rightSpeed;

		public:
			static const char* TYPE;

			Wheels(Robot2d& robot, double distanceBetweenWheels);

			void setSpeed(double leftSpeed, double rightSpeed);

			virtual void
			update(double elapsedSeconds, double secondsSinceStart);
	};
}

#endif //PROJECTS_WHEELS_HPP
