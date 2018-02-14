#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

void main(){
	uv = vec2(texCoords.x, -texCoords.y);
	gl_Position = vec4(position*2,0,1);
}
