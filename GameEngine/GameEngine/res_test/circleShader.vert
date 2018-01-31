#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;
out vec2 fragPos;

uniform vec2 translate;
uniform vec2 scale;
uniform float gt;

void main(){
	uv = texCoords;
	gl_Position = vec4((position+translate)*scale * vec2(1, gt),0,1);
	fragPos = position*2;
}