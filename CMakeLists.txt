cmake_minimum_required(VERSION 3.5)
project(Simulation)
set(SOURCE_FILES
		Intersectee.cpp
		Intersectable.cpp
		Updateable.cpp
		Algorithm.cpp
		SimulationObject.h
		Simulation.h
		Intersectee.h
		Intersectable.h
		SimulationObject.cpp
		Algorithm.h
		Updateable.h
		Simulation.cpp

		#2d
		2d/Map2d.cpp
		2d/Map2d.h
		2d/Robot2d.cpp
		2d/Robot2d.h 2d/LaserRangeFinder2d.cpp 2d/LaserRangeFinder2d.hpp 2d/Wheels.cpp 2d/Wheels.hpp 2d/LaserScanner2d.cpp 2d/LaserScanner2d.hpp IntersectionCalculator.hpp)
add_library(${PROJECT_NAME} ${SOURCE_FILES})