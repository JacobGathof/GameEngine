#version 400 core

in vec2 uv;

uniform sampler2D image;
uniform vec4 color;

void main(){
	gl_FragColor = texture(image, uv) * color;
}
