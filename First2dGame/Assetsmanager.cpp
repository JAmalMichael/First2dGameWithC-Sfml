#include "Assetsmanager.h"



void AssetsManager::LoadTexture(const std::string& name, const std::string& path)
{
	sf::Texture tex;
	tex.loadFromFile(path);
	m_texture.emplace(name, std::move(tex));
}

void AssetsManager::LoadFont(const std::string& name, const std::string& path)
{
	sf::Font font;
	if (!font.loadFromFile(path))
		throw std::runtime_error("Failed to load font: " + path);

	m_fonts.emplace(name, std::move(font));
	/*/m_fonts[name].loadFromFile(path);
	sf::Font font;
	font.loadFromFile(path);
	m_fonts[name] = font;*/
}

void AssetsManager::LoadSound(const std::string& name, const std::string& path)
{
	sf::SoundBuffer sound;
	sound.loadFromFile(path);
	m_sounds.emplace(name, std::move(sound));
}

void AssetsManager::LoadMusic(const std::string& name, const std::string& path)
{
	auto music = std::make_unique<sf::Music>();

	if (!music->openFromFile(path))
		throw std::runtime_error("Failed to load music: " + path);

	m_music.emplace(name, std::move(music));
}


sf::Texture AssetsManager::GetTexture(const std::string& name)
{
	return m_texture[name];
}

sf::Font AssetsManager::GetFont(const std::string& name)
{
	return m_fonts[name];
}

sf::SoundBuffer AssetsManager::GetSound(const std::string& name)
{
	return m_sounds[name];
}

//sf::Music AssetsManager::GetMusic(const std::string& name)
//{
//	return *m_music.at(name);
//}