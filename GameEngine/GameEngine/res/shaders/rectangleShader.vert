#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

void main(){
	uv = texCoords;
	gl_Position = vec4(position*(scale*camera_scale)+((translate-camera_translate)*camera_scale),0,1);
}
