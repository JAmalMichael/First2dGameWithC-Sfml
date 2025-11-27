#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>

class Scene;

class Game
{
private:
	sf::RenderWindow m_window;
	std::map<std::string, std::shared_ptr<Scene>> m_scenes;
	std::string m_currentScene;

public:
	Game();
	void run();
	void changeScene(const std::string& name);
	void registerScene(const std::string& name, std::shared_ptr<Scene> scene);

	sf::RenderWindow& window() { return m_window; }
};