#version 400 core

in vec2 uv;

uniform sampler2D ui;
uniform sampler2D world;

uniform float ui_trans;
uniform float ui_blue;

uniform vec4 screen_color;
uniform float screen_color_percent;

void main(){
	vec4 ui_color = texture(ui, uv) * vec4(1,1,1,ui_trans);
	vec4 world_color = texture(world, uv);

	ui_color.xyz = (1-ui_blue)*ui_color.xyz + ui_blue*vec3(0,0,1);
	gl_FragColor = (screen_color_percent*screen_color) +
								(1-screen_color_percent)*(ui_color + world_color);
}
