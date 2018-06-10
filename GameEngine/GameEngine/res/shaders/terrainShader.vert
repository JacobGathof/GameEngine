#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

out vec2 fragCoord;

void main(){
	uv = texCoords / (vec2(512,512)*camera_scale);
	fragCoord = .5/(vec2(512,512))*(-vec2(0, 0) + translate - camera_translate + vec2(1,-1)/camera_scale);
	gl_Position = vec4(position*2,0,1);
}
