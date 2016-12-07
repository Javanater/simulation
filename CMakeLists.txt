cmake_minimum_required(VERSION 3.5)
project(Simulation)
set(SOURCE_FILES
		Intersectee.cpp
		Intersectable.cpp
		Updateable.cpp
		Algorithm.cpp
		SimulationObject.hpp
		Simulation.hpp
		Intersectee.hpp
		Intersectable.hpp
		SimulationObject.cpp
		Algorithm.hpp
		Updateable.hpp
		Simulation.cpp

		#2d
		2d/Map2d.cpp
		2d/Map2d.hpp
		2d/Robot2d.cpp
		2d/Robot2d.hpp 2d/LaserRangeFinder2d.cpp 2d/LaserRangeFinder2d.hpp 2d/Wheels.cpp 2d/Wheels.hpp 2d/LaserScanner2d.cpp 2d/LaserScanner2d.hpp IntersectionCalculator.hpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})