#version 400 core

in vec2 uv;
in vec3 col;

uniform sampler2D image;

void main(){

	vec4 color = texture(image, uv);
	gl_FragColor = color*vec4(col,1);

}