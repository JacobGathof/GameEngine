#version 400 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 velocity;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

out float alpha;
out vec3 color;

void main(){
	alpha = velocity.w;
	color = velocity.xyz;

	
	gl_PointSize = 2.0f;
	gl_Position = vec4(position.xy*(scale*camera_scale)+((translate-camera_translate)*camera_scale),0,1);

}