#include "MusicManager.h"
#include "AudioLoader.h"

std::map<MusicType, AudioEntity*> MusicManager::audios;

void MusicManager::init()
{
	//addAudio(MusicType::SONG_FMAB_AGAIN, "res/audio/again_fmab_mono.wav");
}

void MusicManager::clean()
{
	for (auto pair : audios) {
		delete pair.second;
	}
}

AudioEntity * MusicManager::get(MusicType type)
{
	return audios[type];
}

void MusicManager::addAudio(MusicType type, char * filename)
{
	AudioEntity* entity = AudioLoader::loadWavFile(filename);
	audios[type] = entity;
}
