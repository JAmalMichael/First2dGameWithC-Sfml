#include "Scene_Game.h"
#include "Game.h"



SceneGame::SceneGame(Game* game) : Scene(game) {
	m_font.loadFromFile("assets/fonts/Satoshi.ttf");
	m_label.setFont(m_font);
	//m_label.setString("Game Scene — Press ESC to return to Menu | Press Enter to Load Game");
	m_label.setFillColor(sf::Color::Yellow);
	m_label.setCharacterSize(24);
	m_label.setPosition(60, 20);
}

void SceneGame::update()
{
	m_entities.update();
}

void SceneGame::sInput()
{
	sf::Event event;
	while (m_game->window().pollEvent(event))
	{
		if (event.type == sf::Event::Closed) m_game->window().close();
		/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
		}*/

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_game->changeScene("MENU");
	}

}


void SceneGame::onEnter()
{
	m_assets.LoadTexture("background", "assets/structures/Background.png");
	m_assets.LoadTexture("player", "assets/character/Idle/Idle1.png");
	m_assets.LoadTexture("enemy", "assets/enemy/Idle/blackIdle1.png");

	m_assets.LoadMusic("bgs", "assets/audio/start.wav");
	m_assets.GetMusic("bgs").play();

	AddbackGround();
	SpawnPlayer();
	SpawnEnemy();

	std::cout << "SceneGame::onEnter called!" << std::endl;

}


void SceneGame::AddbackGround() {
	auto bg = m_entities.AddEntity("background");

	auto sprite = m_entities.AddComponent<CSprite>(
		bg, m_assets.GetTexture("background")
	);

	//background origin set to 0
	sprite->sprite.setOrigin(0.f, 0.f);

	//tint background
	sprite->sprite.setColor(sf::Color(255, 255, 255, 180));

	//scaling background to window size
	const sf::Vector2u winSize = m_game->window().getSize();
	const sf::Vector2u texSize = m_assets.GetTexture("background").getSize();

	sprite->sprite.setScale(
		static_cast<float>(winSize.x) / texSize.x,
		static_cast<float>(winSize.y) / texSize.y
	);

	m_entities.AddComponent<CTransform>(
		bg, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), sf::Vector2f(0, 0), 0.f
	);
} 



void SceneGame::SpawnPlayer()
{
	auto p = m_entities.AddEntity("player");

	m_entities.AddComponent<CTransform>(
		p,
		sf::Vector2f(400, 300),
		sf::Vector2f(0, 0),
		sf::Vector2f(2.f, 2.f),
		0.f
	);

	m_entities.AddComponent<CSprite>(
		p,
		m_assets.GetTexture("player")
	);

	m_entities.AddComponent<CInput>(p);

}

void SceneGame::SpawnEnemy()
{
	auto e = m_entities.AddEntity("enemy");
	 
	m_entities.AddComponent<CTransform>(
		e, sf::Vector2f(800, 300), sf::Vector2f(rand() % 3 - 1, rand() % 3 - 1), sf::Vector2f(2.f, 2.f), 0
	);

	m_entities.AddComponent<CSprite>(
		e, m_assets.GetTexture("enemy")
	);
}

void SceneGame::sRender()
{
	m_game->window().clear();
	m_game->window().draw(m_label);
	m_render.render(m_entities, m_game->window());
	m_game->window().display();
}


