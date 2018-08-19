#include "MidiScheduler.h"


Midi* MidiScheduler::currentMidi;

void MidiScheduler::loadMidi(Midi * midi)
{
	currentMidi = midi;
}

void MidiScheduler::update(float dt)
{
	if (currentMidi != 0) {
		currentMidi->update(dt);
	}
}

MidiEvent* MidiScheduler::queryMidiState()
{
	if (currentMidi == 0) {
		return 0;
	}
	return currentMidi->getLastEvent();
}

void MidiScheduler::init()
{
}

void MidiScheduler::clean()
{
}
