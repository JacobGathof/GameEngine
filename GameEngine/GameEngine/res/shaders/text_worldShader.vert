#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;
layout(location=2) in vec4 color;

out vec2 uv;
out vec4 col;

uniform vec2 text_scale;
uniform vec2 text_translate;
uniform float aspect_ratio;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

void main(){
	uv = texCoords;
	col = color;
	gl_Position = vec4(position * (text_scale*camera_scale) * vec2(1, aspect_ratio) + ((text_translate-camera_translate)*camera_scale),0,1);
}
