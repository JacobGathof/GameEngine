#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in float brightness;


uniform vec2 camera_translate;
uniform vec2 camera_scale;

uniform vec2 translate;
uniform vec2 scale;

out float bright;

void main(){
	vec2 pos = position;
	gl_Position = vec4(pos*(scale*camera_scale)+((translate-camera_translate)*camera_scale),0,1);
	bright = brightness;
}
