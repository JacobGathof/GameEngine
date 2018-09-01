#include "AbstractObjectComponent.h"
#include "Object.h"



void AbstractObjectComponent::setParent(Object * obj){
	parent = obj;
}

Object * AbstractObjectComponent::getParent(){
	return parent;
}
