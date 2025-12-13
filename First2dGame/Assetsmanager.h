#pragma once
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML//Graphics.hpp"
#include <string>
#include <map>

class AssetsManager
{
	std::map<std::string, sf::Texture> m_texture;
	std::map<std::string, sf::Font> m_fonts;
	std::map<std::string, sf::SoundBuffer> m_sounds;
	std::map<std::string, std::unique_ptr<sf::Music>> m_music;


public:
	~AssetsManager() = default;

	void LoadTexture(const std::string& name, const std::string& path);
	void LoadFont(const std::string& name, const std::string& path);
	void LoadSound(const std::string& name, const std::string& path);
	void LoadMusic(const std::string& name, const std::string& path);

	sf::Texture GetTexture(const std::string& name);
	sf::Font GetFont(const std::string& name);
	sf::SoundBuffer GetSound(const std::string& name);
	sf::Music GetMusic(const std::string& name);
};