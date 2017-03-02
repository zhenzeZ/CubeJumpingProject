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
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Player.h"
#include "Enemy.h"

using namespace std;
using namespace sf;
using namespace glm;

class Player;
class Enemy;

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
	Enemy m_enemy;

	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	sf::Clock  m_clock;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	float Xradius = 0;
	float Yradius = 0;
};

#endif