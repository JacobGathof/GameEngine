#pragma once
#include <map>

template <class T, typename Q>
class IManager
{
public:
	IManager() {};
	~IManager() {};

	virtual void init() = 0;

	virtual void clean() {
		for (auto t : elements) {
			delete t.second;
		};
	}

	T* get(Q q) {
		return elements[q];
	};

protected:
	std::map<Q, T*> elements;
};