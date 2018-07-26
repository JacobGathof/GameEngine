#version 400 core

in vec2 uv;
in vec2 fragPos;
in vec2 sc;

uniform vec4 color;

void main(){

	vec2 d = fragPos/sc;
	float e = dot(d,d);
	uint a = uint(e < 1 && e > 1- 1./32);
	
	if(a < .5)
		discard;
	
	gl_FragColor = vec4(color.rgb,a);
	
}