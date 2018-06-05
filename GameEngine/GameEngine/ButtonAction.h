#pragma once

#include "AbstractAction.h"

class FullscreenButtonAction : public AbstractAction {
public:
	virtual int run(float dt = 0.0f);
};


class NoteButtonAction : public AbstractAction {
public:
	virtual int run(float dt = 0.0f);
};

class MusicButtonAction : public AbstractAction {
public:
	virtual int run(float dt = 0.0f);
};

class UnpauseAction : public AbstractAction {
public:
	virtual int run(float dt = 0.0f);
};

class ExitAction : public AbstractAction {
public:
	virtual int run(float dt = 0.0f);
};


