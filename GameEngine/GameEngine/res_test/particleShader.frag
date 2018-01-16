#version 400 core

in vec4 col;
in float li;

void main(){

	gl_FragColor = col * vec4(0,0,0,1);

}