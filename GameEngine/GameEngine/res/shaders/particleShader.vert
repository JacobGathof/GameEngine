#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec4 color;
layout(location=2) in float life;

out vec4 col;
out float li;


void main(){
	gl_PointSize = 1.0f;
	col = color;
	li = life;
	gl_Position = vec4(position,0,1);
}