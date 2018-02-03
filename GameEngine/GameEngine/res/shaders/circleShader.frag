#version 400 core

in vec2 uv;
in vec2 fragPos;
in vec2 sc;

void main(){

	if(dot(fragPos,fragPos) < .5*dot(sc,sc) && dot(fragPos,fragPos) > .5*dot(sc-vec2(.01,.01), sc-vec2(.01,.01))){
		gl_FragColor = vec4(0,0,0,1);
	}else{
		gl_FragColor = vec4(0,0,0,0);
	}
}