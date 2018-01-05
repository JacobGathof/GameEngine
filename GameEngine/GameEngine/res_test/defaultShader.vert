#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;
layout(location=2) in vec3 color;

out vec2 uv;
out vec3 col;

void main(){
	uv = texCoords;
	col = color;
	gl_Position = vec4(position,0,1);
}