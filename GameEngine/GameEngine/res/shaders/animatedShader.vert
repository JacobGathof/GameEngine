#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;
out vec2 sc;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

uniform int rows;
uniform int columns;
uniform int currentRow;
uniform int currentColumn;

uniform float rotation;

void main(){
	vec2 pos = position * mat2(cos(rotation), -sin(rotation), sin(rotation), cos(rotation));
	sc = scale;
	uv = (texCoords+vec2(currentColumn, currentRow)) / vec2(columns, rows);
	gl_Position = vec4(pos*(scale*camera_scale)+((translate-camera_translate)*camera_scale),0,1);
}
