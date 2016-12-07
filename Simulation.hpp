/*
 * Simulation.h
 *
 *  Created on: Mar 23, 2016
 *      Author: Madison
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <mutex>
#include <condition_variable>
#include <thread>
#include "Algorithm.hpp"

#define SIMULAITON_DEFAULT_ITERATION_PERIOD .03333

namespace flabs
{
	class Simulation
	{
		private:
			Algorithm& algorithm;
			double iterationPeriod;
			double timeScale;
			volatile bool exited;
			volatile bool paused;
			volatile bool stepping;
			std::mutex mutexVariable;
			std::condition_variable condition;
			std::thread* algoritmThread;
			volatile double secondsSinceStart;

		public:

			/**
			 * Creates a simulation with a reference to an algorithm.
			 */
			Simulation(Algorithm& algorithm, double iterationPeriod =
			SIMULAITON_DEFAULT_ITERATION_PERIOD);

			virtual ~Simulation();

			/**
			 * Main simulation thread. Call this directly if you want to manage the threading yourself.
			 */
			void run();

			/**
			 * Resets all flags and calls run() in a new thread.
			 */
			void start();

			/**
			 * Sets the exit flag to signal the run() method to exit.
			 */
			void exit();

			/**
			 * Waits for the thread created by start() to finish.
			 */
			void join();

			/**
			 * Sets the pause flag to pause the run() method.
			 */
			void pause();

			/**
			 * Clears the pause flag to resume the run() method.
			 */
			void resume();

			/**
			 * Sets the stepping flag to allow the run() method to loop once if it is paused.
			 */
			void step();

			bool isPaused();

			double getSecondsSinceStart();

			Algorithm& getAlgorithm();

		private:
			void waitWhilePaused();
	};
}

#endif
