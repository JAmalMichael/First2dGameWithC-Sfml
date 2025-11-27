#include "Scene_Game.h"
#include "Game.h"

SceneGame::SceneGame(Game* game) : Scene(game) {
	m_font.loadFromFile("assets/fonts/Satoshi.ttf");
	m_label.setFont(m_font);
	m_label.setString("Game Scene — Press ESC to return to Menu");
	m_label.setFillColor(sf::Color::Yellow);
	m_label.setCharacterSize(24);
	m_label.setPosition(60, 20);
}

void SceneGame::update()
{
	//No gameplay yet
}

void SceneGame::sInput()
{
	sf::Event event;
	while (m_game->window().pollEvent(event))
	{
		if (event.type == sf::Event::Closed) m_game->window().close();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_game->changeScene("MENU");
	}

}

void SceneGame::sRender()
{
	m_game->window().clear();
	m_game->window().draw(m_label);
	m_game->window().display();
}