#pragma once
#include "AbstractAction.h"

template<class T>
class SetAction : public AbstractAction
{
public:
	SetAction(T* ref, T val) {
		reference = ref;
		value = val;
	};
	~SetAction() {
	};
	virtual int run(float dt) {
		*reference = value;
		return 1;
	}
private:
	T * reference;
	T value;
};

