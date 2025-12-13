#include "Scene_Game.h"
#include "Game.h"


SceneGame::SceneGame(Game* game) : Scene(game) {
	m_font.loadFromFile("assets/fonts/Satoshi.ttf");
	m_label.setFont(m_font);
	m_label.setString("Game Scene — Press ESC to return to Menu | Press Enter to Load Game");
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

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
		{
			/*m_game->changeScene("GAMEOVER");*/
			m_assets.LoadTexture("player", "assets/character/Idle/Idle1.png");
			m_assets.LoadTexture("enemy", "assets/enemy/Idle/blackIdle1.png");
			/*m_assets.LoadTexture("tile", "assets/enemy/Idle/blackIdle1.png");*/
			m_assets.LoadTexture("background", "assets/structures/Background.png");
			//m_assets.LoadSound("slash", "assets/audio/slash.wav");

			m_assets.LoadMusic("bgs", "assets/audio/start.wav");

			m_assets.GetMusic("bgs").setLoop(false);
			m_assets.GetMusic("bgs").play();

			SpawnPlayer();
			SpawnEnemy();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_game->changeScene("MENU");
	}

}

void SceneGame::sRender()
{
	m_game->window().clear();
	m_game->window().draw(m_label);
	m_game->window().display();
}

void SceneGame::SpawnPlayer()
{
	auto p = m_entities.AddEntity("player");

	m_entities.AddComponent<CTransform>(
		p,
		sf::Vector2f(400, 300),
		sf::Vector2f(0, 0),
		sf::Vector2f(1, 1),
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
		e, sf::Vector2f(800, 300), sf::Vector2f(rand() % 3 - 1, rand() % 3 - 1), sf::Vector2f(1, 1), 0
	);

	m_entities.AddComponent<CSprite>(
		e, m_assets.GetTexture("enemy")
	);
}


void SceneGame::AddbackGround() {
	auto background = m_entities.AddEntity("background");

	m_entities.AddComponent<CSprite>(
		background, m_assets.GetTexture("background")
	);

	m_entities.AddComponent<CTransform>(
		background, sf::Vector2f(1000, 720), sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0
	);
}