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

void main(){
	uv = texCoords;
	col = color;
	vec2 offset = vec2(0, position.z*cos(3*gameTime + uint(gl_VertexID / 6)));
	vec2 realPosition = position.xy * (text_scale*ui_scale) * vec2(1, aspect_ratio) + ((text_translate+4*offset)*ui_scale) - vec2(1, 1);
	gl_Position = vec4(realPosition,0,1);
}
