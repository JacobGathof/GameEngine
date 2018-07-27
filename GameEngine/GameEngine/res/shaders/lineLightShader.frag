#version 400 core

in float bright;

void main(){
	gl_FragColor = vec4(1,1,1,bright);

}
