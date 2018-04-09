#include "AudioLoader.h"
#include <iostream>


MusicEntity* AudioLoader::loadMusicFile(char * f)
{
	MusicEntity* entity = 0;

	unsigned char* d;
	unsigned int s;
	int sps;
	short ch;
	loadData(f, &d, &s, &sps, &ch);

	entity = new MusicEntity(d, s, sps, ch);

	delete[] d;

	return entity;
}


SoundEntity * AudioLoader::loadSoundFile(char * f)
{
	SoundEntity* entity = 0;

	unsigned char* d;
	unsigned int s;
	int sps;
	short ch;
	loadData(f, &d, &s, &sps, &ch);

	entity = new SoundEntity(d, s, sps, ch);

	delete[] d;

	return entity;
}

void AudioLoader::loadData(char * f, unsigned char ** d, unsigned int * s, int * sps, short * ch)
{
	std::ifstream file(f, std::ifstream::binary);

	if (!file.is_open()) {
		std::cout << "File: " << f << " could not be opened" << std::endl;
	}
	else {
		char chunkId[5] = "\0";
		unsigned int size = 0;

		file.read(chunkId, 4);
		file.read((char*)&size, 4);

		chunkId[4] = '\0';

		file.read(chunkId, 4);

		chunkId[4] = '\0';

		file.read(chunkId, 4);
		file.read((char*)&size, 4);

		chunkId[4] = '\0';

		short formatTag = 0;
		short channels = 0;
		int samplesPerSec = 0;
		int averageBytesPerSec = 0;
		short blockAlign = 0;
		short bitsPerSample = 0;

		file.read((char*)&formatTag, 2);
		file.read((char*)&channels, 2);
		file.read((char*)&samplesPerSec, 4);
		file.read((char*)&averageBytesPerSec, 4);
		file.read((char*)&blockAlign, 2);
		file.read((char*)&bitsPerSample, 2);

		if (size > 16) {
			file.seekg((int)file.tellg() + (size - 16));
		}

		file.read(chunkId, 4);
		file.read((char*)&size, 4);

		chunkId[4] = '\0';


		unsigned char* data = new unsigned char[size];

		file.read((char*)data, size);

		file.close();

		*d = data;
		*s = size;
		*sps = samplesPerSec;
		*ch = channels;
	}

}
