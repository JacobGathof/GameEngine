#include "SoundManager.h"
#include "AudioLoader.h"

void SoundManager::init()
{
	addAudio(SoundType::SOUND_A_NOTE, "res/audio/note_a.wav");
}

void SoundManager::addAudio(SoundType type, char * filename)
{
	SoundEntity* entity = AudioLoader::loadSoundFile(filename);
	elements[type] = entity;
}
