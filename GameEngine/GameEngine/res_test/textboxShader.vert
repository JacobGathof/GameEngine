#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

uniform vec2 dim;
uniform vec2 scale;
uniform vec2 pos;

void main(){
	gl_Position = vec4(2*(position*scale + pos)/dim - vec2(1, 1) ,0,1);
}