#version 400 core

in vec2 uv;
in vec2 fragPos;

uniform float radius;

void main(){

	if(dot(fragPos,fragPos) < radius*radius && dot(fragPos,fragPos) > (radius-.01)*(radius-.01)){
		gl_FragColor = vec4(0,0,0,1);
	}else{
		gl_FragColor = vec4(0,0,0,0);
	}
}