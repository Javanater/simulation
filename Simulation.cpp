/*
 * Simulation.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: Madison
 */

#include "Simulation.h"
#include <chrono>
#include <Utilities/utilities.h>

using namespace std;

namespace flabs
{
	Simulation::Simulation(Algorithm& algorithm,
		double iterationPeriod) : algorithm(algorithm),
		iterationPeriod(iterationPeriod), timeScale(1), exited(false),
		paused(false), stepping(false), algoritmThread(NULL),
		secondsSinceStart(0)
	{
	}

	Simulation::~Simulation()
	{
	}

	void Simulation::run()
	{
		secondsSinceStart = 0;
		uint64_t lastTime = nanos();

		algorithm.setup();

		while (!exited)
		{
			uint64_t currentTime = nanos();
			double   elapsed     =
						 (currentTime - lastTime) * timeScale / 1000000000.;
			secondsSinceStart += elapsed;

			algorithm.update(elapsed, secondsSinceStart);
			algorithm.loop(elapsed, secondsSinceStart);

			// TODO: This kinda works, but slowly diverges...
			waitWhilePaused();
			lastTime = nanos();
			// TODO: Adjust sleep time to match period
			this_thread::sleep_for(
				chrono::nanoseconds((uint64_t) (iterationPeriod * 1000000000)));
		}
	}

	void Simulation::start()
	{
		unique_lock<mutex> lock(mutexVariable);
		exited         = false;
		paused         = false;
		stepping       = false;
		algoritmThread = new thread(&Simulation::run, this);
	}

	void Simulation::exit()
	{
		unique_lock<mutex> lock(mutexVariable);
		exited = true;
		condition.notify_all();
	}

	void Simulation::join()
	{
		// TODO: Thread safe join
		if (algoritmThread != NULL)
		{
			algoritmThread->join();
			delete algoritmThread;
			algoritmThread = NULL;
		}
	}

	void Simulation::pause()
	{
		unique_lock<mutex> lock(mutexVariable);
		paused = true;
	}

	bool Simulation::isPaused()
	{
		unique_lock<mutex> lock(mutexVariable);
		return paused;
	}

	void Simulation::resume()
	{
		unique_lock<mutex> lock(mutexVariable);
		paused = false;
		condition.notify_all();
	}

	void Simulation::step()
	{
		unique_lock<mutex> lock(mutexVariable);
		stepping = true;
		condition.notify_all();
	}

	void Simulation::waitWhilePaused()
	{
		unique_lock<mutex> lock(mutexVariable);
		stepping = false;

		while (paused && !stepping && !exited)
			condition.wait(lock);
	}

	double Simulation::getSecondsSinceStart()
	{
		return secondsSinceStart;
	}

	Algorithm& Simulation::getAlgorithm()
	{
		return algorithm;
	}
}
