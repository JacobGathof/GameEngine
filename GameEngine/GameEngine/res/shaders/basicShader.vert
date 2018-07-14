#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

void main(){
	gl_Position = vec4(position*2,0,1);
}
