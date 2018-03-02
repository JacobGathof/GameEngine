#version 400 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 velocity;
layout(location = 2) in float life;

uniform float dt;
uniform vec2 translate;
uniform vec2 scale;

out vec3 newPosition;
out vec3 newVelocity;
out float newLife;

out float alpha;

void main(){

	gl_Position = vec4(position*scale+translate,1);
	alpha = newLife;
	vec3 acceleration = vec3(0,0,0);

	if(life <= 0.0){
		newPosition = velocity;
		newVelocity = vec3(velocity.y, velocity.x, 0);
		newLife = 2.0f+life;
	
	}else{
		newVelocity = velocity+dt*acceleration;
		newPosition = position+dt*newVelocity;
		newLife = life-dt;
	}
	


}