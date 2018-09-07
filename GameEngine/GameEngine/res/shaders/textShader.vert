#version 400 core

layout(location=0) in vec3 position;
layout(location=1) in vec2 texCoords;
layout(location=2) in vec4 color;

out vec2 uv;
out vec4 col;

uniform vec2 text_scale;
uniform vec2 text_translate;
uniform float aspect_ratio;

uniform vec2 ui_scale;

uniform float gameTime;

/*
float rand(vec2 co){
	return .5 - fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
};
*/

void main(){
	uv = texCoords;
	col = color;
	vec2 offset = vec2(0, uint(!bool(uint(position.z)^1))*4*cos(3*gameTime + uint(gl_VertexID / 6)));
	
	//offset += uint(!bool(uint(position.z)^2)) * 8*4*gameTime * vec2(rand(vec2(uint(gl_VertexID / 6), 0)), rand(vec2(0, uint(gl_VertexID / 6))));
	
	vec2 realPosition = position.xy * (text_scale*ui_scale) * vec2(1, aspect_ratio) + ((text_translate+offset)*ui_scale) - vec2(1, 1);
	gl_Position = vec4(realPosition,0,1);
}

