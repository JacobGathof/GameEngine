#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 dim;
uniform vec2 translate;
uniform vec2 scale;

void main(){
	uv = texCoords;
	gl_Position = vec4((position*scale+translate)/dim*800,0,1);
}