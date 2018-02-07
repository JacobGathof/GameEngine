#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 translate;
uniform vec2 scale;

void main(){
	uv = vec2(texCoords.x, 1-texCoords.y);
	gl_Position = vec4(position*scale+translate - vec2(1,1),0,1);
}