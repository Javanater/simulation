/*
 * Robot2d.h
 *
 *  Created on: Mar 28, 2016
 *      Author: Madison
 */

#ifndef SIMULATION_2D_ROBOT2D_H_
#define SIMULATION_2D_ROBOT2D_H_

#include <math/geometry/Vector.h>
#include <simulation/Updateable.hpp>
#include <simulation/SimulationObject.hpp>

namespace flabs
{
	class Robot2d: public virtual SimulationObject, public virtual Updateable
	{
		private:
			Vector2d position;
			double orientation;

		public:
			static const char* TYPE;
			Robot2d();
			virtual ~Robot2d();
			Vector2d& getPosition();
			double& getOrientation();
			virtual void update(double elapsedSeconds, double secondsSinceStart);
	};
}

#endif
