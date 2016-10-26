/*
 * SimulationObject.h
 *
 *  Created on: Mar 30, 2016
 *      Author: Madison
 */

#ifndef SIMULATION_SIMULATIONOBJECT_H_
#define SIMULATION_SIMULATIONOBJECT_H_

#include <string>

namespace flabs
{
	class SimulationObject
	{
		private:
			// TODO: id should be generated by Simulation or Algorithm
			std::string     type;
			static uint32_t ID;
			uint32_t        id;

		public:
			SimulationObject() = default;

			SimulationObject(const std::string type);

			SimulationObject(const std::string type, uint32_t id);

			virtual ~SimulationObject();

			const std::string& getType();

			uint32_t getID();
	};
}

#endif
