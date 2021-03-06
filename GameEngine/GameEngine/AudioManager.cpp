#include "AudioManager.h"
#include "AudioLoader.h"


void AudioManager::init()
{
	addSound(AudioType::SOUND_A_NOTE, "res/audio/note_a.wav");

	//addMusic(AudioType::SONG_FMAB_AGAIN, "res/audio/again_fmab_mono.wav");
	addMusic(AudioType::SONG_1, "res/audio/mus_vsasgore.wav");
	addMusic(AudioType::SONG_2, "res/audio/mus_x_undyne.wav");
}

void AudioManager::addSound(AudioType type, char * filename)
{
	SoundEntity* entity = AudioLoader::loadSoundFile(filename);
	elements[type] = entity;
}

void AudioManager::addMusic(AudioType type, char * filename)
{
	SoundEntity* entity = AudioLoader::loadMusicFile(filename);
	elements[type] = entity;
}
