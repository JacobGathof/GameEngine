#version 400 core

in vec4 col;

void main(){

	gl_FragColor = col * vec4(1,1,1,1);

}
