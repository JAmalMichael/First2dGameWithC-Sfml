#include "Scene_GameOver.h"
#include "Game.h"

SceneGameOver::SceneGameOver(Game* game) : Scene(game) {
	m_font.loadFromFile("assets/fonts/Satoshi.ttf");
	m_label.setFont(m_font);
	m_label.setString("GAME OVER — Press Enter to return to Menu");
	m_label.setFillColor(sf::Color::Red);
	m_label.setCharacterSize(24);
	m_label.setPosition(60, 250);
}

void SceneGameOver::update(float dt) {}

void SceneGameOver::onEnter() {};

void SceneGameOver::sInput() {
    sf::Event event;
    while (m_game->window().pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            m_game->window().close();


        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            m_game->changeScene("MENU");
    }
}

void SceneGameOver::sRender() {
    m_game->window().clear();
    m_game->window().draw(m_label);
    m_game->window().display();
}