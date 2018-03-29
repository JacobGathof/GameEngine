#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec4 color;
layout(location=2) in float life;

out vec4 col;
out float li;
flat out uint circle;

uniform float halfLife;


void main(){

	float si = 2.0f;
	circle = 0;
	if(life <= halfLife){
		si = 16*(halfLife-life)/halfLife+2;
		circle = 1;
	}

	gl_PointSize = si;
	col = color;
	li = life;
	gl_Position = vec4(position,0,1);
}
