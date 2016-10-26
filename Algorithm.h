/*
 * Algorithm.h
 *
 *  Created on: Mar 23, 2016
 *      Author: Madison
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <set>
#include "Updateable.h"
#include "SimulationObject.h"
#include "Intersectable.h"
#include "Intersectee.h"
#include "IntersectionCalculator.hpp"

namespace flabs
{
	class Algorithm
	{
		private:
			std::set<SimulationObject*> simulationObjects;
			std::set<Updateable*>       updateables;
			std::set<Intersectable*>    intersectables;
			std::set<Intersectee*>      intersectees;
			IntersectionCalculator<2>   intersectionCalculator;

		public:
			Algorithm();

			virtual ~Algorithm();

			template<class T>
			bool add(T& object)
			{
				bool added = false;

				SimulationObject* simulationObject =
									dynamic_cast<SimulationObject*>(&object);
				if (simulationObject)
				{
					added = true;
					simulationObjects.insert(simulationObject);
				}

				Updateable* updateable = dynamic_cast<Updateable*>(&object);
				if (updateable)
				{
					added = true;
					updateables.insert(updateable);
				}

				Intersectable
					* intersectable = dynamic_cast<Intersectable*>(&object);
				if (intersectable)
				{
					added = true;
					intersectables.insert(intersectable);
					intersectionCalculator.addIntersectable(*intersectable);
				}

				Intersectee* intersectee = dynamic_cast<Intersectee*>(&object);
				if (intersectee)
				{
					added = true;
					intersectees.insert(intersectee);
				}

				return added;
			}

			std::set<SimulationObject*>& getSimulationObjects();

			std::set<Updateable*>& getUpdateables();

			void update(double elapsedSeconds, double secondsSinceStart);

			virtual void setup() = 0;

			virtual void
			loop(double elapsedSeconds, double secondsSinceStart) = 0;
	};
}

#endif
