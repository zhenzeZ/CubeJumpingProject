#pragma once
#include "Vector3.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Player
{
public:
	Player();

	void update(double t);

	float Xdistance();
	float Ydistance();
private:
	sf::Vector3f m_motion;
	float m_gravity;
	float m_acceleration;
	float m_time;

	bool jump;
	int timesToJump;
	int pixelsToMetres;
};