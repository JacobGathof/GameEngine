#version 400 core

in vec2 uv;

uniform sampler2D ui;

uniform float ui_trans;

void main(){
	gl_FragColor = texture(ui, uv) * vec4(1,1,1,ui_trans);
}
