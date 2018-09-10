#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

uniform vec2 scale;
uniform vec2 translate;

uniform vec2 ui_scale;

uniform vec2 points[2];

void main(){
	vec2 pos = points[gl_VertexID]; 
	gl_Position = vec4(pos*(scale*ui_scale) + (translate*ui_scale) - vec2(1, 1), 0, 1);
}
