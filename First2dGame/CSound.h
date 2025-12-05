#pragma once
//steps, jump, coin pickup
#include "SFML/Audio.hpp"

struct CSound
{
	sf::Sound sound;
	sf::SoundBuffer* buffer = nullptr;

	CSound() {}
	CSound(sf::SoundBuffer* buff)
		: buffer(buff) {
		sound.setBuffer(*buffer);
	}
};