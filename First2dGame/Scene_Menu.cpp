#include "Game.h"
#include "Scene_Menu.h"

SceneMenu::SceneMenu(Game* game) : Scene(game) 
{
	//m_font.loadFromFile("assets/fonts/arial.tff");
	m_font.loadFromFile("assets/fonts/Satoshi.ttf");
	m_title.setFont(m_font);
	m_title.setString("HydesSyde Demo  Press Enter to Start ->");
	m_title.setFillColor(sf::Color::Black);
	m_title.setCharacterSize(42);
	m_title.setPosition(120, 250);
}

void SceneMenu::update(float dt) {
	//static menu
};

void SceneMenu::onEnter() {};


void SceneMenu::sInput() {
	sf::Event event;
	while (m_game->window().pollEvent(event))
		{
			if (event.type == sf::Event::Closed) m_game->window().close();
			
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) m_game->changeScene("GAME");

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_game->window().close();
		}
}

void SceneMenu::sRender() {
	m_game->window().clear(sf::Color::Blue);
	m_game->window().draw(m_title);
	m_game->window().display();
}