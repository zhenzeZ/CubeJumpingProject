#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Vector3.h"
#include "Matrix3.h"

#include <Debug.h>
#include "Player.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:
	Window window;
	Player m_player;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	sf::Vector3f m_cubePoints[24];
	sf::Vector3f m_movement;

	sf::Clock  m_clock;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	float Xradius = 0;
	float Yradius = 0;
};

#endif