#include "Swarm.h"

Swarm::Swarm(): m_lastTime(0) { // initialise the variable m_lastRime in the constructor
	m_pParticle = new Particle[NPARTICLES]; // Any time the 'new' keyword is used, it must be deleted later on
}

Swarm::~Swarm() {
	delete[] m_pParticle; // Because the particle swarm is an array, we must delete in the destructor to free up memory
}

void Swarm::update(int elapsed) {

	int interval = elapsed - m_lastTime; // This helps to run the simulation suitable for the clock speed of all computers that run it

	for (int i = 0; i < Swarm::NPARTICLES; i++) { // Iterate through each individual particle and update
		m_pParticle[i].update(interval); // Updating the position of all the particles on every run of the game loop
	}
	m_lastTime = elapsed;
}
