#version 400 core

layout(location=0) in vec2 position;

uniform vec2 translate;
uniform vec2 scale;

uniform vec2 camera_translate;
uniform vec2 camera_scale;

uniform vec2[6] vertices;

void main(){
	vec2 pos = vertices[gl_VertexID]; 
	gl_Position = vec4(pos*(scale*camera_scale)+((translate-camera_translate)*camera_scale),0,1);
}
