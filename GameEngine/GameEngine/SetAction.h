#pragma once
#include "AbstractScriptAction.h"

template<class T>
class SetAction : public AbstractScriptAction
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

