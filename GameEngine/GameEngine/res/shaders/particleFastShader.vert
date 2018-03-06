#version 400 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 velocity;
layout(location = 2) in float life;

uniform float dt;
uniform float gameTime;
uniform vec2 translate;
uniform vec2 scale;

out vec2 newPosition;
out vec2 newVelocity;
out float newLife;

out float alpha;

void main(){

	gl_Position = vec4(position*vec2(scale)*vec2(1,1)+translate,position.y/800,1);
	alpha = 1;
	
	vec2 acceleration = vec2(velocity.y,-velocity.x) + vec2(cos(gameTime)*velocity);


	newVelocity = 200*normalize(velocity + dt*acceleration);
	newPosition = position+dt*newVelocity;
	newLife = life-dt;
	


}