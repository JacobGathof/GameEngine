#version 400 core

in vec2 uv;
in vec4 col;

uniform sampler2D image;
uniform vec4 text_color;

void main(){

	vec4 color = texture(image, uv);
	gl_FragColor = vec4(0,0,0,text_color.a*color.a) + vec4(text_color.xyz*(1-col.a) + col.xyz*col.a, 0);

}
