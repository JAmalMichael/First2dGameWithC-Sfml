#pragma once
//base system
#include "Tilemap.h"
#include "EntityManager.h"
#include "SFML/Graphics.hpp"

class System {
	virtual ~System() = default;
	virtual void init() {};
	virtual void update(float dt, EntityManager& em, Tilemap* tilemap = nullptr) = 0;
	virtual void render(sf::RenderWindow& window, EntityManager& em) {};
};

