cmake_minimum_required(VERSION 3.5)
project(Simulation)
set(SOURCE_FILES
	src/Intersectee.cpp
	src/Intersectable.cpp
	src/Updateable.cpp
	src/Algorithm.cpp
	include/simulation/SimulationObject.hpp
	include/simulation/Simulation.hpp
	include/simulation/Intersectee.hpp
	include/simulation/Intersectable.hpp
	src/SimulationObject.cpp
	include/simulation/Algorithm.hpp
	include/simulation/Updateable.hpp
	src/Simulation.cpp

	#2d
	src/2d/Map2d.cpp
	include/simulation/2d/Map2d.hpp
	src/2d/Robot2d.cpp
	include/simulation/2d/Robot2d.hpp
    src/2d/LaserRangeFinder2d.cpp
    include/simulation/2d/LaserRangeFinder2d.hpp
    src/2d/Wheels.cpp
    include/simulation/2d/Wheels.hpp
    src/2d/LaserScanner2d.cpp
    include/simulation/2d/LaserScanner2d.hpp
    include/simulation/IntersectionCalculator.hpp
)
add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory(../math ../math)
add_subdirectory(../utilities ../utilities)

target_link_libraries(${PROJECT_NAME} PUBLIC Math utilities)

