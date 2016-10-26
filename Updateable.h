/*
 * Updateable.h
 *
 *  Created on: Mar 23, 2016
 *      Author: Madison
 */

#ifndef UPDATEABLE_H_
#define UPDATEABLE_H_

#include "SimulationObject.h"

namespace flabs
{
	class Updateable : public virtual SimulationObject
	{
		public:
			using SimulationObject::SimulationObject;

			Updateable();

			virtual ~Updateable();

			virtual void
			update(double elapsedSeconds, double secondsSinceStart) = 0;
	};
}

#endif
