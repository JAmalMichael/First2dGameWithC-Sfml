#include "Scene_Game.h"
#include "Game.h"



SceneGame::SceneGame(Game* game) : Scene(game) {
	m_font.loadFromFile("assets/fonts/Satoshi.ttf");
	m_label.setFont(m_font);
	m_label.setString("Game Scene — Press ESC to return to Menu | Press keys to move player");
	m_label.setFillColor(sf::Color::Black);
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



void SceneGame::AddbackGround() {
	auto bg = m_entities.AddEntity("background");

	auto spr = m_entities.AddComponent<CSprite>(
		bg, m_assets.GetTexture("background")
	);

	//background origin set to 0
	spr->sprite.setOrigin(0.f, 0.f);

	
	//spr->sprite.setColor(sf::Color::White);

	//scaling background to window size
	const sf::Vector2u winSize = m_game->window().getSize();
	const sf::Vector2u texSize = m_assets.GetTexture("background").getSize();

	spr->sprite.setScale(
		static_cast<float>(winSize.x) / texSize.x,
		static_cast<float>(winSize.y) / texSize.y
	);

	m_entities.AddComponent<CTransform>(
		bg, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f
	);
} 



void SceneGame::SpawnPlayer()
{
	auto p = m_entities.AddEntity("player");

	m_entities.AddComponent<CTransform>(
		p,
		sf::Vector2f(400, 300),
		sf::Vector2f(0.f, 0.f),
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
		e, sf::Vector2f(800, 300), sf::Vector2f(rand() % 3 - 1, rand() % 3 - 1), 0
	);

	m_entities.AddComponent<CSprite>(
		e, m_assets.GetTexture("enemy")
	);
}


void SceneGame::onEnter()
{
	m_assets.LoadTexture("background", "assets/structures/Background.png");
	m_assets.LoadTexture("player", "assets/character/Idle/Idle1.png");
	m_assets.LoadTexture("enemy", "assets/enemy/Idle/blackIdle1.png");
	m_assets.LoadTexture("tile1", "assets/structures/Tile1.png");
	m_assets.LoadTexture("tile2", "assets/structures/Tile2.png");

	m_assets.LoadMusic("bgs", "assets/audio/start.wav");
	m_assets.GetMusic("bgs").play();

	AddbackGround();
	AddTileMap();
	SpawnPlayer();
	SpawnEnemy();

	std::cout << "SceneGame::onEnter called!" << std::endl;

	auto t1 = m_assets.GetTexture("player");
	std::cout << "Player texture size: " << t1.getSize().x << ", " << t1.getSize().y << std::endl;

	auto t2 = m_assets.GetTexture("enemy");
	std::cout << "Enemy texture size: " << t2.getSize().x << ", " << t2.getSize().y << std::endl;

	auto t3 = m_assets.GetTexture("background");
	std::cout << "Background texture size: " << t3.getSize().x << ", " << t3.getSize().y << std::endl;

	auto t4 = m_assets.GetTexture("tile1");
	std::cout << "Tile1 texture size: " << t4.getSize().x << ", " << t4.getSize().y << std::endl;

}

void SceneGame::AddTileMap()
{
	auto tileMap = m_entities.AddEntity("tilemap");

	auto tileComp = m_entities.AddComponent<CTileMap>(tileMap);


	tileComp->texture = &m_assets.GetTexture("tile1");
	tileComp->tileSize = 32;
	tileComp->width = 10;
	tileComp->height = 4;


	std::vector<int> level = {
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1
	};

	tileComp->vertices.resize(tileComp->width * tileComp->height * 4);

	//for (unsigned i = 0; i < tileComp->vertices.getVertexCount(); i++)
	//{
	//	tileComp->vertices[i].position = sf::Vector2f(0.f, 0.f);
	//	tileComp->vertices[i].texCoords = sf::Vector2f(0.f, 0.f);
	//}


	for (unsigned y = 0; y < tileComp->height; ++y)
	{
		for (unsigned x = 0; x < tileComp->width; ++x)
		{
			int tile = level[x + y * tileComp->width];
			if (tile == 0) continue;

			int tu = tile - 1;

			sf::Vertex* quad = &tileComp->vertices[(x + y * tileComp->width) * 4];

			quad[0].position = { x * 32.f, y * 32.f };
			quad[1].position = { (x + 1) * 32.f, y * 32.f };
			quad[2].position = { (x + 1) * 32.f, (y + 1) * 32.f };
			quad[3].position = { x * 32.f, (y + 1) * 32.f };

			quad[0].texCoords = { 0.f, 0.f };
			quad[1].texCoords = { 32.f, 0.f };
			quad[2].texCoords = { 32.f, 32.f };
			quad[3].texCoords = { 0.f, 32.f };

			quad[0].color = quad[1].color = quad[2].color = quad[3].color = sf::Color::White;

		}
	}
}

void SceneGame::sRender()
{
	m_game->window().clear(sf::Color::Black);
	//draw background first
	for (auto e : m_entities.GetEntities("background"))
	{
		auto spr = m_entities.GetComponent<CSprite>(e);
		auto trans = m_entities.GetComponent<CTransform>(e);

		if (spr && trans)
		{
			spr->sprite.setPosition(trans->position);
			m_game->window().draw(spr->sprite);
		}
	}

	//draw tile second
	t_render.render(m_entities, m_game->window());
	//draw other entities last
	m_render.render(m_entities, m_game->window());
	m_game->window().draw(m_label);
	m_game->window().display();
}


