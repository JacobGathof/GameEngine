#include "AudioLoader.h"
#include <iostream>

ALCdevice* AudioLoader::device;
ALCcontext* AudioLoader::context;

AudioLoader::AudioLoader()
{
}


AudioLoader::~AudioLoader()
{
}

AudioEntity* AudioLoader::loadWavFile(char * f)
{
	AudioEntity* entity = 0;

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

		entity = new AudioEntity(data, size, samplesPerSec, channels);

		delete[] data;
	
	}

	file.close();

	return entity;
}

void AudioLoader::init()
{
	device = alcOpenDevice(0);
	if (!device)
		std::cout << "No device";
	context = alcCreateContext(device, 0);
	if (!context)
		std::cout << "No context";

	alcMakeContextCurrent(context);
}

void AudioLoader::clean()
{
	alcMakeContextCurrent(0);
	alcDestroyContext(context);
	alcCloseDevice(device);
}
