#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;
layout(location=2) in vec3 color;

out vec2 uv;
out vec3 col;

uniform vec2 dim;
uniform vec2 text_scale;
uniform vec2 text_translate;
uniform float aspect_ratio;

void main(){
	uv = texCoords;
	col = color;
	gl_Position = vec4(position * text_scale * vec2(1, aspect_ratio) + text_translate - vec2(1, 1),0,1);
}