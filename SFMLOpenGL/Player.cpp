#include "Player.h"

Player::Player():
	m_motion(0.0f, 0.0f,0.0f),
	m_gravity(-9.8f),
	m_acceleration(0.0f),
	jump(false),
	timesToJump(2),
	pixelsToMetres(100),
	m_time(0)
{

}

void Player::update(double t)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_motion.x = -20.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_motion.x = 20.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !jump && timesToJump > 0)
	{
		m_motion.y = 100.0f;
		jump = true;
		timesToJump--;
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && jump)
	{
		jump = false;
	}

	m_time = t;
}

float Player::Xdistance()
{
	m_acceleration = 1 * 0.8 * m_gravity; // a = m * res * g

	m_motion.x = m_motion.x - m_acceleration * m_time; // v = v - a * t

	if (m_motion.x < 5 && m_motion.x > -5) 
	{
		m_motion.x = 0;
	}

	return  (m_motion.x * m_time + 0.5 * m_acceleration * m_time * m_time)/ pixelsToMetres;
}

float Player::Ydistance()
{
	m_motion.y = m_motion.y + m_gravity * m_time; // v = v + a *t

	return (m_motion.y * m_time + 0.5 * m_gravity * m_time * m_time) / pixelsToMetres;
}