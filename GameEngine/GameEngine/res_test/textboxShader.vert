#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

const vec2 dim = vec2(800,800);
uniform vec2 scale;
uniform vec2 pos;

void main(){
	gl_Position = vec4((position+1)/2*scale/dim + pos/dim,0,1);
}