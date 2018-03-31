#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;
out vec2 uv2;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

void main(){
	uv = texCoords;
	vec2 pos = position*(scale*camera_scale)+((translate-camera_translate)*camera_scale);

	vec2 pos2 = vec2(1,1)*(vec2(position.x, -position.y)*(scale*camera_scale)+((translate+vec2(0,512)-camera_translate)*camera_scale));

	uv2 = (pos2+1)/2;

	gl_Position = vec4(pos,0,1);
}
