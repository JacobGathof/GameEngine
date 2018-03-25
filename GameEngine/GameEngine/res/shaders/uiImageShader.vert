#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_scale;
uniform vec2 camera_translate;

uniform float yangle;

void main(){
	float c = cos(yangle);
	float s = sin(yangle);

	uv = texCoords;

	vec2 p = position;
	p = p - vec2(.5, .5);
	p =  vec2(c*p.x + 0, p.y);
	p = p + vec2(.5, .5);

	vec3 pos = vec3(p*(camera_scale*scale)+(translate*camera_scale) - vec2(1,1),0);


	gl_Position = vec4(pos,1);
}
