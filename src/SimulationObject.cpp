/*
 * SimulationObject.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: Madison
 */

#include <simulation/SimulationObject.hpp>

namespace flabs
{
	uint32_t SimulationObject::ID = 0;

	SimulationObject::SimulationObject(const std::string type) : type(type),
		id(ID++)
	{
	}

	SimulationObject::SimulationObject(const std::string type,
		uint32_t id) : type(type), id(id)
	{
	}

	SimulationObject::~SimulationObject()
	{
	}

	const std::string& SimulationObject::getType()
	{
		return type;
	}

	uint32_t SimulationObject::getID()
	{
		return id;
	}
}
