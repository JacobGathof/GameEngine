#pragma once
#include "IParticle.h"
#include "IParticleEmitterComponent.h"

template<class T>
class ParticleEmitter
{
public:

	ParticleEmitter() {};

	ParticleEmitter(std::initializer_list<IParticleEmitterComponent*> comps) {
		components = comps;
	};

	~ParticleEmitter() {
		for (auto a : components) {
			delete a;
		}
	};

	IParticle* createNewParticle(Vector2f& origin) {
		ParticleData data;
		data.position = origin;
		setupData(data);
		return new T(data);
	};

	void setupData(ParticleData& data) {
		for (auto a : components) {
			a->setupData(data);
		}
	};

	void addComponent(IParticleEmitterComponent* comp) {
		components.push_back(comp);
	};

	void setComponents(std::initializer_list<IParticleEmitterComponent*> comps) {
		components = comps;
	}

protected:
	
	std::vector<IParticleEmitterComponent*> components;

};

