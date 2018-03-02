#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 velocity;
layout(location = 2) in float life;

uniform float dt;
uniform float gameTime;
uniform vec2 translate;
uniform vec2 scale;

out vec3 newPosition;
out vec3 newVelocity;
out float newLife;

out float alpha;

void main(){

	gl_Position = vec4(position*vec3(scale, scale.x)+vec3(translate,0),1);
	alpha = (position*vec3(scale, scale.x)+vec3(translate,0)).z*4;
	
	vec3 acceleration = vec3(velocity.y,-velocity.x,velocity.y) + vec3(cos(gameTime)*velocity);

	if(life <= 0.0){
		newPosition = position;
		newVelocity = velocity;
		newLife = 2.0f+life;
	
	}else{
		newVelocity = 200*normalize(velocity + dt*acceleration);
		newPosition = 200*normalize(position+dt*newVelocity);
		newLife = life-dt;
	}
	


}