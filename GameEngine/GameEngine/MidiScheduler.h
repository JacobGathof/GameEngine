#pragma once
#include "Midi.h"

class MidiScheduler
{
public:
	static void init();
	static void clean();

	static void loadMidi(Midi* midi);
	static void update(float dt);
	static MidiEvent* queryMidiState();

private:
	static Midi* currentMidi;

};

