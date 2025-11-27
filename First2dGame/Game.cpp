#include "Game.h"
#include "Scene_Menu.h"
#include "Scene_Game.h"
//#include "Scene_GameOver.h"

Game::Game(): m_window(sf::VideoMode(1280, 720), "TJMask")
{
	m_currentScene = "MENU";
	registerScene("MENU", std::make_shared<SceneMenu>(this));
	registerScene("GAME", std::make_shared<SceneGame>(this));
	//registerScene("GAMEOVER", std::make_shared<SceneGameOver>(this));
}

void Game::run() {
	while (m_window.isOpen()) {
		m_scenes[m_currentScene]->sInput();
		//m_scenes[m_currentScene]->update();
		m_scenes[m_currentScene]->sRender();
	}
}

void Game::changeScene(const std::string& name)
{
	m_currentScene = name;
}

void Game::registerScene(const std::string& name, std::shared_ptr<Scene> scene)
{
	m_scenes[name] = scene;
}