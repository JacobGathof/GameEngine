#version 400 core

in vec4 col;
in float li;

void main(){

	gl_FragColor = col * vec4(1,1,1,li/4.0);

}