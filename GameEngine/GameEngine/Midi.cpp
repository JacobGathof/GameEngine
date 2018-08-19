#include "Midi.h"
#include <iostream>
#include <string>
#include <fstream>


const char* Midi::notes[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

Midi::Midi(const char * filename)
{
	parseMidiFile(filename);

}

Midi::~Midi()
{
}

void Midi::update(float dt)
{
	bool keepRunning = true;
	lastEvent = 0;
	while (keepRunning) {
		if (midiPtr >= events.size()) {
			lastEvent = 0;
			return;
		}
		MidiEvent* ev = events[midiPtr];
		if (currentDeltaTime >= ev->deltaTime) {
			lastEvent = ev;
			midiPtr++;
		}
		else {
			keepRunning = false;
		}
	}

	currentDeltaTime += dt_per_qn * (1.0f / µs_per_qn) * µs_per_sec * dt;
}

void Midi::reset()
{
	midiPtr = 0;
	currentDeltaTime = 0;
}

MidiEvent* Midi::getLastEvent()
{
	return lastEvent;
}

void Midi::addEvent(MidiEvent* e)
{
	int dt = e->deltaTime;
	current_delta_time += dt;
	e->deltaTime = current_delta_time;


	events.push_back(e);
}


std::string Midi::numToNote(int n)
{
	int q = n % 12;
	const char* c = notes[q];
	int octave = n / 12 - 1;

	return std::string(c) + std::string("_") + std::to_string(octave);
}

void Midi::parseMidiFile(const char * filename)
{
	std::ifstream file;
	file.open(filename, file.binary | file.in);

	if (file.is_open()) {
		readHeader(file);
		readBody(file);

	}
	else {
		std::cout << "Could not open midi source" << std::endl;
	}
}

void Midi::readHeader(std::ifstream & file)
{
	char* data = new char[4];
	char* header = new char[4];

	file.read(header, 4);
	std::string str(header, 4);

	if (str == "MThd") {
		int chunkSize = 0;
		int formatType = 0;
		int numTracks = 0;
		int timeDivision = 0;

		int ticksPerQuarter = -1;
		int framesPerSecond = -1;
		int ticksPerFrame = -1;


		file.read(data, 4);
		chunkSize = ((int)data[0] << 24) + ((int)data[1] << 16) + ((int)data[2] << 8) + ((int)data[3]);

		file.read(data, 2);
		formatType = ((int)data[0] << 8) + ((int)data[1] << 0);

		file.read(data, 2);
		numTracks = ((int)data[0] << 8) + ((int)data[1] << 0);

		file.read(data, 2);
		timeDivision = ((int)data[0] << 8) + ((int)data[1] << 0);


		if (!(0x8000 & timeDivision)) {
			ticksPerQuarter = timeDivision;
		}
		else {
			ticksPerFrame = timeDivision & 0x00ff;
			framesPerSecond = (timeDivision & 0x7f00) << 8;
		}


		std::cout << "Chunk Size:" << chunkSize << std::endl;
		std::cout << "Format Type:" << formatType << std::endl;
		std::cout << "Number Tracks:" << numTracks << std::endl;
		std::cout << "Time Division:" << timeDivision << std::endl;
		std::cout << "	Ticks / Quarter:" << ticksPerQuarter << std::endl;
		std::cout << "	Frames / Second:" << framesPerSecond << std::endl;
		std::cout << "	Ticks / Frame:" << ticksPerFrame << std::endl;
		std::cout << std::endl;

	}
	else {
		std::cout << "No header found, malformed midi" << std::endl;
	}

	delete[] header;
	delete[] data;
}

void Midi::readBody(std::ifstream & file)
{
	char* data = new char[4];
	char* header = new char[4];

	file.read(header, 4);
	std::string str(header, 4);

	if (str == "MTrk") {
		int ptr = 0;

		unsigned int length = 0;
		file.read(data, 4);

		length = ((int)(unsigned char)data[0] << 24) + ((int)(unsigned char)data[1] << 16) + ((int)(unsigned char)data[2] << 8) + ((int)(unsigned char)data[3]);

		char* track = new char[length];
		file.read(track, length);

		while (ptr < length) {

			int deltaTime = 0;
			deltaTime = readVariableLength(ptr, track);

			int event_id = (int)((unsigned char)track[ptr]);
			if (event_id == 0xff) {
				processMetaEvent(ptr, track);
			}
			else if (event_id == 0xf0 || event_id == 0xf7) {
				std::cout << "Mistake";
			}
			else {
				MidiEvent* event = processMidiEvent(ptr, track);
				event->deltaTime = deltaTime;
				addEvent(event);
			}

		}


		delete[] track;

	}

	delete[] header;
	delete[] data;
}


int Midi::readVariableLength(int & ptr, char * track)
{
	unsigned int ret = 0;
	bool foundEnd = false;

	while (!foundEnd) {
		unsigned int current = (int)((unsigned char)track[ptr++]);
		if (current & 0x80) {
			ret = ret << 7;
			ret += (int)((unsigned char)(current & 0x7f));

		}
		else {
			ret = ret << 7;
			ret += (int)((unsigned char)(current & 0x7f));
			foundEnd = true;
		}
	}
	return ret;
}

MetaEvent Midi::processMetaEvent(int & ptr, char * track)
{
	ptr++;
	int event_type = (int)((unsigned char)track[ptr++]);
	int event_length = (int)readVariableLength(ptr, track);
	char* event_data = new char[event_length];
	std::memcpy(event_data, track + ptr, event_length);

	std::cout << "Event: " << std::hex << event_type << " " << event_length << " | ";
	for (int i = 0; i < event_length; i++) {
		std::cout << std::hex << (int)event_data[i] << " ";
	}
	std::cout << std::endl;

	ptr += event_length;

	delete[] event_data;

	return MetaEvent();
}


MidiEvent* Midi::processMidiEvent(int & ptr, char * track)
{
	int event_value = ((int)((unsigned char)track[ptr]) & 0xf0) >> 4;
	int channel = ((int)((unsigned char)track[ptr++]) & 0x0f) >> 4;
	int par1 = (int)((unsigned char)track[ptr++]);
	int par2 = (int)((unsigned char)track[ptr++]);

	return new MidiEvent(0, event_value, channel, par1, par2);
}


std::ostream & operator<<(std::ostream & os, MidiEvent & event)
{
	os << "Midi Event: " << event.eventValue << " | " << event.arg1 << " | " << event.arg2 << " | " << event.deltaTime;
	return os;
}

MidiEvent::MidiEvent(int dt, int val, int chan, int a1, int a2)
{
	deltaTime = dt;
	eventValue = val;
	eventChannel = chan;
	arg1 = a1;
	arg2 = a2;
}
