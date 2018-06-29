#version 400 core

in vec2 uv;

uniform sampler2D ui;
uniform sampler2D world;
uniform sampler2D effects;

uniform float ui_trans;
uniform float ui_blue;

uniform vec4 screen_color;
uniform float screen_color_percent;

void main(){
	vec4 ui_color = texture(ui, uv);
	vec4 world_color = texture(world, uv);
	vec4 effects_color = texture(effects, uv);

	vec4 finalColor = vec4(0,0,0,1);
	finalColor = world_color;

	finalColor = mix(finalColor, effects_color, effects_color.a);
	//finalColor = finalColor*(1-effects_color.a) + effects_color*(effects_color.a);
	
	finalColor = mix(finalColor, screen_color, screen_color_percent);
	
	vec4 uiColor = ui_color*ui_trans;
	finalColor = finalColor*(1-uiColor.a) + uiColor;
	//mix(finalColor, ui_color, .5);


	gl_FragColor = finalColor;
}
