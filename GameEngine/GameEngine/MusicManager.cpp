#include "MusicManager.h"
#include "AudioLoader.h"


void MusicManager::init()
{
	//addAudio(MusicType::SONG_FMAB_AGAIN, "res/audio/again_fmab_mono.wav");
}

void MusicManager::addAudio(MusicType type, char * filename)
{
	AudioEntity* entity = AudioLoader::loadWavFile(filename);
	elements[type] = entity;
}
