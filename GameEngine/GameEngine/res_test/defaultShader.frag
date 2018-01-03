#version 400 core

in vec2 uv;

uniform sampler2D image;

void main(){

	vec4 color = texture(image, uv);

	gl_FragColor = color*vec4(0,0,0,1);
}