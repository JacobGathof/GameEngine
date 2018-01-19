#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;
layout(location=2) in vec3 color;

out vec2 uv;
out vec3 col;

uniform vec2 text_scale;
uniform vec2 text_translate;
const float aspect_ratio = 1/1;

const float scale = 1.0/512.0;

void main(){
	uv = texCoords;
	col = color;
	gl_Position = vec4(position * text_scale * vec2(1, aspect_ratio) + text_translate,0,1);
}