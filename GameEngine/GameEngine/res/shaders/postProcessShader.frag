#version 400 core

in vec2 uv;

uniform sampler2D ui;

uniform float ui_trans;
uniform float ui_blue;

void main(){
	vec4 color = texture(ui, uv) * vec4(1,1,1,ui_trans);
	color.xyz = (1-ui_blue)*color.xyz + ui_blue*vec3(0,0,1);
	gl_FragColor = color;
}
