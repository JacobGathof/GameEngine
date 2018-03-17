#version 400 core

in vec2 uv;

uniform sampler2D ui;
uniform sampler2D world;
uniform sampler2D lights;

uniform float ui_trans;
uniform float ui_blue;

uniform vec4 screen_color;
uniform float screen_color_percent;

void main(){
	vec4 ui_color = texture(ui, uv);
	vec4 world_color = texture(world, uv);

	ui_color.xyz = (1-ui_blue)*ui_color.xyz + vec3(0,0,ui_blue);

	vec4 finalColor = vec4(0,0,0,1);
	finalColor = world_color;
	finalColor = mix(finalColor, screen_color, screen_color_percent);
	vec4 uiColor = ui_color*ui_trans;
	finalColor = finalColor*(1-uiColor.a) + uiColor;
	//mix(finalColor, ui_color, .5);


	gl_FragColor = finalColor;
}
