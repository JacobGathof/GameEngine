#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec4 color;
layout(location=2) in float life;

out vec4 col;

void main(){

	gl_PointSize = 4.0f;
	col = color;
	gl_Position = vec4(position,0,1);
}
