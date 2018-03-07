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

const float InverseMaxInt = 1.0 / 4294967295.0;

float randhash(uint seed, float b)
{
    uint i=(seed^12345391u)*2654435769u;
    i^=(i<<6u)^(i>>26u);
    i*=2654435769u;
    i+=(i<<5u)^(i>>12u);
    return float(b * i) * InverseMaxInt;
}

void main(){

	gl_Position = vec4(position*vec2(scale)*vec2(1,1)+translate,0,1);
	alpha = 1;
	vec2 accel = vec2(-velocity.y, velocity.x);
	
	if(life <= 0.0){
		uint seed = uint(gameTime * 1000.0) + uint(gl_VertexID);
		float theta = randhash(seed++, 6.28);
		newPosition = 10*vec2(cos(theta),sin(theta));
		newVelocity = 10*newPosition;
		newLife = theta*3.0f;
	}
	else{
		newVelocity = velocity+dt*accel;
		newPosition = position+dt*newVelocity;
		newLife = life-dt;
	}

}