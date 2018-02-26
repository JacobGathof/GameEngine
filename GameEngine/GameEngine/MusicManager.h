#pragma once
#include "AudioEntity.h"
#include <map>

enum class MusicType {
	SONG_FMAB_AGAIN,
};


class MusicManager
{
public:

	static void init();
	static void clean();
	static AudioEntity* get(MusicType type);

private:

	static void addAudio(MusicType type, char* filename);
	static std::map<MusicType, AudioEntity*> audios;

};
