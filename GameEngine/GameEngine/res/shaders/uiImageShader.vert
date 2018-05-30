#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_scale;
uniform vec2 camera_translate;


void main(){
	uv = texCoords;

	vec3 pos = vec3(position*(camera_scale*scale)+(translate*camera_scale) - vec2(1,1),0);


	gl_Position = vec4(pos,1);
}
