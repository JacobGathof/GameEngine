#version 400 core

uniform vec4 color;

in vec2 fragPos;

void main(){

	vec2 temp = fragPos;
	float d = dot(temp,temp);
	float f = 1 - d;

	gl_FragColor = color * vec4(1,1,1,smoothstep(0,1,f));

}
