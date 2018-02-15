#version 400 core

in vec2 uv;

uniform sampler2D ui;

void main(){
	gl_FragColor = texture(ui, uv) * vec4(1,1,1,.25);
}
