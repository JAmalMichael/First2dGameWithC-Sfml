#include "SInput.h"

void SInput::update(float dt, EntityManager& em)
{
	for (auto& e : em.GetEntities())
	{
		if (em.GetComponent<CInput>(e))
		{
			auto* in = em.GetComponent<CInput>(e);
			if (!in) continue;

			in->up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
			in->down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
			in->left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
			in->right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
			in->slash = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		}
	}
}