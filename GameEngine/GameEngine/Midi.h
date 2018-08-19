#pragma once
#include <vector>

#define NOTE_OFF			0x8
#define NOTE_ON				0x9
#define NOTE_AFTERTOUCH		0xA
#define CONTROLLER			0xB
#define PROGRAM_CHANGE		0xC
#define CHANNEL_AFTERTOUCH	0xD
#define PITCH_BEND			0xE


class MidiEvent {
public:

	MidiEvent(int dt, int val, int chan, int a1, int a2);

	int deltaTime;

	int eventValue;
	int eventChannel;

	int arg1;
	int arg2;

	friend std::ostream& operator<<(std::ostream& os, MidiEvent& event);
};


class MetaEvent {

};


class Midi
{
public:
	Midi(const char* filename);
	~Midi();
	void update(float dt);
	void reset();
	MidiEvent* getLastEvent();

private:

	void parseMidiFile(const char* filename);
	void readHeader(std::ifstream& file);
	void readBody(std::ifstream& file);
	int readVariableLength(int& ptr, char* track);
	MetaEvent processMetaEvent(int& ptr, char* track);
	MidiEvent* processMidiEvent(int& ptr, char* track);

	std::string numToNote(int n);
	static const char* notes[];


	int µs_per_qn = 500000;
	int µs_per_sec = 1000000;

	std::vector<MidiEvent*> events;
	int current_delta_time;
	void addEvent(MidiEvent* e);

	int midiPtr = 0;
	float currentDeltaTime = 0;
	int dt_per_qn = 96;

	MidiEvent* lastEvent;
};

