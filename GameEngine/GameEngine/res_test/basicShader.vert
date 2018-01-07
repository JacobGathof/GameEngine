#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform float scale;

void main(){
	uv = texCoords;
	gl_Position = vec4(position*scale,0,1);
}