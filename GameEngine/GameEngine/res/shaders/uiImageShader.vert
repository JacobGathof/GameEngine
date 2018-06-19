#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 ui_scale;

uniform vec2 dim;
uniform vec2 offset;


void main(){
	uv = (texCoords + offset) / dim;

	vec3 pos = vec3(position*(ui_scale*scale)+(translate*ui_scale) - vec2(1,1),0);


	gl_Position = vec4(pos,1);
}
