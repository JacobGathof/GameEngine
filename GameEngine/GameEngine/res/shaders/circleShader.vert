#version 400 core

layout(location=0) in vec2 position;
layout(location=1) in vec2 texCoords;

out vec2 uv;
out vec2 fragPos;
out vec2 sc;

uniform vec2 translate;
uniform vec2 scale;
uniform float gt;

/*Will not work in the future. !!! camera scale and camera translate must be integrated */


void main(){
	uv = texCoords;
	gl_Position = vec4((position*scale+translate) * vec2(1, gt),0,1);
	fragPos = position*2;
	sc = scale;
}
